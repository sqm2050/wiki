MSID IMSI = MCC + MNC + MSIN

G:
$LAI = MCC + MNC + LAC$
$CGI = MCC + MNC + LAC + CI$
$SAI = MCC + MNC + LAC + SAC$
$RAI = MCC + MNC + LAC + RAC$


用户从BSS接入则为CGI,用户从RNS接入为SAI

C:
BSID = Cell-id + SID + NID
				LAC

CID = BSID * 8 + SEC
CID = BSID * 16 + SEC

CID 小区识别码
BSID 基站识别码
SEC 扇区号

RNS - 即无线网络子系统
　　无线网络子系统（RNS - Radio Network Subsystem）包括在接入网中控制无线电资源的无线网络控制器（RNC）。RNC具有宏分集合并能力，可提供软切换能力。每个RNC可覆盖多个NodeB。NodeB实质上是一种与基站收发信台等同的逻辑实体，它受RNC控制，提供移动设备（UE）和无线网络子系统（RNS）之间的物理无线链路连接。同样，基站系统（BSS）由基站控制器构成，基站控制器控制一个或多个基站收发信台，与NodeB不同，每个BSS对应于一个蜂窝。IuCS与IuPS接口将接入网中的所有移动设备分别接入核心网中的电路交换域和分组交换域。
　　UMTS是通用移动通信系统,它是国际标准化组织3GPP制定的全球3G标准之一。它一般由用户终端，无线接入网，核心网构成。而UTRAN是无线接入部分一种重要的接入方式。UTRAN是一组连接到核心网的无线接入子系统(RNS)组成，它们之间的接口是Iu接口。
