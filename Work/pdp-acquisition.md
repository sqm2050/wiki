# PDP上下文的数据采集
Digital cellular telecommunicaitons system:数字蜂窝通信系统

Universal Mobile Telecommunication System(UMTS):通用移动系统


gn/gp接口:
<div class=box><img src=../png/gn-gp-interface.jpg align=middle></div>

$Gp$接口是与其他的PLMN进行交互的，其实报文规则一模一样。可用于小区的更新，新的SGSN向旧的SGSN发起请求，获取用户的IMSI号等信息，然后向原来附着的GGSN发起PDP更新请求。

二次激活：不会更新用户终端IP，也不会更新GGSN控制面TEID，但是会分配新的GGSN数据面TEID。因为GTP解析时是根据3个元素(user_ip, ggsn_ip_c,teid_u)这样用户二次激活的上行流量就会被追踪到(其实在添加用户之前就判断是否有ggsn_teid_c，就没有加上).
## 名词解释
CS：Circuit Switch电路交换

PS：Packet Switch分组交换

MCC：移动国家码，中国是460

MNC：移动网号，区分一个国家不同的运营商，在中国移动为00，联通位01.

LAC:Location Area Code(LAC),位置区号码。

RAC:Routeing Area Code,路由器码

SAC:Service Area Code,服务区码

CI:Cell Identification

SAI:Service Area Identifier

PLMN：Public Land Mobile Network，公共陆地移动网络。PLMN=MCC+MNC，例如中国移动46000，联通46001

LAI：MCC + MNC + LAC

RAI：LAI + RAC

CGI：LAI + CI

SAI: LAI + SAC(Service Area Code) 

$CGI = MCC + MNC + LAC + CI$
$SAI = MCC + MNC + LAC + SAC$
$RAI = MCC + MNC + LAC + RAC$

$User Location Information IE中的geograhic location type,0代表后面是CGI，1--SAI，2--RAI。$

$RAI中的LAC和User Location Information中的LAC有什么不同？$

$记录用户的当前位置信息，用户从BSS接入则为CGI，用户从RNS接入为SAI。$

## 模块需求思路
> 在G网的PS域进行用户信息的采集。

1. 建立维护针对于一个用户的信息节点

2. 提供多种查询接口

3. 统计用户的行为，提供传出功能

## 学习元素
> GTP中叫做`Information Elements`，Radius叫做`AVP`。
`IE`又分为TV，TLV类型，IE的`type field`第8位，如果是0就是TV(1-127是TV)。，1是TLV类型。

### 手机号码
不包含字冠如+86，0086，86

### 位置区编码
> 包含在信息元Routing Area Idntity(RAI)中。

LAC:locatoin area code位置区码,为寻呼而设置的一个区域，覆盖一片地理区域，初期一般按行政区域划分（一个县或一个区）。位置区码（LAC）则用于标识不同的位置区。位置区码（LAC）包含于LAI中，由两个字节组成，采用16进制编码。可用范围0x0000--0xFFFF.码组0x0000和0xFFFF不可以使用。一个位置区可以包含一个或多个小区。

RAI会在Creat PDP context Request,Update PDP Context Request出现.也会在新旧SGSN之间的消息中出现，可以不关心。

如果LAC覆盖范围过小，则移动台发生的位置更新过程将增多，从而增加了系统中的信令流量。

### CI号码
> 当有网络切换时，选择第一个CI。 $Cell ID$:对应IE-174:Cell Identification。

Cell Id用途：基于手机网络基站定位。基于Cell-ID（蜂窝编号）的定位技术，根据小区基站的覆盖范围（半径），来确认手机的大致位置，所以，定位该方式的定位精度与小区基站的分布密度密切相关。市区精度方位大致在150m左右，郊区精度范围大致在1000m～2000m左右。

### 终端类型-IMEI
International Mobile Equipment identity:国际移动设备识别码。一般在PDP上下文请求里面带有。

### 开始时间
通过定时的在linux端获取基准时间，计算到分秒。

### 结束时间

### 时长（秒）

### RATType
> The "RAT Type"information element is used to indicate which Radio Access Technology is currently serving the UE.
取值1代表3G：
<div class=box><img src=../png/rattype-1.png></div>

2代表2G：
<div class=box><img src=../png/rattype-2.png></div>

没有此AVP，也认为是2G网络

### 终端IP
End user address,端用户地址，type=128

### 访问IP
> 没有IP信息的填空，对于有多个IP的业务，输出合并的流量记录，访问IP只填第一个IP。

### 状态码

### User Agent
> 采集全部信息
http请求头域包含关于发起请求的用户代理的信息。这是为了统计，跟踪协议违反的情况，和为了识别用户代理从而为特定用户代理自动定制响应。用户代理应该包含User-Agent头域在请求中。

### APN
> Access Point Name-`131`,如3gwap，3gnet，uniwap，uninet，cmwap，cmnet

### IMSI
### SGSN IP
### GGSN IP
### Content-type
实体头域，指明发给接收者的实体主题的媒体类型，或在HEAD方法中指明若请求为GET时将发送的媒体类型。

当消息包含实体主体(entity)时，主体的数据类型由实体头域的Content-Type和Conten-Encoding头域确定。
### 源端口
### 目的端口
### 网址/特征信息
> 如果有url填充url信息，如果没有填充特有信息。

## 信息统计
总共$20项$

GTP隧道管理报文$9项$：
* IMSI,IMEI,MSISDN(若有),终端IP,APN,SGSN_IP,GGSN_IP.

* LAC(RAI),RAT type在其他信令中出现

GTP移动管理报文$1项$等：
* CI(Cell Identification)--Forward Relocation Request(前向重定位请求).
 
* LAC(RAI),RAT type也会出现在这种报文中

业务报文$6项$：
* User Agent,Content-type,URL,访问IP,源端口，目的端口

计算的$3项$：
* 开始时间，结束时间，时长。

未确定$1项$：
* 状态码.

## 概要设计
* 首先还是像学习`ismi`那样，通过用户`ip`,`ggsn_ip_u`,两个`teid_u`建立针对用户的唯一映射
* 提供针对于`ismi`,`imei`,`手机号`的查询
* 记录`用户ip`，`APN`，`GSN IP`等这些非唯一性的信息
* 记录`User Agent`,`Content-type`,`url`,`端口`等信息（可配）
* 统计`访问IP`，只记录第一个，然后记录不同的ip个数；

### 内存
> gtp是每次都alloc一个新的节点去分析报文，然后copy信息。

多个链表,只有一个`alloc`内存的地方，有两个删除的地方，多次`get`，只有一块内存伴随这用户信息整个生命期。

只有一个设置(`set`)引用基数的地方，其他其他地方`get`，`put`

### 引用计数
节点只有在加在临时表（sgsn_table）上的时候被set为一，然后添加定时器。

其他地方都是只是get put操作，添加到后面5张数据索引表上的时候不对引用计数进行任何操作，只是在添加钱删除引用计数，保证留有一个给后添加的定时器。

### get by
> 不会对链表产生影响，只会增加节点引用计数。

节点的get操作必须在锁内，因为定时器是在写锁里面进行unlink和put的，当匹配到相应的节点时候要先get，再释放锁，保证最后的引用基数(1)没有没有被定时器put（free）,因为读锁还没有释放。

使用完后进行put操作。

### get in - 节点unlink
没有get操作,删除timer,unlink节点，然后返回。因为已经删除了timer所以所有get_by进行put之后计数会变回1.

然后再去重新add这个节点，或者出错put.

不可以内嵌使用get_by获取节点，然后锁住返回的节点p，进行删除定时器，unlink操作。因为定时器删除是可以多次删除成功的（不可以作为正确的判定条件）。所以在get_by和加锁的时间窗口里面可能会有另外一个进程get_by到。然后删除定时器成功，继续再次unlink，出错！

> 也可以使用一个原子的标志，这样就可以先get by然后，判断标志，然后把标志置位，然后加锁进去unlink。

> 也可以get by得到节点p，然后去利用p中含有的删除索引表的信息去重新，get in - unlink。


### 删除或者unlink
1. 只能同时加锁、同时unlink
因为如果不是同时加锁进行unlink，unlink完一个链表。这个节点，还会存在，在这之后再次获得锁，进行解锁，造成多次unlink同一链表。

2. 只能有一个用于删除的索引
这是由于只能有一组(防止死锁)同时加锁顺序决定的。多层锁的原因，导致只能有一组加锁顺序，所以一定是先获得那个用于删除的索引表的阻塞锁，再依次获取其他的链表的阻塞锁，进行unlink操作。

3. timer用于删除的好处
timer的好处就是知道节点的所有信息，可以直接顺序（按照同一组加锁顺序）加锁，不用先利用$删除索引表$（有且只能有一个）去获得节点的其他信息。
```
static inline gn_user_t *
get_user_in_ggsn_gn(uint32_t ggsn_ip, uint32_t ggsn_teid)
{
	hash_list_t *l;
	gn_user_t *p;

	const int idx = hash_gsn_gn(ggsn_ip, ggsn_teid);
	WR_LOCK_GGSN_GN(idx);
	l = gn_ggsn_head[idx].next;
	while (l) {
		p = container_of(l, gn_user_t, list_gsn);
		if (p->ggsn.ip_c == ggsn_ip && p->ggsn.teid_c == ggsn_teid) {
			WR_LOCK_ALL_GN(p);
			if (cvmx_tim_delete_entry(&p->tim_del) ==
					CVMX_TIM_STATUS_SUCCESS) {
				hash_list_unlink(&p->list_gsn);
				UNLINK_ALL_GN(p);
			} else {
				p->timeout = 1;
				p->ggsn.ip_c = 0xff;	
				p->ggsn.teid_c = 0xff;	
				p = NULL;
			}
			WR_UNLOCK_GGSN_GN(idx);
			WR_UNLOCK_ALL_GN(p);
			return p;
		}
		l = l->next;
	}
	WR_UNLOCK_GGSN_GN(idx);
	return NULL;
}
```

不可能会出现根据第二个去作为删除的索引表（惟一一组加锁顺序决定的）。因为在硬并发情况下，只能是利用删除索引表查找到后直接在锁内进行删除，因为get by之后到加锁删除之间的时间窗口会有其他的get by获取到节点，继续进入阻塞锁进行删除。而且又由于加锁顺序是唯一确定的一组，所以只能是有唯一个删除索引表，而且它的阻塞锁再添加时候，一直在最前面。

当然也可以使用一个标志（link，unlink标志），这样就算多次进入unlink操作。先get by到，通过判断（在锁内判断，和置位，保证安全）而跳过后续的unlink操作。跳出之后put。

也可以先get by，之后把get in使用的信息复制到临时变量，然后使用复制出的信息进行get in(进行二次查找)，而不是利用get by出来的节点进行unlink.

$如下错误写法（get by，之后利用节点get in）：$
```
static inline gn_user_t *
get_user_in_ggsn_gn(uint32_t ggsn_ip, uint32_t ggsn_teid)
{
	gn_user_t *p;
	p = get_user_by_ggsn_gn(ggsn_ip, ggsn_teid);
	if (cvmx_unlikely(p == NULL))
		return NULL;

	WR_LOCK_GGSN_GN(p->gsn_idx);
	WR_LOCK_ALL_GN(p);
	if (cvmx_tim_delete_entry(&p->tim_del) == CVMX_TIM_STATUS_SUCCESS) {
		hash_list_unlink(&p->list_gsn);
		UNLINK_ALL_GN(p);
	} else {
		p->timeout = 1;
		p->ggsn.ip_c = 0xff;	
		p->ggsn.teid_c = 0xff;	
		p = NULL;
	}
	gn_user_put(p);
	WR_UNLOCK_GGSN_GN(p->gsn_idx);
	WR_UNLOCK_ALL_GN(p);
	return p;
}
```

### 添加
使用多层锁的原因分析，及分解:

> gtp中是会把所有要连接的表同时加上锁，因为在gn模块中有空信息不用加，为了省去空信息的hash计算，这里依次添加安全的索引表，然后同时去加用于删除的索引表和定时器（具有删除操作）。注意加锁的顺序。

可以把这个唯一一个作删除的表放到最后进行添加，其他的链表加锁、添加、解锁。然后其他的链表可能去进行get操作，这时候不会有影响，如果后面添加定时器失败要进行前面链表的unlink，然后put(不能free)即可。删除的时候一定加上多层锁进行删除。

添加定时器：定时器用于检查超时-解链删除，所以定时的添加必须在最后的那几个用于节点解链删除的危险链表的锁内执行，保证所有的链表是在安全的情况下添加定时器(获得节点，unlink操作的函数也必须保证先删除定时器再进行解链)。添加失败后要重新获得前面的没有unlink操作的链表的锁，进行解链，这里加锁的顺序要保证一致(这样的话，有删除操作的链表的锁在其他的部分要先加，加锁与$这里组成的顺序一致$)，防止死锁

加锁是根据结构中是否相应的数据，解锁亦然。但是如果添加安全链表时（对于只有link，get操作的索引链表的时候）有重复数据，会把旧的赋值0，如果第二个数据来的够快，第一个节点就会因为被置零而没有解锁，造成死锁。所以这里把值设置成了`0xff`无效的值，代替赋值0。

### BUG
1. get_in..() 调用了get_by..()函数,留下一个恶心的时间窗口。

2. 清除节点数据的时候，把数据设置成了`0x00`,影响解锁的行为。

3. 位域并行写入的bug，先前的结构如下：
```
	/* 4 words */
	uint16_t timeout: 13,
			 nsapi_flag, 3;
	uint8_t  cause;
	uint8_t  teardown;
	uint32_t gsn_idx;
	uint32_t ip_idx;
	uint32_t imsi_idx;
	uint32_t imei_idx;
	uint32_t msisdn_idx;
```
在分别加锁连接节点的时候，重复发送报文会并行写`timeout`，这里会引起后面64位数据错乱，导致`gsn_idx`错乱，造成死锁。

测试过不添加ggsn索引表的情况，没有问题出现，原因是`gsn_idx`成为了保留，用于被乱写。

后来测试过`timeout`为`uint16_t`的类型，一个晚上以后造成死锁。

所以改为一个完成64位的数据。
```
	uint64_t timeout;
	uint16_t nsapi_flag;
	uint8_t  cause;
	uint8_t  teardown;
	uint32_t gsn_idx;
	uint32_t ip_idx;
	uint32_t imsi_idx;
	uint32_t imei_idx;
	uint32_t msisdn_idx;
```
总结：不论什么bug，如果不是逻辑错误，一定是操作把别人内存改了，或者别人把自己内存改了。

## 关于二次激活
二次激活，在请求中不带`sgsn_teid_c`,响应中也没有`ggsn_teid_c`，应该都是和主激活一样的。不同的只是数据面的`teid`,还有一个`nsapi`。

如果`sgsn_teid_c`和`sgsn_ip_c`有一样是为空的话，可以通过二次激活请求头部带有的`ggsn_teid_c`和目的ip，到ggsn表中copy一个节点出来，然后建立一个以`sgsn_teid_c`和`sgsn_ip_c`为索引，`sgsn_teid_c`、`sgsn_ip_c`和`nsapi`为查找条件的临时表，等待二次激活的响应。

在响应消息头部取出`sgsn_teid_c`和目的ip查找上面建立的临时表，如果ggsn测有信息更新就更新临时节点的数据。然后添加节点。

最终主次和二次激活都是建立一个`user_ip`和`ggsn_ip_u`作为索引，`user_ip` `ggsn_ip_u` `sgsn_teid_u` `ggsn_teid_u`作为查找条件的链表。而且每次查找`teid_u`只有也只用其中一个去匹配。主-二不同的地方是链表中的`teid_u`和`nsapi`.但是`nsapi`不作为唯一匹配条件。

## mips load命令与位域操作详解

