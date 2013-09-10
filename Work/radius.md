## radius认证帐号的学习，并打帐号到业务报文
### RFC2865
1. radius报文被封装在udp数据域中，目的端口是1812。响应的时候，目的和源端口就相反了

2. access-challenge报文，如果NAS支持，则会重新发一个request报文，如果不支持challengge则认为是access-reject.重发时候使用一个新的ID,0-...

3. 多个同样类型的AVP的顺序需要保持，但是不同类型的AVP的不需要保持顺序，但是Radius服务器或者客户端不要求同样类型的属性是临近的。

4. AVP的length，包含type，length 和value域，所以真正的值域的长度=length -1.value的长度是0-n个octets。

5. 用户名：应该包含在access-request用于认证；也可能包含在access-accept，客户端将用返回的名字进行accounting-request。len >= 3, string至少有一个字符。$UTF-8 encoded 10646$

6. Framed-Protocol：tyep=7，指明用来传输数据的帧格式。 
 
7. Framed-IP-Address：type=8，用在access-accept消息中，也可出现爱acccess-request消息中，用于暗示server端，但是server可以不予理会。
> NAS-IP-Address说是指明辨别NAS的ip地址,但还是响应到ip.src,没有用途。

8. Session-Timeout：type=27，设置服务的最大秒数。在access-accept和access-challenge中出现。
> Idle-Timeout:type=28，与Session-Timeout类似。
<hr>
### RFC2866
1. 任何在access-request，access-accept上有效的AVP在accounting-request上都有效
> 除了user-password,CHAP-password,Replay-message,state.

2. 如果accounting-request报文中包含了一个framed-ip-address，这个属性一定包含的是用户的ip地址。如果access-accept给用户分配或者协商了一个 framed-ip-address,那么accounting-requst一定包含协商或者分配的那个地址。

3. Accounting-response不需要有任何的属性在里面。

4. acct-status-type：type=40,指明account-request标识用户服务的开始还是结束。
------------------------------------------------------------------------------
1. 一个认证服务器对应多个用户名，可能汇聚--多个认证服务其的流量，导致用户ip 相同。
> 经查看都是公网ip。
 
## 厦门测试
```
cpu0 
bind ruleset test interface 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53
add ruleset test aclmask 7 pri=0,sip=0.0.0.0/0,dip=0.0.0.0/0,sport=0-65535,dport=1646,protocol=udp,action=forward,fmt_add=disable,reverse=disable,aging=0,slotgroup=0,outgroup=0
add ruleset test aclmask 6 pri=0,sip=0.0.0.0/0,dip=0.0.0.0/0,sport=1646,dport=0-65535,protocol=udp,action=forward,fmt_add=disable,reverse=disable,aging=0,slotgroup=0,outgroup=0
add ruleset test aclmask 5 pri=0,sip=0.0.0.0/0,dip=0.0.0.0/0,sport=0-65535,dport=1645,protocol=udp,action=forward,fmt_add=disable,reverse=disable,aging=0,slotgroup=0,outgroup=0
add ruleset test aclmask 4 pri=0,sip=0.0.0.0/0,dip=0.0.0.0/0,sport=1645,dport=0-65535,protocol=udp,action=forward,fmt_add=disable,reverse=disable,aging=0,slotgroup=0,outgroup=0
add ruleset test aclmask 3 pri=0,sip=0.0.0.0/0,dip=0.0.0.0/0,sport=0-65535,dport=1813,protocol=udp,action=forward,fmt_add=disable,reverse=disable,aging=0,slotgroup=0,outgroup=0
add ruleset test aclmask 2 pri=0,sip=0.0.0.0/0,dip=0.0.0.0/0,sport=1813,dport=0-65535,protocol=udp,action=forward,fmt_add=disable,reverse=disable,aging=0,slotgroup=0,outgroup=0
add ruleset test aclmask 1 pri=0,sip=0.0.0.0/0,dip=0.0.0.0/0,sport=0-65535,dport=1812,protocol=udp,action=forward,fmt_add=disable,reverse=disable,aging=0,slotgroup=0,outgroup=0
add ruleset test aclmask 0 pri=0,sip=0.0.0.0/0,dip=0.0.0.0/0,sport=1812,dport=0-65535,protocol=udp,action=forward,fmt_add=disable,reverse=disable,aging=0,slotgroup=0,outgroup=0
sync ruleset test aclmask
add outgroup 1 2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19
delete outgroup 1 0
set crosspass 24 forward 0 1 disable disable
set crosspass 25 forward 0 1 disable disable
set crosspass 50 forward 0 1 disable disable
set crosspass 51 forward 0 1 disable disable
set fmt uds udslen 0
set sregister packetio enable
exit
```

### 66实验室
#### FPA用光
7口出，再入6口，跑了一晚上，FPA_4用光了，在0-150浮动。
```
interface 6
	Rx bps: 892009624  pps:734390
	Tx bps: 0  pps:0
interface 7
	Rx bps: 0  pps:0
	Tx bps: 892036240  pps:734122
```
> 之前复制5份，却能恒定在180W以上。
```
FPA_QUE4_AVAILABLE(0x00011800280000b8) = 0x00000000001c5711
  [63:29] RESERVED_29_63       =          0 (0x0)
  [28: 0] QUE_SIZ              =    1857297 (0x1c5711)
```
#### 关闭开关
```
	set sregister packtio disable
```
内存可以恢复
```
FPA_QUE4_AVAILABLE(0x00011800280000b8) = 0x00000000003d08ca
  [63:29] RESERVED_29_63       =          0 (0x0)
  [28: 0] QUE_SIZ              =    3999946 (0x3d08ca)
```

#### 再发包后停止发包
内存又能用完了
```
==> log1 <==
10:18:12
FPA_QUE0_AVAILABLE(0x0001180028000098) = 0x0000000000004f83
  [63:29] RESERVED_29_63       =          0 (0x0)
  [28: 0] QUE_SIZ              =      20355 (0x4f83)
FPA_QUE3_AVAILABLE(0x00011800280000b0) = 0x00000000000ac7dc
  [63:29] RESERVED_29_63       =          0 (0x0)
  [28: 0] QUE_SIZ              =     706524 (0xac7dc)
FPA_QUE4_AVAILABLE(0x00011800280000b8) = 0x0000000000000000
  [63:29] RESERVED_29_63       =          0 (0x0)
  [28: 0] QUE_SIZ              =          0 (0x0)
```

### 总结
风暴 < 复制 < 循环出进

#### 复制
```
vlan add member 0 0xfc1 0 2 0
vlan add member 0 0xfc1 0 3 0
vlan add member 0 0xfc1 0 6 0
vlan add member 0 0xfc1 0 7 0
```
#### 风暴
```
vlan add member 0 0xfc2 0 3 0
vlan add member 0 0xfc3 0 2 0
```
#### 循环进出
$7口出，6循环进$
```
add outgroup 2 0 7
del outgroup 2 0 0
create ruleset radius
add ruleset radius aclmask 0 action=forward,outgroup=2
```

## Radius软件流程

### 报文解析
AVP：属性值对。有定长与不定长两种。不定长的格式是TLV（TYPE，LENGTH，VALUE）。

用户名会按字节copy到临时buffer中，会有消耗。

### 模块入口
端口为`1813`,`1812`,`1645`,`1646`的UDP报文。

### ACCESS_REQUEST
根据`sip,dip,sp,dp,radius_id`五个元素建立 _临时表_ ，节点信息不一定包含完整新（用户名，用户IP）。节点超时时间`30s`。

### ACCESS_ACCEPT
删除定时器，在临时表中，查找，删除在临时表中的索引，删除定时器。

继续解析报文中的`AVPs`，判断信息是否完整。完整则插入到IP表(IP作为索引、查找条件)，NAME表(用户名作为索引，用户名和RADIUS_IP作为查找条件)。节点超时时间`120min`。
> TODO: 注意同一RADIUS服务器上用户名重复的问题。

### ACCESS_REJECT ACCESS_CHALLENGE
删除临时表中的节点和定时器。不做其他行为。

### ACCOUNT_REQUEST
计费请求里面可能会带有需要的全部信息。

计费请求报文里面会带有状态的AVP，如果是`START`,`UPDATE`,`ON`就会插入到IP表和NAME表中。如果是`STOP`,`OFF`就会删除IP表和NAME表响应的节点。

### 打印标签
会在MAC地址后面(即$12$字节后)，添加`9100`标签(2 octets)，`length`(1 octet），`user_name`( <= 61 octets)

`length`包含标签，自身，用户名的全部的长度。

### 消耗
> 业务数据比率较大
* 解析用户名，copy到buffer中
* 查找IP表
* 把用户名按字节插入到报文中
