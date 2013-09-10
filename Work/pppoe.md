# PPPoE---RFC 2516

## 前言，格式
### 学习远端地址
为了在以太网上提供点对点连接，每个PPP会话，必须学习远端的以太网地址，同时建立一个唯一的会话标识符。PPPoE包的发现协议提供了这个功能。
### 服务器-多选一
当一个主机希望初始化一个PPPoE会话，它必须执行发现阶段去标识对方的以太MAC地址并且建立一个PPPoE会话标识符(SESSION_ID)。当PPP定义了一个段对端关系时，发现阶段也同时建立了一个客户端-服务器关系。
> 基于这个网络拓扑，该主机可能有不止一个可以通信的访问集中器( _服务器_ )。发现阶段允许主机发现所有的服务器，然后选择使用其中一个。当发现阶段成功结束时，该主机与被选择的访问集中器都拥有将用于建立它们之间在以太网上的点对点连接的信息。

### 报文格式：
| 目的地址（6 octets） | 源地址（6 octets） | 以太包类型（2octets） | 有效载荷 | 校验码 |

* 目的地址在第一个发现帧中是以太网广播地址（0xff ff ff ff ff ff）
* 以太包类型为`0x8863`发现阶段或者`0x8864`PPP会话阶段。

### 有效载荷
PPP头部(6 bytes)：
* VER域占用4位，对于 *rfc 2516* ，必须设置位0x1.
* TYPE域占用4位，对于 *rfc 2516* ，必须设置位0x1.
* CODE域占用8位
* SESSION_ID域占用16位。一个网络字节序的无符号数值，它与以太网源目地址一起定义了一个PPP会话。0xffff是保留值，现在不能使用。
* LENGTH域占用16位。网络序的值，指出PPPoE有效载荷的长度，她不包含以太包及PPPoE包头。

## 发现阶段
在发现阶段有4个步骤。完成时，两端都知道PPPoE的会话ID及对方的以太网址，而且它们一起唯一标识一个会话。

* 主机广播一个初始（Initiation）包
* 一个或者多个服务器发送提议（Offer）包
* 主机发送一个单播会话请求（Session Request）包
* 被选择的访问集中器发送一个确认（Confirmation）包

所有的发现阶段的以太帧，都要将 *ETHER_TYPE* 域的值设置位`0x8863`。

### 有效载荷
有效载荷可以包含一个或者多个标签（TAG），一个标签是一个TLV（type-length-value)的结构。`TYPE`16位,`LENGTH`16位。

如果 *发现包* 接收到一个未知类型的标签，该标签必须被忽略。

### PADI包
PADI(PPPoE Active Discovery Initiation)包，目的地址被设置为广播地址。`CODE = 0x09`，`SESSION_ID = 0x0000`。

PADI包必须包含正确的类型为服务名称（Service-name）的标签，用于指出主机正在请求的服务。
> 但是在"PPPoE-dail-pkt.cap"中的PADI中没有 _服务名称_ 这个标签。

### PADO包
当服务器接收到它可以提供服务的PADI包，它通过发送一个PADO(PPPoE Active Discovery Offer)包来响应。目的地址是发送PADI的主机的单播地址。`CODE = 0x07`,`SESSION_ID = 0x0000`.

PADO包 *必须* 包含一个AC名称(AC-Name)标签，其中有访问集中器的名称；同时， *必须* 包含一个服务名称(Service-Name)标签来标识PADI中的服务名称，同时可以包含任意数量的其他服务名称(Service-Name)标签来指出该访问集中器提供的其他服务。

### PADR包
因为PADI是广播包，所以主机可能接收到多个PADO。主机需要审核这些PADO包，并且从中选择一个。这个选择可以基于所提供的AC名称(AC-Name)或者服务。然后主机发送PADR(PPPoE Active Discovery Request)包给被选中的访问集中器。目的地址被设置为这个发送PADO的访问集中器的单播以太网地址。`CODE = 0x19`,`SESSION_ID = 0x0000`.

PADR包必须包含一个正确的服务名称(Service-Name)标签，该标签指出主机所请求的服务，同时可以包含任意数量的其他标签。
> 但是在"PPPoE-dail-pkt.cap"中同样没有 _服务名称_ 这个标签。

### PADS包
当访问集中器接收到PADR包时，它开始准备开始一个PPP会话。它为PPPoE会话创建一个唯一的会话ID(SESSION_ID)，并用PADS(PPPoE Active Discovery Session-confirmation)包回复给主机。`CODE = 0x65`,`SESSION_ID`必须设置为刚为本次PPPoE会话创建的唯一值。

如果访问集中器不喜欢PADR中服务器名称则它必须在回复的PADS中包含服务名称错误(Service-Name-Error)标签，这时SESSION_ID必须被设置位`0x0000`.

### PADT包- 发现终止
这个包可以在会话建立之后的任意时刻发送，用于指出这个PPPoE会话已经被终止。主机或着服务器都可以发送这个包。目标地址被设置为单播以太网地址，`CODE = 0xa7`,`SESSION_ID`是将被终止的会话的ID。 _这个包不需要任何标签。_ 

在发送或者接收到一个PADT后，即使正常的$PPP终止包$也必须不再被发送。PPP端应该使用PPP协议本身来关闭一个PPPoE会话，但PADT可以用于PPP不能使用的情况。
> LCP链路终止

## 会话阶段
`ETHER_TYPE = 0x8864`,`CODE = 0x00`，对于这个PPPoE会话，SESSION_ID必须不能改变，并且必须是发现阶段指定的值。
> 没有找到SESSION_ID起始限制。

PPPoE有效载荷包含一个PPP帧,$该帧以PPP帧协议ID开头。$GRE中A10隧道，里面的PPP帧有的是`ff 03`开始的，有的不是，直接后跟`协议号` 。在PPPoE中后面直接跟`协议号`,还有就是`协议域`在$rfc2516$中是不推荐压缩的。

最大接收单元（MRU，Maximum-Receive-Unit）选项必须不超过1492。因为以太网有1500字节（8位）的最大有效载荷限制，而PPPoE头有6字节（8位）并且PPP协议ID包含2字节（8位），所以，PPP的MTU必须不超过1492。

## LCP
 *推荐* 访问集中器不定期的发送回音请求（Echo-Request）包给主机，以此决定这个会话的状态。否则，如果主机不发送终止请求（Terminate-Request）包即终止一个会话，访问集中器将不能判断这个会话
