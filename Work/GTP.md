G-PDU:GTP分组数据单元。由T-PDU加上GTP头构成。G-PDU在一条路径上传输。
T-PDU:原始分组，如来自MS或外部分组数据网络节点的IP报文。T-PDU是GTP隧道的静荷。

1.测试
请求报文:
	FPA 7 3都是少了一个，停止发包后自动释放，测试一个晚上后没有异常。
响应报文:
	单独发，FPA个数一直不减少，不变。(说明分配的空间,在没有找请求的报文后正常的释放了)
	在请求30之内发,能够扑捉，删除sgsn上，添加ggsn上。
	3:少2个
	7:少1个
删除报文:
	单独发，FPA个数一直不减少，不变。(说明分配的空间,在没有找请求的报文后正常的释放了)
	能够正常扑捉，并在小于30秒内利用定时器删除。

一个完成的GTP报文：
	能够承受并解析、添加。正常释放空间。

gtc-c.pcap：
	会把FPA 7耗尽：
	sgsn_nodes = 3629, ggsn_nodes = 96371, ip_nodes = 96371
	停止发包后会正常释放，3 7号FPA。

-----------IMSI---
Data Encoding - based on 3GPP TS 23.003 V8.5.0 (2009-06) §2.2 p13-14
8	7	6	5	4	3	2	1
Octet 0	Mobile country code digit 2	Mobile country code digit 1
Octet 1	Mobile network code digit 1	Mobile country code digit 3
Octet 2..	Rest of IMSI address
-----------Modify imsi order of GTP-----
00:16:31:ff:31:98 > 00:11:14:21:22:43, ethertype VMAN (0x9100), length 62:
0011 1421 2243 0016 31ff 3198 9100 0b46
0004 1000 0010 7f08 0045 0000 30fb 6a00
0040 11bc 1e02 0304 05c0 a8fc 8300 6400
c800 1cc7 e258 5858 5858 5858 5858

==============性能测试==========================
1.不学习帐号，发送业务数据
	测试hash，和判断空链表头
2.学习不相应的帐号，发送业务数据
	测试hash，和判断空链表头
3.学习相应的帐号，发送业务数据
	测试hash，查找的几次判断和打报文头
4.学习响应的帐号，打报文头部分，发送业务数据
	测试hash，查找的几次判断
------------------------------------------------------------------------------
一次激活，二次激活，PDU通告，sgsn之间的流量
总结:
	并发同步控制,链表安全:多进程环境下，多链表，多锁
	节点内存安全:引用基数,get-add(+1),put-add(-1), set(1)
	节点唯一：哈希索引，插入查找参数保证节点唯一
	异步删除,防止嵌套锁导致死锁：定时器unlink，put操作
	
使用多层锁的原因：多个链表，如果第一个表添加完了，解锁，去添加第二张表时第一张表的删除操作，也过来了。就会把节点给free掉，造成内存错误。在只根据一个表进行删除操作的情况下，可以把这个唯一一个作删除的表放到最后进行添加。删除的时候一定加上多层锁进行删除。

嵌套锁- 死锁:
			b2	b3	<---外层锁,用作插入时同步
			a1	a2	<---外层锁,用作插入时同步
			a2	a1	<---内存锁,用作删除时同步
			
			a1	a2
			b2	b4
			b4	b2
* 总共是有3个hash表：sgsn,ggsn,ip。
 
* create PDP context request消息						
	- 首先学习sgsn发起的create PDP context request消息，学习到sgsn_ip_c,sgsn_teid_c,imsi。
	- hash(sgsn_ip_c,sgsn_teid_c)作为索引,同时也利用这两个参数，插入,查找加spinlock，加上30s的定时器，解锁。					
	    
		> 后来发现30时间太短，现场测试时候改成180s。
		
* response消息
	- 然后利用request的两个参数，跟踪ggsn的response消息，学习到用户的ip, ggsn_teid_c,ggs_ip_c。
	- 利用sgsn_teid_c,sgsn_ip_c，去sgsn上查找解下节点。
	- ggsn利用ggsn_teid_c,ggsn_ip_c索引，插入，查找ip表只利用ip作为索引,插入,查找。上双锁插入ggsn,ip节点,这里旧节点的删除统一交给定时器处理
	 
		> 因为，如果在插入的时候发现ggsn相同，ip 不同去unlink ip的链表，就要锁住旧的ip链表，就会形成嵌套双锁（同类型），造成死锁危机。

* patch1
	> 数据是多个ggsn流量的汇聚走过设备，加上ggsn_ip_u,作为索引，插入，查找。
	
	- 在dpp结构体重加入外层ip作为ggsn_ip_u，用户ip与ggsn_ip_u始终在对侧，这个隐含条件一开始没有注意到。
	- 因为ggsn_ip_u可能因为sgsn发起的更新而更新（ggsn发起的更新不会），所以又加上对更新消息的学习和追踪。
	
		> ggsn发起的更新不会更新，隧道teid，ip等。
		
	- update request：ggsn_teid_c,ggsn_ip_c,sgsn_teid_new,sgsn_ip_new 建立新表update表。
	- update response:ggsn_teid_new,ggsn_ip_new（如果有，没有就用旧的赋值），ggsn_ip_u.
	- search(sgsn_teid_new,sgsn_ip_new) on update表,找到旧的ggsn_teid_c,ggsn_ip_c.
	- search(ggsn_teid_c, ggsn_ip_c) on ggsn表，把imsi，user_ip拷贝到新节点，删除旧节点，如果ggsn_teid_new,ggsn_ip_new,ggsn_ip_u不为空就用新的，否则使用旧值插入。

		> 这里注意取链表中的值的时候要么，在写（或自旋锁锁）内摘下，或者读锁内复制给一个新的变量，然后出去在读锁-自旋锁内删除此节点，不要在读锁内clear节点，和在锁外面使用在锁内读到的指针---在索引到的值。
	
patch2：
	发现还是有错打imsi号的现象，加入sgsn_teid_u,ggsn_teid_u，作为插入、查找
	条件但没有加入索引，因为这两个在业务数据上下行的时候只会有一个在gtp头中
	所以插入、查找的时候利用他们作为判断，但是没有hash。
	之后就没有打错的现象了，说明在一个ggsn_ip_u上user_ip复用的现象严重。ggsn
	依靠不同的teid_u、 user_ip识别怎么进行网关。

patch总结：
	加入ggsn_ip_u,因为多个ggsn流量汇聚，也因此追踪更新消息
	加入ggsn_teid_u,sgsn_teid_u作为节点插入、查找条件但是没有索引

有时候一些模糊的概率数据也能作为判断问题的依据，注意一些暗喻。

bug: 引用基数操作和在结构体中的位置，报文判断，定时器删除依据.

## 并行
