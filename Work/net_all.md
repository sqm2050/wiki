7 .报文识别功能要求(基本要求)
	97.1 POS报文识别	POS使用的链路层协议主要有PPP和HDLC。 POS is defined by RFC 2615 as PPP over SONET/SDH.
	97.2 链路层报文识别
	97.3 VLAN报文识别
	97.4 MPLS报文识别	MPLS和以太网WAN赶走了帧中继和ATM
	97.5 IP层报文识别
	107.6 IPv4报文识别
	107.7 IPv6报文识别
	107.8 TCP/UDP报文识别
	107.9 ICMP报文识别
	107.10IP层隧道报文识别
	107.11L2TP/PPTP隧道报文识别
	107.12IPSec(AH、ESP封装)隧道报文识别
	107.13未能识别的报文


常见隧道协议
基于数据包:
	IPsec
	GRE (一般路由封装) supports multiple protocols and multiplexing
	en:IP in IP Tunneling [2] Lower overhead than GRE and used when only 1 IP stream is to be tunneled
	L2TP（资料连结层隧道协议）[3]
	MPLS (Multi-Protocol Label Switching)
	GTP (GPRS Tunnelling Protocol)
	PPTP (Point-to-Point Tunneling Protocol) [4]
	PPPoE (point-to-point protocol over Ethernet)
	PPPoA (point-to-point protocol over ATM)
	en:IEEE 802.1Q (Ethernet VLANs)
	en:DLSw (SNA over 互联网协议)
	en:XOT (X.25 datagrams over TCP)
	IPv6 穿隧：en:6to4、en:6in4、en:Teredo tunneling
	en:Anything In Anything (AYIYA; e.g. IPv6 over UDP over IPv4, IPv4 over IPv6, IPv6 over TCP IPv4, etc.)
基于串流:
	传输层安全
	SSH
	SOCKS
	HTTP CONNECT 命令
	各式的电路层级的代理服务器协议，如Microsoft Proxy Server的Winsock Redirection Protocol或WinGate Winsock Redirection Service.

IP协议号：
	0 HOPOPT IPv6 逐跳选项 
1 ICMP Internet 控制消息 
2 IGMP Internet 组管理 
3 GGP 网关对网关 
4 IP IP 中的 IP（封装） 
5 ST 流 
6 TCP 传输控制 
7 CBT CBT 
8 EGP 外部网关协议 
9 IGP 任何专用内部网关 
（Cisco 将其用于 IGRP）
10 BBN-RCC-MON BBN RCC 监视 
11 NVP-II 网络语音协议 
12 PUP PUP 
13 ARGUS ARGUS 
14 EMCON EMCON 
15 XNET 跨网调试器 
16 CHAOS Chaos 
17 UDP 用户数据报 
18 MUX 多路复用 
19 DCN-MEAS DCN 测量子系统 
20 HMP 主机监视 
21 PRM 数据包无线测量 
22 XNS-IDP XEROX NS IDP 
23 TRUNK-1 第 1 主干 
24 TRUNK-2 第 2 主干 
25 LEAF-1 第 1 叶 
26 LEAF-2 第 2 叶 
27 RDP 可靠数据协议 
28 IRTP Internet 可靠事务 
29 ISO-TP4 ISO 传输协议第 4 类 
30 NETBLT 批量数据传输协议 
31 MFE-NSP MFE 网络服务协议 
32 MERIT-INP MERIT 节点间协议 
33 SEP 顺序交换协议 
34 3PC 第三方连接协议 
35 IDPR 域间策略路由协议
36 XTP XTP 
37 DDP 数据报传送协议 
38 IDPR-CMTP IDPR 控制消息传输协议
39 TP++ TP++ 传输协议 
40 IL IL 传输协议 
41 IPv6 Ipv6 
42 SDRP 源要求路由协议 
43 IPv6-Route IPv6 的路由标头 
44 IPv6-Frag IPv6 的片断标头 
45 IDRP 域间路由协议 
46 RSVP 保留协议 
47 GRE 通用路由封装 
48 MHRP 移动主机路由协议
49 BNA BNA 
50 ESP IPv6 的封装安全负载 
51 AH IPv6 的身份验证标头 
52 I-NLSP 集成网络层安全性 TUBA 
53 SWIPE 采用加密的 IP 
54 NARP NBMA 地址解析协议 
55 MOBILE IP 移动性 
56 TLSP 传输层安全协议 
使用 Kryptonet 密钥管理
57 SKIP SKIP 
58 IPv6-ICMP 用于 IPv6 的 ICMP 
59 IPv6-NoNxt 用于 IPv6 的无下一个标头 
60 IPv6-Opts IPv6 的目标选项 
61 任意主机内部协议 
62 CFTP CFTP 
63 任意本地网络 
64 SAT-EXPAK SATNET 与后台 EXPAK 
65 KRYPTOLAN Kryptolan 
66 RVD MIT 远程虚拟磁盘协议 
67 IPPC Internet Pluribus 数据包核心 
68 任意分布式文件系统 
69 SAT-MON SATNET 监视 
70 VISA VISA 协议 
71 IPCV Internet 数据包核心工具 
72 CPNX 计算机协议网络管理 
73 CPHB 计算机协议检测信号 
74 WSN 王安电脑网络 
75 PVP 数据包视频协议 
76 BR-SAT-MON 后台 SATNET 监视 
77 SUN-ND SUN ND PROTOCOL-Temporary 
78 WB-MON WIDEBAND 监视 
79 WB-EXPAK WIDEBAND EXPAK 
80 ISO-IP ISO Internet 协议 
81 VMTP VMTP 
82 SECURE-VMTP SECURE-VMTP 
83 VINES VINES 
84 TTP TTP 
85 NSFNET-IGP NSFNET-IGP 
86 DGP 异类网关协议 
87 TCF TCF 
88 EIGRP EIGRP 
89 OSPFIGP OSPFIGP 
90 Sprite-RPC Sprite RPC 协议 
91 LARP 轨迹地址解析协议 
92 MTP 多播传输协议 
93 AX.25 AX.25 帧 
94 IPIP IP 中的 IP 封装协议 
95 MICP 移动互联控制协议 
96 SCC-SP 信号通讯安全协议 
97 ETHERIP IP 中的以太网封装 
98 ENCAP 封装标头 
99 任意专用加密方案 
100 GMTP GMTP 
101 IFMP Ipsilon 流量管理协议 
102 PNNI IP 上的 PNNI 
103 PIM 独立于协议的多播 
104 ARIS ARIS 
105 SCPS SCPS 
106 QNX QNX 
107 A/N 活动网络 
108 IPComp IP 负载压缩协议 
109 SNP Sitara 网络协议 
110 Compaq-Peer Compaq 对等协议 
111 IPX-in-IP IP 中的 IPX 
112 VRRP 虚拟路由器冗余协议 
113 PGM PGM 可靠传输协议 
114 任意 0 跳协议 
115 L2TP 第二层隧道协议 
116 DDX D-II 数据交换 (DDX) 
117 IATP 交互式代理传输协议 
118 STP 计划传输协议 
119 SRP SpectraLink 无线协议 
120 UTI UTI 
121 SMP 简单邮件协议 
122 SM SM 
123 PTP 性能透明协议 
124 ISIS over IPv4 
125 FIRE 
126 CRTP Combat 无线传输协议 
127 CRUDP Combat 无线用户数据报 
128 SSCOPMCE 
129 IPLT 
130 SPS 安全数据包防护 
131 PIPE IP 中的专用 IP 封装 
132 SCTP 流控制传输协议 
133 FC 光纤通道 
134-254 未分配 
255 保留
