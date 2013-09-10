/**
 * 	1. 隧道认证 Challenge AVP - Challenge response AVP(v2)  nonce(v3)
 * 		v2:第二版叫做：Tunnel Authentication
 * 		v3:第三版叫做：Control message Authentication 不是认证消息的一
 * 		步部分，而是认证整个认证消息
 * 	2. avp隐藏,隐藏机制。会不会隐藏到ID？会。
 * 	3. 基于IPSec的报文加密
 * 	4. 端口问题src-any dst-1701; src-any?dst-any?
 * 	5. 第三版把两个id扩展到32位，这样子第二版session id标识在一个tunnel 中
 * 	   的一个会话，但是第三版中每个session id就唯一标识了这一端上的会话。
 * 	   但是也能与隧道建立关联，就是ICRQ 等控制消息依旧是控制头，里面使用的
 * 	   依旧是对端分配的tunnel id。v3-P62说HELLO的session id是零，这个？
 * 	6. GRE有7e，有碎片。L2TP没有7e，没有碎片。
 * 
 * 	认证，加密-隐藏，流动窗口，分片- 重组（ppp），帧封装格式
 */
	L2TP支持包括IP、ATM、帧中继、X.25 在内的多种网络。在IP网络中，L2TP协议
	使用注册端口 UDP 1701。[1]因此，在某种意义上，尽管L2TP协议的确是一个数
	据链路层协议，但在IP网络中，它又的确是一个会话层协议。

	L2TPv3可在隧道中转发PPP、HDLC、帧中继、和以太网等第二层帧，而L2TPv2 只
	能通过隧道转发PPP帧。
rfc3931:
	l2tp:layer two tunneling protocol.

	L2TP Control Connection Endpoint(LCCE)
	An L2TP node that exists at either end of an L2TP control connection.
	May also be referred to as an LAC or LNS,depending on whether tunnele-
	d frames are processed at the data link(LAC) or network layer(LNS).

	Data messages are used to encapsulate the L2 traffic being carried ov-
	er the L2TP session.Unlike control messages,data messages are not ret-
	ransmitted when packet loss occurs.

	L2TPv3 structure
	Tunneled Frame		L2TP Control Message
	L2TP Data Header	L2TP Control Header
	L2TP Data Channel	L2TP Control Channel
	   (unreliable)			(reliable)
	Packet-Switch Network(IP,FR,MPLS,etc.)					分组交换网络支持

	Data memssages are passed over an unreliable data channel,encapsulated
	by an L2TP header,and sent over a Packet-Switched Network(PSN 分组交换
	网络)such as IP,UDP,Frame Relay,ATM,MPLS,etc.Control messages are sent
	over a reliable L2TP control channel,which operates over the same PSN.

	The necessary setup for tunneling a session with L2TP consists of  two
	steps:(1) Establishing the control connection,and (2)establishing a s-
	ession as triggered by an incoming call or outgoing call.An L2TP sess-	trigger:触发器
	ion MUST be established before L2TP can begin to forward session fram-
	es.Multiple sessions may be bound to a single control connection , and
	multiple control connections may exist between the same two LCCEs.

Over UDP:
L2TPv3 Control Message Header:

	0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	T L x x S x x x x x x x|  Ver  |	Length			|
			Control Connection ID
		Ns		       |	Nr
	——————————————————————————————————————————————————————————————————
	The T bit MUST be set to 1, indicating that this is a control message.	T位必须置1，表示是一个控制消息。

	The L and S bits MUST be set to 1,indicating that the Length field and	控制消息必须有长度和序号，所以两位必须置位
	sequence numbers are present.

	The x bits are reserved for future extensions.All reserved bits MUST 
	be set to 0 on outgoing messages and ignored on incoming messages.

	The Ver field indicates the version of the L2TP control message header
	described in this document.On sending, this field MUST be set to 3 for
	all messages(unless operating in an environment that includes L2TPv2[R
	FC2661] and/or L2F[RFC2341] as well,see Section 4.1 for details).

	The length field indicates the total length of the message in  octets,
	always calculated from the start of the control message header  itself
	(beginning with the T bit).

	Non-zero Control Connection IDs are selected and exchanged as Assigned
	Control Connection ID AVPs durin the creation of a control connection.

	The Session Header MUST provide a method of distinguishing traffic am-
	ong multiple L2TP data sessions and a method of distinguishing data m-
	essages from control messages.
	会话头必须提供一个能从多个L2TP数据会话中区分通信的方法，和一个区分是数
	据消息还是控制消息的方法。
	Each type of encapsulating PSN MUST define its own session header cle-
	arly identifying the format of the header and parameters necessary  to
	setup the session.Section 4.1 defines two session headers,one for tra-
	nsport over UDP and one for transport over IP.

	The L2-Specific Sublayer is an intermediary layer between the L2TP se-	intermediary:adj.中间人的,调解的.n:中间人
	ssion header and the start of the tunneled frame.It  contains  control
	fields that are used to facilitate the tunneling of each frame.The de-	facilitate:vt.促进，帮助
	fault L2-Specific Sublayer for L2TPv3 is defined in Section 4.6.

Control Conection Teardown:
	Control connection teardown may be initiated by either LCCE and is ac-
	complished by sending a single StopCCN control message.As part of  the
	reliable control message delivery mechanism,the recipient of a StopCCN	mechanism:n.机械，机构，结构，机理，技巧
	MUST send an ACK message to acknowledge recepit of the message and ma-
	intain enough control connection state to properly accept StopCCN ret-	properly:ad.适当地
	ransmissions over at least a full retransmission cycle(in case the ACK	retransmission:重发，重传，转发
	message is lost).The recommended time for a full retransmission  cycle
	is at least 31 seconds

	通过StopCCN 可以关闭控制连接，和所有与控制连接有关的会话。所以没有必要
	在关闭控制连接的时候，独立地关闭每个会话。				detect:vt.发觉，察觉，探测

Data Messge:
        | L2TP Session Header  |
        | L2-Specific Sublayer |
        | Tunnel Payload       |

L2TPv3 Session Header Over UDP:
	0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	T x x x x x x x x x x x|  Ver  |	Reserved		|
			 	Session ID
		Cookie	(optional maxium 64bits	)
	——————————————————————————————————————————————————————————————————

Over IP:
	L2TPv3 over IP (both versions) utilizes the IANA-assigned IP  protocol
	ID 115.
	L2TPv3 Session Header Over IP:
	0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
				Session ID
		Cookie (optional maxium	64bits)
	——————————————————————————————————————————————————————————————————

	L2TP Control and Data Traffic over IP
	L2TPv3 Control Message Header Over IP:
	0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
				(32 bits of zeros)
	T L x x S x x x x x x x|  Ver  |	Length			|	Note that Length field is still calculate from the begi-
			Control Connection ID					nnig of the control message header,beginning with the T
		Ns		       |	Nr				bit.
	——————————————————————————————————————————————————————————————————
	

Session Teardown:
	Session teardown may be initiated by either the LAC or LNS and is acc-
	omplished by sending a CDN control message.After the last  session  is 
	cleared,the control connection MAY be torn down as well (and typically
	is).

Protocol Operation:
	L2TP may operate over a variety of PSNs. There are two modes described 	L2TPv2 over other PSNs:RFC3070,RFC3355.
	for operation over IP(4.1.1) and L2TP over UDP(4.1.2).L2TPv3 implemen-
	tations MUST support L2TP over IP and SHOULD support L2TP over UDP for
	better NAT and firewall traversal,and for easier migration from L2TPv2	migration:n.移民，移动，【计】迁移。

Session ID
	A 32-bit field containing a non-zero identifier for a session.L2TP se-
	ssions are name by identifiers that have local significance only. That
	is ,the same logical will be given different Session IDs by  each  end 
	of the control connectoin is used for session establishment,Session I-
	Ds are selected and exchanged as Local Session ID AVPs during the cre-
	ation of a session.The session id alone provides the necesary  context 
	for all further processing,including the presence,size,and value of t-
	he Cookie,the type of L2-Specific Sublayer,and the type of payload be-
	ing tunneled.

L2TPv3 Control Message Header Over IP
	Note that the length field is still calculated from the  beginning  of 	L2TPv2 RFC2661;L2F RFC2341
	the control message header,beginning with the T bit.

	When operating directly over IP,L2TP packets lose the ability to  take
	advantage of the UDP checksum as a simple packet integrity.		intergrity:n.完整性

UDP Port Selection
	control connection:UDP:1701(destination address)
	The initiator of an L2TP control connection pick an  available source 
	UDP port(which may or may not be 1701) and sends to the desired dest-
	ination addres at port 1701.The recipent picks a free port on its own
	system(which may or may not be 1701)and sends its replay to the init-
	iator's UDP port and address,setting its own source port to the  free
	port it found.
	控制连接的发起者发起的把报文目的端口是1701，源端口任意选一个可获得端口
	（可能是也可能不是1701）。接收端在自己的系统上选择一个空闲的端口（可以
	是或者不是1701）发送响应到发起者的端口和地址，选择空闲端口作为自己的源
	端口。

	Either L2TP over UDP or L2TP over IP may be secured with IPsec RFC2401
	defines the recommended method for securing L2TPv2.L2TPv3 possesses i-
	dentical characteristics to IPsec as L2TPv2 when running over UDP  and
	implementations MUST follow the same recommendation.When operating ov-
	er IP directly,[RFC3193] still applies,though references to UDP source
	and destination ports.

	Note that IPv6 does not support "in-flight" fragmentation of data pac-
	kets.

4.1.4 IP Fragmentation Issues
	In summary,attempting to control the source MTU by communicating  with
	the originating host,forcing that an MTU be sufficently large  on  the	sufficently:ad.足够，充分。
	path between LCCE peers to tunnel a frame from any other interface wi-
	thout fragmentation,fragmenting IP packets before  encapsulation  with
	L2TP/IP,or fragmentation the resultant L2TP/IP packet between the tun-
	nel endpoints,are all valid methods for managing MTU mismatches.

4.2 Reliable Delivery of Control Messages
	The sequence number in the header of a received message is  considered 
	less than or equal to the last received number if its  value  lies  in 
	the range of the last received number and the preceding 32767  values,
	inclusive.For example,if the last received sequence number was 15,then
	messages with sequence number 0 through 15, as well  as 32784  through 
	65535,would be considered less than or equal.Such a message  woule  be
	considered a duplicate of a message already received and ignored  from
	processing.

认证和隐藏：
Control Message Autentication Nonce AVP - 73
	contain a cryptographically random valueThis value is used for Control
	Message Authenticaton.

Random Vector
	This value is used for AVP Hiding.

H bit:
	The H bit MUST only be set if (1) a shared secret exists between the L
	CCEs and (2) Control Message Authentication is enable. If the H bit is
	set in any AVP(s) in a given control message,at least one Random Vect-
	or AVP must be also be present in the message and MUST precede the fi-
	rst AVP having an H bit of 1.

Message Digest AVP - 59
	0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
        | Digest type | Message Digest	.... |
	
	Type:
	0 HMAC-MD5	16 bytes
	1 HMAC-SHA-1	20 bytes
	Digest Type 0 MUST be supported,while Digest Type 1 SHOULD be supported

	If Control Message Authentication is enabled,at least one Message Dig-
	est AVP MUST be present in all messages and MUST be placed immediately
	after the Message Type AVP.
	
	shared_key = MHAC_MD5(shared_secret, 2)
	Message Digest = HMAC_Hash(shared_key, local_nonce + 
					remote_nonce + control_message)

	when calulating the Message Digest,the Message Digest AVP MUST be pre-
	sent within the control message with the Digest type set to its proper
	value,but the Message Digest itself set to zeros.

	对于SCCRQ只有一个nonce在消息中，没必要用它去计算Digest的值：
	Message Digest = HMAC_Hash (shared_key, control_message)

1.General Control Message AVPs:
	Message Type(All): 0
		肯定是第一个消息的AVP，紧跟在头后。M 1,H 一定是0，长度是8.
	Message Digest(ALL): 59
		 Attribute Value:Digest Type| Message Digest...	H 0, M 1
	Control Message Authentication Nonce(SCCRQ, SCCRP): 73
		H 0,M 1
	Random Vector (ALL): 36

2.Control Connection Management AVPs: 
	Control Connection Tie Breaker(SCCRQ): 5
	Host Name (SCCRQ,SCCRP): 7
	Rount ID (SCCRQ,SCCRP): 60
	Assigned Control Connection ID (SCCRQ, SCCRP, StopCCN)
		会被隐藏，H bit MAY be 0 or 1.


3. Sesssion Manangement AVPs:
	Local Session ID(ICRQ, ICRP, ICCN, OCRQ, OCRP, OCCN, CDN, WEN, SLI): 63
	contains the identifier being assigned  to this  session by the sender.
	Additionally,for all session-oriented control messages sent after this
	AVP is received, the remote LCCE MUST echo this value in the Remote S-
	ession ID AVP.
	会被隐藏，H bit MAY be 0 or 1.

Remote Session ID: 64
	Contains the identifier that was assigned to this session by the peer.
	会被隐藏，H bit MAY be 0 or 1.


================================= l2tp v2 ====================================
L2TP Header Format:
	l2tp packets for the control channel and data channedl share a  common	控制隧道和数据隧道使用同一个头格式
	header format.In each case where a field is optional, its  space  does	如果一个域是可选的
	not exist in the message if the field is marked not present. Note that	当它被标记是不存在的，她的空间也不存在
	while optional on data messages,the length,ns,and nr fields marked  as 	控制消息中len,ns,nr域是肯定存在的。
	optional below,are required to be present on all control messages.

	0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
	T L x x S x O P x x x x|  Ver  |	Length(opt)		|
		Tunnel ID	       |	Session ID		|
		Ns (opt)	       |	Nr (opt)		|
		Offset Size(opt)       |	Offset pad... (opt)	|

	T: indicates the type of message.It is set to 0 for a data message and
	   1 for a control message.
	L: if the Length bit is 1,the length field is present.This bit MUST be
	   set to 1 for control messages.
	S: If the Sequence bit is set to 1 the Ns and Nr fields are present.T-
	   he S bit MUST be set to 1 for control messages.
	O: if the offset bit is 1,the offset size field is  present. the O bit
   	   MUST be set to 0 (zero) for control messages.
	P: if the Priority bit is 1,this data message should receive preferen-
	   tial treatment in its local queuing and transmission. This  feature
	   is only for use with data messages.The P bit MUST be set to  0  for 
	   all control messages.
	Ver: MUST be 2.								L2F RFC2341
	Length: The length field indicates the total length of the message  in
		octets.								长度单位八位元
	Tunnel ID: indicates the identifier for the control connection.L2TP t-
		   unnels are named by identifiers that have local significan-	像GTP的teid一样，本端给对端分配相应的tunnel id。
		   ce only.That is,the same logical will  be  given  different 	Session ID,在ICRQ报文中，于此类似。
		   Session IDs by each end of the tunnel.Tunnel ID in each me-
		   ssage is that of the intended recipient,not the sender.Tun-
		   nel IDs are selected and exchanged as Assigned Tunnel ID A-
		   VPs during the creation of a tunnel.

AVP Format:
	0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1		与l2tpv3
	M H| rsvd  | Length	       |	Vendor ID		|
	Atrribute Type		       |	Atrribute Value...	[[|]]
		until Length is reached....

Mandatory(M) bit:如果置位的话，在Session出现的没有识别的消息，这个会话
	就要终止，如果是在Tunnel中出现的话，真个隧道就要终止。如果M bit 没有置
	位，不能识别的报文就要被忽略。

	Hidden(H)bit:隐藏信息。

	Length:AVP的整个长度 = 6 + Atrribute Value, 6 - 1023.

	Vendor ID:

H bit:
	If the H bit is set in any AVP(s) in a given control message, a Random
	Vector AVP must also be present in the message and MUST precede the f-	precede:vt.vi.在...之前，在前面
	irst AVP having an H bit of 1.
	如果Hbit在一个AVP中置位了，那么一个Randon Vector AVP也必须出现在消息中
	而且在第一个H置位的AVP前面。

	隐藏要经过几步，首先拿出原始AVP的长度和值域，然后生成如下的字模式：
	Length of Original Value	| Original Atrribute Value
						Padding...
	新的AVP：
		6 + 	4 + 				2 + 		12 = 24
		head	Attribute Value length		size of length  padding
	计算MD5 hash值：
	1. AVP的属性号(2 octet)		AV
	2. 共享密钥			S					v2是secret，v3是shared_key=HMAC_MD5(shared_secret, 1)
	3. 任意长度的一个随机数		RV
	随机数在Random Vector AVP中传递，必须在第一个hidden AVP 的前面，如果想
	使用多个随机数，那么在第一次使用那个那随机数的hidden AVP前面要放置一个
	randon vector AVP.

	然后MD5值和子格式的前16octet的段进行异或，而且哈希值放到属性值域。如果
	小于16octet在异或前会进行转码, 但是只有子格式中的octets被修改，AVP的长
	度不做调整。

	如果子格式长于16octets，则生成第二个MD5值，使用共享密钥，和第一个异或值
	把值域拆开成16-octet长度的块p1,p2,...
		b1 = MD5(AV + S + RV)	c(1) = p1 xor b1
		b2 = MD5(S + c(1))	c(2) = p2 xor b2
		.
		bi = MD5(S + c(i-1))	c(i) = pi xor bi

	控制隧道l2tp头是包含序列号，但是数据隧道没有包含，但是LAC 可以请求包含
	序号，通过Sequencing Required AVP。一旦这个AVP在会话设置时候出现了，序
	好在所有的时间出现。如果这个AVP没出现，那么顺序控制在LNS之下，LNS 控制	RFC2661-44/80
	开关序号在任何时候通过发送一个包含或者不包含序号的数据消息。

	滑动窗口会考虑接收的最后一个和前面32767之间的报文，比如最后一个编号 15
	那么32784-65535（模）-0-15这些将会考虑。如果有重传的，也会进行重新确认。
	所有的控制消息都会继续一个滑动槽，但是ZLB不会，所以Ns在ZLB被发送之后不
	会增长。发送了之后就会向下滑动一个，比如:
	-> ICRQ Ns:2 Nr:1	这时候滑动一个Ns立即就变成3了。
	-> ZLB  Ns:3 Nr:1	这里Ns虽然是3但是，不做滑动。
	<- ICRP Ns:1 Nr:3	接收者的期望Nr也不会因为ZLB向下滑
	-> ICCN Ns:3 Nr:2	所以Ns还是3。

	每个隧道保持一个控制消息的队列用来重传给对端。在最前端的消息被给予一个
	Ns值，而且保持直到接收到一个消息的Nr值表明这个消息已经被接收。经过一段
	时间（默认是1s），如果没有接到确认就会重传。使用同样的Ns值，但是Nr值会
	根据下一个期望接收的消息更新。

	指数延迟间隔：如果第一个重传发生在1s之后，下个重传在2秒，然后是4s。 最
	大重传时间设置为8秒。如果默认重传5次之后，这个隧道和所有的会话会被清除。

	HELLO消息对隧道是全局的，所以HELLO消息中的会话ID一定是0.

Incoming calls:
	An Incoming-Call-Request :ICRQ is generated by the LAC when an incoming
	call is detected.

	LNC 可以在会话没建立之前，停止呼叫-通过发送CDN，这时候没有建立起会话呢
	所以使用CDN Assigned Session ID AVP中id号。

	实践表明接收者使用与目的端口不一样的任意源端口会导致l2tp穿过NAT 设备时
	侯变得困难。
	1701端口也被L2F使用，但是Version field会不同，L2F值是1，L2TP值是2。

AVP: Message Type(all message)
	value length :2 octets。The length of this AVP is 8.

	Message Type AVP一定要是消息中的第一个AVP。

	Message Type AVP中的M位，具有特殊的意义，不代表是否忽略这个不识别的AVP
	而是忽略整个消息，而且清楚tunnel。

	H位一定不能置位。就是不能隐藏。

Message Type:0, M must 1,H must 0

Assigned Tunnel ID: 9, M must 1, H may 0-1;

Assigned Session ID: 14, M must 1, H may 0-1;

1:
	type	tunnel	session	ns	nr						src,dst,tunnel_id,session_id.
	SCCRQ	0(120)	0	0	0
	SCCRP	120(1)	0	0	1
	SCCN	1	0	1	1
2:
	ICRQ	1	0(1)	2	1
	ICRP	120	1(1)	1	3
	ICCN	1	1	3	2
3:
	PPP->LCP->CCP->IPCP协商对方的地址。

隧道端点安全：Tunnel Endpoint Security, 通过认证来确保。

报文等级的安全：packet level security , 安全的l2tp需要底层的传输提供有效的加密
完整，认证服务。

点到点的安全：

隧道认证：l2tp使用一个简单的，可选的，类似与CHAP的认证机制。如果过一个LAC 或者
LNS希望验证对端的端点，那么会在SCCRQ 或者SCCRP 中包含一个challeng AVP,相应的在
SCCRP或者SCCCN中就要包含一个challeng response AVP了。
为了参与隧道认证，一个共享密钥必须存在LAC和LNS之间，用于AVP隐藏。
