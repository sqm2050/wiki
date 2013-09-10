## Handoff 切换
从一个基站向另一个基站转移用户站通信之动作。硬切换的特点是，通信信道短暂中断。软切换的特点是，一个以上的基站同时与同一个用户站保持通信。

Handoff 又称为 Handover (HO) 是所有蜂窝通信系统共有的特征。根据切换类型可以分为, 硬切换，软切换，更软切换等。

硬切换用于GSM网络，软切换是CDMA 网络的特征之一。

PCF --- PDSN
PCF(packet control function)一般与BSC在一起。PCF的功能主要是在BSC和PDSN提供PPP帧的传输，它是RLP(无线链路协议)连接的终止点。
	
PDSN是CDMA分组网中的核心设备，是一种无线接入网(RAN)和分组交换公共数据网(Packet Switch Public Data NetWork, PSPDN)之间的网关。简言之，是CDMA2000网络中移动终端访问互联网的接入设备。PDSN是PPP连接的终止点，提供IP数据包的路由。

业务信道的分配，A10连接的建立，链路层(PPP)的建立，移动IP注册。

执行完以上操作之后，用户数据业务就可以封装在GRE帧中在A10连接中传送了。

在A10连接的生存期超时前，PCF通过向所选的PDSN发送注册请求消息来定期的进行重注册。

### PCF切换：
	移动终端应保持相同的PPP连接和同样的IP地址。
	
### PDSN切换：
	当用户发生PDSN间切换后，由于需要重新建立PPP连接，重新获取IP地址。

### CDMA2000数据：
```
		IP
		PPP	
	GRE	GRE
	IP	IP
	Link	Link
	Phys	Phys
```
GRE:
控制报文:UDP 699,PPP IPCP/LCP

数据报文：CDMA2000 A10标准

Registration Request and Registration Reply 不仅仅用于注册，也被用来在PCF和PDSN之间交换信息

A10的释放是由PCF控制的。PDSN初始化A10连接的释放，PDSN请求PCF释放连接。

A11注册请求是由PCF向PDSN发起的，用于初始化建立，更新和释放一个A10连接。除此之外，与一个A10连接有关的账户信息可能被包含在任何一个和这个A10连接有关的A11注册请求.

## 添加BSID（基站编码）
### cvse
BSID存在与 *Critical Vendor/Organization Specific Extension(CVSE)* 这个扩展中.

> 关键供应商/组织指定的扩展。

自身类型：26H.

bsid在app-t=01 sub-t=01的RADIUS中，而且本版本仅支持，Radius认证。

#### Vendor-Specific-Attribute
CVSE中包含多个 *Vendor-Specific-Attribute* - 供应商指定属性。

类型：1AH.
Type Length Vendor-ID	Vendor-Type	Vendor-Length	Vendor-Value

* Type: 1AH	

* Length: Length of all VSA

* Vendor ID: 00 00 15 9FH

* Vendor-Length: Length of all Vendor

* Vendor-Value: ...

#### 其他类型的属性

* Type:

* Length: Length of all Attr

* Value: ...

## 转义长度 - pcf-pdsn.pcap
```
0000   00 1b 21 a7 65 f5 00 18 82 1d 0c 53 08 00 45 00  ..!.e......S..E.
0010   00 57 00 01 00 00 fd 2f ed 2d ac 1c 78 05 ac 1c  .W...../.-..x...
0020   00 0b 30 00 88 81 00 00 00 02 00 00 00 00 7e ff  ..0...........~.
0030   7d 23 c0 21 7d 21 7d 21 7d 20 7d 39 7d 22 7d 26  }#.!}!}!} }9}"}&
0040   7d 20 7d 20 7d 20 7d 20 7d 23 7d 25 c2 23 7d 25  } } } } }#}%.#}%
0050   7d 25 7d 26 b9 7d 21 af 7d 28 7d 27 7d 22 7d 28  }%}&.}!.}(}'}"}(
0060   7d 22 59 a7 7e                                   }"Y.~

0000   7e ff 7d 23 c0 21 7d 21 7d 21 7d 20 7d 39 7d 22  ~.}#.!}!}!} }9}"
0010   7d 26 7d 20 7d 20 7d 20 7d 20 7d 23 7d 25 c2 23  }&} } } } }#}%.#
0020   7d 25 7d 25 7d 26 b9 7d 21 af 7d 28 7d 27 7d 22  }%}%}&.}!.}(}'}"
0030   7d 28 7d 22 59 a7 7e                             }(}"Y.~

0000   ff 03 c0 21 01 01 00 19 02 06 00 00 00 00 03 05	[00 19]是长度ppp-lcp的长度域值0x0019 = 25 是转义之前的长度。
0010   c2 23 05 05 06 b9 01 af 08 07 02 08 02
```
