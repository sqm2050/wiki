1. 双栈策略
	双栈策略是指在网元中同时具有IPv4和IPv6两个协议栈，它既可以接收、处理、
收发IPv4的分组，也可以接收、处理、收发IPv6的分组。对于主机（终端）来讲，“双栈”
是指其可以根据需要来对业务产生的数据进行IPv4封装或者IPv6封装。对于路由器来讲，
“双栈”是指在一个路由器设备中维护IPv6和IPv4两套路由协议 栈，使得路由器既能与IPv
4主机也能与IPv6主机通信，分别支持独立的IPv6和IPv4路由协议，IPv4 和IPv6路由信息
按照各自的路由协议进行计算，维护不同的路由表。IPv6数据报按照IPv6路由协议得到的
路由表转发，IPv4数据报按照IPv4路由协议得到的路由表转发。
2. 隧道策略
	隧道的配置方法分为手工配置隧道和自动配置隧道，而自动配置隧道又可以分为
兼容地址自动隧道、 6to4隧道、6over4、ISATAP、MPLS隧道、GRE隧道等，这些隧道的实
现原理和技术细节都不相同，相应的，其应用场景也就不同。

6to4
isatap:	teredo(miredo)
ipv4 over ipv6
------------------------------------------------------------------------------
teredo:ip->udp->ipv6---teredo_server
sixxs.org:ipv6--->ipv4

teredo-sixxs:ipv6)udp)ipv4)--->teredo_server--->ipv6--->sixxs.org--->ipv4(new)
------------------------------------------------------------------------------
6 to 4自动隧道：(IPv6 in IPv4)
	每一个站点都需要确定一个路由来运行双层协议张、即IPv4和IPv6兼容和6to4隧
道，以确保这个路由有全球范围的路由地址（非专用IPv4地址空间）。
	用于通过IPv4网络将IPv6域连接起来，它是点到多点连接类型。在RFC3056 中定
义的2002::/16的地址范围专用于6to4隧道的地址范围。边缘路由器自动使用嵌入在 IPv6
的IPv4地址建立隧道。如果边缘路由器的IPv4地址为192.168.99.1，则其IPv6地址为2002
:c0a8:6301::/48因为，192.168.99.1的十六进制表示为c0a8:6301。

通过IPv4网络把IPv6网络域连接起来:

      host---ipv6网络---6to4路由器A---IPV4网络---6to4路由器A---IPV6网络---host
			192.168.99.1		192.168.30.1
			2002:c0a8:6301::/48	2002:c0a8:1e01::/48

路由器A将IPv6的分组封装到IPv4分组中，并将提取的IPv4 地址用作目标地址，随后分组
穿过IPv4的网络。路由器B收到IPv4的分组后，将其拆封以获得其中的IPv6 分组，并将其
转发到最终的目的地。

6to4采用特殊的IPv6地址使在IPv4海洋中的IPv6孤岛能互相连接。此时IPv6的出口路由器
与其他的IPv6域建立隧道连接。IPv4隧道的末端可从IPv6域的地址前缀中自动提取，因为
站点IPv4地址包含在IPv6地址前缀中。通过这个机制，站点能够配置IPv6而不需要想注册
机构申请IPv6地址空间。

------------------------------------------------------------------------------
NAT只能解析TCP UDP数据流，IPv4压缩的IPv6 数据包发送时协议域的是41，而不是6-TCP
或17-UDP。所以IPv4压缩的IPv6通信传输不能通过一般的 NAT，为了使IPv6数据传输能够
通过单个或多层NAT，IPv6数据包必须压缩成IPv4 UDP格式的数据，包含IPv4和UDP标头各
一个。UDP数据普遍能够NAT解析而且能够通过多层的NAT。
------------------------------------------------------------------------------
ISATAP隧道和6to4隧道
	和6to4都是目前比较流行的自动建立隧道的过渡技术，都可以连接被IPv4隔绝的
IPv6孤岛，都是通过将IPv4地址嵌入到IPv6地址当中，并将IPv6封包封装在IPv4中传送，
在主机相互通信中抽出IPv4地址建立tunnel。但具体实现的流程，IPv6地址和应用范围不
尽相同。 

	ISATAP(draft-ietf-ngtrans-isatap-23.txt) 的全名是 Intra-Site Automatic
Tunnel Addressing Protocol，它将IPv4地址夹入IPv6地址中，当两台 ISATAP 主机通讯
时，可自动抽取出 IPv4 地址建立 Tunnel 即可通讯，且并不需透过其它特殊网络设备，
只要彼此间IPv4网络通畅即可。

	双栈主机支持isatap后会自动在该隧道接口上生成本地链路的前缀(fe80::开头)
和64位的接口标识符::0:5EFE:X.X.X.X(这里的X.X.X.X是双栈主机的IPv4单播地址),这样
就可以和同一子网内其他isatap客户机进行ipv6通讯了；如果需要和其他网络的isatap客
户机或者IPv6网络通信，必须通过ISATAP路由器拿到全球单播地址前缀(2001:, 2002:, 
3ffe:开头)，通过路由器与其他IPv6主机和网络通信。

	ISATAP过渡技术不要求隧道端节点必须具有全球惟一的IPv4地址，只要双栈主机
具有IPv4单播地址即可，不管该地址公有的还是私有的都可以。

	6to4(RFC3056) 机制被定义在站点之间进行IPv6通讯，每个站点必须至少有一台
“6to4”路由器作为出入口，使用特需的地址格式，地址前缀为(2002:开头),并将路由器的
IPv4 地址夹入IPv6 地址中，因此位于不同6to4 site 内的主机彼此通讯时即可自动抽出
IPv4地址在路由器之间建立Tunnel。

	透过6to4 router，不同6to4 site内的主机可互相通讯，当需与一般IPv6主机通
讯时，则必须过6to4 relay router。6to4 relay router必须同时具备6to4及IPv6接口，
同时提供这些接口的封包转送。

	6to4需要一个全球合法的IPv4地址，所以对解决IPv4地址短缺没有太大帮助。但
它不需要申请IPv6地址，通过它可使站点迅速升级到IPv6。

## 6 in 4
这个 IPv4 隧道使用 IP 协议号码的 41 。这个协议号码是特别设计用来 IPv6 于 IPv4 中.

## 6 to 4
6to4 也使用协议号 41 ，但相对于在端点上做静态组态，其可从 IPv6 封包中的 IPv6 位址推出端点的 IPv4 位址资讯。

### 6 to 4 转换的例子
http://6to4.version6.net/?lang=en_GB

### wikipedia
6to4 may be used by an individual host, or by a local IPv6 network.When used by a host,it must have a global IPv4 address connected,and the host is repsonsible for encapsulation of outgoing IPv6 packets and decapsulation of incoming 6to4 packets.If the host is configured to forward packets for other clients,often a local network,it is then a router.

Most IPv6 networks use autoconfiguration,which requires the last 64 bits for the host.The first 64 bits are the IPv6 prefix.The first 16 bits of the prefix are always 2002,the next 32 bits are the IPv4 address,and the last 16 bits of the prefix are available for addressing multiple IPv6 subnets behind the same 6to4 router.

192.0.2.4 ==> c0 00 02 04, 6to4 prefix 2002:c000:0204::/48,which leaves room for a 16-bit subnet field and 64 bit host addresses within the subnets.

#### 6to4 performs three functions
* Assigns a block of IPv6 address space to any host or network that has a global IPv4 address

* Encapsulate IPv6 packets inside IPv4 packets for transmission over an IPv4 network using $6in4$ .

* Route traffic between 6to4 and 'native' IPv6 networks

#### Encapsulation and transmission
6to4 embeds an IPv6 packet in th payload portion of an IPv4 packet with protocol type 41.

The IPv4 destination address for the prepended packet header is derived from the IPv6 destination address of the inner packet(which is in the format of a 6to4 address),by extracting the 32 bits immediately following the IPv6 destination address's 2002::/16 prefix.

The IPv4 source address in the prepended packet header is the IPv4 address of $the host or router$ which is sending the packet over IPv4.

The resulting IPv4 packet is then routed to its IPv4 destination addres just like any other IPv4 packet.

#### Routing between 6to4 and native IPv6
To allow hosts and networks using 6to4 addresses to exchange traffic with hosts using "native" IPv6 addresses, "relay routers" have been established. A relay router connects to an IPv4 network and an IPv6 network. 6to4 packets arriving on an IPv4 interface will have their IPv6 payloads routed to the IPv6 network, while packets arriving on the IPv6 interface with a destination address prefix of 2002::/16 will be encapsulated and forwarded over the IPv4 network.

中继路由器可以让使用6to4地址的主机或者网络与原生IPv6网络的主机交换分组。一个中继路由器连接一个IPv4和一个IPv6网络。当一个IPv4接口上的6to4报文到达时，把这个报文的负载路由到响应的IPv6网络；当IPv6接口上的一个2002::/16开头的报文到达时将被封装和通过IPv4网络转发。

There is a difference between a "relay router" and a "border router" (as known as a "6to4" border router).A 6to4 border router is an IPv6 router supporting a 6to4 pseudo-interface.It is normally the border router between an IPv6 site and a wide-area IPv4 network,where the IPv6 site uses 2002::/16 co-related to the IPv4 address used later on.On the other hand,a "relay router" is a 6to4 router configured to support transit routing between 6to4 addresses and pure native IPv6 addresses.

边缘路由器只是IPv6和IPv4网络之间接口，但是中继路由器还支持将2002::/16(6to4 address)开头的和纯原生的IPv6网络连接。

## 6 over 4
6over4 defines a trivial method for generating a link-local IPv6 address from an IPv4 address, and a mechanism to perform Neighbor Discovery on top of IPv4.

### Link-local address generation
Any host wishing to participate in 6over4 over a given IPv4 network can set up a virtual IPv6 network interface.

The link-local address is determined as follows :
* it starts with fe80::.

* the lower-order 32 bits to the binary value must be that of the IPv4 address of the host.

192.0.2.142(c000028e) would user fe80:0000:0000:0000:0000:0000:c000:028e as its link-local IPv6 address.

> 嵌有ipv4地址的ipv6地址与6over4相似，但是前面96都为零，或者80位为零，16位是ffff,然后是32位的ipv4地址。

### Limit of 6over4
6over4 relies on IPv4 multicast availability which is not very widely supported by IPv4 networking infrastructure. 6over4 is of limited practical use, and is not supported by the most common operating systems. To connect IPv6 hosts on different physical links, IPv4 multicast routing must be enabled on the routers connecting the links.

ISATAP(teredo) is a more complex alternative to 6over4 which does not rely on IPv4 multicast.

## 4in6

