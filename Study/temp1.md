----------------------------------------------------
----------------------------------------------------
当使用次要的PDP上下文激活过程时，在消息中不应包含‘选择模式’，'IMSI','MSISDN','端用户地址‘。。。
----------------------------------------------------
3/25 14:38
	在9053上更新双teid_u的版本，重启时间14：20
	14:20
15	14:35	40W用户.
40	15:00	128W	增速	3w/min
90	15:50	278W		3w/min
60	16:20	362W
150	16:50	454W
180	17:20	530W


15:50 9052	1440
	15:50
30	16:20	106W
60	16:51	212W
240	19:51	720W
	21:06	912W
	22:55-23:23	增速趋于7000以下

20:30 9053重新换se，360=3h
23:23 9052换se	360	3000以下

3/26	9053	13:30 720	0cf34599d52d10ae3540398d5589f913
----------------------------------------------------
3/24 21:50;
	9052 double_teid
	9053 ip_idx
----------------------------------------------------
ssh root@182.245.126.78 -p 9053
-----------------------------------------------------
 192.168.1.53 sw
					4056(1,4)	4057(1,0)
vlan add member 1 4056 25 0
vlan add member 1 4057 25 0
vlan remove member 1 4056 10 
vlan remove member 1 4057 22
vlan add member 1 4056 10 1
vlan add member 1 4057 10 1
pvid set 1 25 4032 1 1 
vlan add 1 4032
vlan add member 1 4032 10 1 

   192.168.1.52 sw

vlan add member 1 4057 10 1 
vlan remove member 1 4057 22
pvid set 1 25 4032 1 1 
vlan add 1 4032
vlan add member 1 4032 10 1 
vlan add member 1 4056 25 0
vlan add member 1 4057 25 0
------------------------------------------------------


19:28 3/24	FPA下降有些快。
sgsn_nodes = 24186, update_nodes = 7545
ggsn_nodes = 5736995,ip_nodes = 5737408


交谈中请勿轻信汇款、中奖信息、陌生电话，勿使用外挂软件。
陈小阳(251779677)  16:00:52
我终于上来了

182.245.126.78：15001
182.245.126.78：15002
吴海波(1191107987)  16:01:45
你把你的规则贴进来
16:02:48  吴海波邀请了慕年鹏加入讨论组
陈小阳(251779677)  16:04:00
=============================================================1.1.0.51
vlan add 1 4032
vlan add member 1 4032 25 1
vlan add member 1 4032 10 1
vlan add member 1 4032 22 1

vlan add 1 4033
vlan add member 1 4033 25 1
vlan add member 1 4033 10 1
vlan add member 1 4033 22 1


pcltest -d 1 -i 4 -v 4032 -M 2123 -p 1 -r 1 
pcltest -d 1 -i 4 -v 4032 -N 2123 -p 2 -r 2
pcltest -d 1 -i 0 -v 4033 -M 2123 -p 3 -r 3
pcltest -d 1 -i 0 -v 4033 -N 2123 -p 4 -r 4



vlan add 1 4034
vlan add member 1 4034 10 1 
vlan add member 1 4034 22 1  


=======================================================1.1.0.50
# vlan remove member 0 4032 27 
# # vlan remove member 0 4033 27 
# # vlan remove member 0 4033 1 
# # vlan remove member 0 4034 27 
# # vlan remove member 0 4034 2 
# # vlan add member 0 4034 0 0
#
#
# pvid set 1 25 4034 1 1
# vlan add 1 4034
# vlan add member 1 4034 10 1 
# vlan add member 1 4034 22 1  
# # vlan add member 1 4034 16 1
#
# vlan add 1 4032
# vlan add member 1 4032 25 1
# vlan add member 1 4032 10 1
# vlan add member 1 4032 22 1
#
# vlan add 1 4033
# vlan add member 1 4033 25 1
# vlan add member 1 4033 10 1
# vlan add member 1 4033 22 1
#
# pcltest -d 1 -i 4 -v 4032 -M 2123 -p 1 -r 1 
# pcltest -d 1 -i 4 -v 4032 -N 2123 -p 2 -r 2
# pcltest -d 1 -i 0 -v 4033 -M 2123 -p 3 -r 3
# pcltest -d 1 -i 0 -v 4033 -N 2123 -p 4 -r 4
#
# 加#的是配置后，注释掉的，
# 罗尔夫(80244085)  16:05:59
# ip port ssh不上
# 陈小阳(251779677)  16:06:07
# 现在再试试
# 182.245.126.78端口为：15001   
# 182.245.126.78端口为：15002
# 罗尔夫(80244085)  16:08:15
# 谁你连上吗？
# 吴海波(1191107987)  16:08:45
# 我都ping不通
# 设置防火墙了么
# 陈小阳(251779677)  16:09:45
# 恩，需要通过绿盟的防火墙
# 还在调，再等一会儿
# 陈小阳(251779677)  16:14:22
# 谁要远程？只能先远程协助了
# 罗尔夫(80244085)  16:18:20
# 不能ssh了
# 陈小阳(251779677)  16:18:39
# 好像绿盟的设备有问题
# 吴海波(1191107987)  16:18:56
# 果然不可靠啊
# 哎，他要是OEM咱们的估计就没问题了
# 陈小阳(251779677)  16:19:23
# 美亚的研发工程师好像也在远程调试，所以也不能重启防火墙
# 罗尔夫(80244085)  16:19:58
# 他们怎么远程登陆得？
# 陈小阳(251779677)  16:20:13
# 同样的规则，他们就可以，我们就不可以
# 罗尔夫(80244085)  16:20:23
# 应该还是映射端口出来得吧
# 靠，没天理
# 陈小阳(251779677)  16:20:32
# 恩
# 我远程协助吧
# 登陆到我的电脑，然后再跳转
# 吴海波(1191107987)  16:23:50
# 学毅，你登陆上去了么
# 罗尔夫(80244085)  16:24:08
# 还没有
# 吴海波(1191107987)  16:24:30
# 哦，你先看吧，我是想上去看一下交换芯片的配置
# 因为PCL 广播的这个东西在实验室没有做过测试
# 陈小阳(251779677)  16:24:54
# 那我远程学毅了
# 罗尔夫(80244085)  16:25:03
# 好
# 陈小阳(251779677)  16:26:04
# 学毅没收到我的远程协助吗
# 罗尔夫(80244085)  16:26:27
# 没有啊
# 陈小阳(251779677)  16:26:21
#
#
# 吴海波(1191107987)  16:27:00
# 估计是网速问题
# 陈小阳(251779677)  16:27:35
# 我管了重新申请远程，有吗
# 关
# 罗尔夫(80244085)  16:28:49
# 清孟先上去看一下，有多少用户同时在线？fpa空间够不够
# 我还在找问题
# 孙清孟(361841482)  16:29:15
# 嗯
# 那海波先下了吧
# 吴海波(1191107987)  16:30:19
# 能查看多少用户在线？这个功能灰常不错哦
# 很有用哦
# 吴海波(1191107987)  16:33:50
# 小阳，能不能写个脚本，每分钟读一次这个数据，保存下来，这个数据会有一定的参考意义
# 罗尔夫(80244085)  16:33:55
# MAC QQ上没有找到远程协助
# 等等
# 吴海波(1191107987)  16:34:40
# 难道MAC上没有这个功能？可能是苹果系统的原因哦，用虚拟机呢、
# 孙清孟(361841482)  16:34:52
# 我断开。
# 陈小阳(251779677)  16:34:51
# 我重新更改一下管理口ip，看看能不能完成端口映射
# 恩，
# 孙清孟(361841482)  16:36:32
# 临时节点有：3734
# 学习到的用户：147 8232
# FAP5剩下：651 5074
# 陈小阳(251779677)  16:36:45
# 182.245.126.78端口为：9052   
# 182.245.126.78端口为：9053
#
# 罗尔夫(80244085)  16:36:51
# tim得fpa呢
# 陈小阳(251779677)  16:36:52
# 现在好像可以了吧
# 罗尔夫(80244085)  16:37:04
# 试一下
# 孙清孟(361841482)  16:37:09
# 忘记读了
# 罗尔夫(80244085)  16:37:40
# 可以了，密码？
# 陈小阳(251779677)  16:37:41
# 管理口的ip是临时加的，注意不要重启
# juson
# 陈小阳(251779677)  16:40:52
# 状态对吗
# 罗尔夫(80244085)  16:49:37
# 里面得两条规则是要配置得吗？
# 我看到CPU输出报文没有负载均衡
# 流量不是很大，可以考虑用一个板卡试一下，简化拓扑
# 陈小阳(251779677)  16:52:46
# 关于我们设备的打标签比例显示，美亚的周成祖好像比较关心这个，刘学毅有空的时候，能不能跟他沟通一下详细的细节问题
# 陈小阳(251779677)  16:55:49
# 没有负载均衡？我刚刚统计了一遍速率，38个业务接口基本上都在90Mbps~100Mbps之间
# 罗尔夫(80244085)  17:00:47
# 嗯，我跟周沟通一下，目前因为在实验室找之前发现得问题，还没来得及理会这个事
# 罗尔夫(80244085)  17:01:58
# 你告诉他现在我们上面可以读即时得在线用户数
# 陈小阳(251779677)  17:02:30
# 罗尔夫(80244085)  17:05:34
# 一个万兆大概150万，差不多一起600万左右用户同时在线
# 陈小阳(251779677)  17:06:36
# 不是这么算吧，信令报文是广播到所有56CPU的
# 吴海波(1191107987)  17:07:04
# 学毅，这个是怎么看的，你跟我说下，我写个脚本，然后把这些信息都循环读一下，做一个24小时的数据图出来，这个非常有用
# 罗尔夫(80244085)  17:08:36
# 清孟说吧
# 吴海波(1191107987)  17:09:36
# 这样吧，清梦，等下我找你，你给我说一下吧，QQ里边不好说
# 孙清孟(361841482)  17:09:43
#
# MCDebug(config-zxmdu-cn56a)# gtp_imsi show all
#
# sgsn_nodes = 3761, ggsn_nodes = 1368248, ip_nodes = 1368286
# 嗯，好的，这个得手动看。不过跟csr寄存器的差不多，可以用脚本记录那个值。
# 罗尔夫(80244085)  17:10:49
# 现在一个板卡得两个CPU是136W，另一个是163和156W
# 吴海波(1191107987)  17:11:28
# 信息量还是比较大的
# 罗尔夫(80244085)  17:12:33
# 如果能保证原始一条链路得上下行在一个CPU上处理就是最好得了
# 吴海波(1191107987)  17:13:25
# 呵呵，那帮人肯定懒得去弄这些，分光汇聚后肯定搞不清楚
# 罗尔夫(80244085)  17:21:42
# 奇怪报文都是从一个万兆发往Switch
# ？
# 是哪个ip地址的万兆
# 需要我这里查一下线路吗
# 吴海波(1191107987)  17:25:49
# 没有负载均衡？
# 陈小阳(251779677)  17:25:59
# 我先去吃饭，有时给我电话
# 有事
# 罗尔夫(80244085)  17:26:17
# 跟线路没有关系
# 好
# 罗尔夫(80244085)  17:44:53
# 小阳，你回来得时候试一下把四个万兆的数据往一个CPU发
# 陈小阳(251779677)  17:58:06
# 回来了
# 我现在就给设备下电重启，然后重新配置
# 还有人在设备上吗？
# 罗尔夫(80244085)  18:01:04
# 我没有
# 孙清孟(361841482)  18:01:13
# 没在
# 陈小阳(251779677)  18:01:26
# 那我下电了
# 熊猫的熊(19550252)  18:06:21
# 现在标签率多少了
# 陈小阳(251779677)  18:14:13
# 刘学毅，我已经把所有的数据都导到 端口为9052板卡的56A上了
# 罗尔夫(80244085)  18:14:39
# 好，我先上去看一下
# 陈小阳(251779677)  18:14:47
# 恩
# 罗尔夫(80244085)  18:16:37
# 一共3G
# cpu出口没有负载均衡，我先看一下
# 罗尔夫(80244085)  18:20:30
# 一共就一百万用户在线
# 陈小阳(251779677)  18:36:52
# 现在有一百四十多万了
# 孙清孟(361841482)  18:37:28
#  会越来越多。
#  罗尔夫(80244085)  18:37:44
#  对，我在看负载均衡，很奇怪，一会我给你发一个版本，你升级看一下
#  陈小阳(251779677)  18:37:49
#  好
#  罗尔夫(80244085)  18:57:12
#  小阳，一会收一下邮件，我给你发了
#  罗尔夫(80244085)  18:59:09
#  已经发出去了，你把现场的板卡升一下吧
#  好
#  陈小阳(251779677)  19:08:53
#  升级一台先试看一下？
#  吴海波(1191107987)  19:11:16
#  升级】、
#  果断升级
#  陈小阳(251779677)  19:11:31
#  哈哈
#  熊猫的熊(19550252)  19:17:19
#
#
#  陈小阳(251779677)  19:18:31
#  设备起来了，9052
#  罗尔夫(80244085)  19:20:53
#  好，我先看一下
#  罗尔夫(80244085)  19:22:29
#  初始化没有成功
#  现场是4G内存是吧？
#
#  陈小阳(251779677)  19:23:17
#  对
#  罗尔夫(80244085)  19:24:14
#  刚才我看错了
#  罗尔夫(80244085)  19:26:59
#  奇怪，同样的版本我实验室可以自动负载均衡，为什么在现场的就不能呢？
#  陈小阳(251779677)  19:28:02
#  是因为我没有重启设备的时候，万兆口还有数据吗
#  是因为我重启设备的时候，万兆口还有数据吗
#
#  罗尔夫(80244085)  19:28:52
#  应该不是，我想想
#  陈小阳(251779677)  19:30:24
#  怎么看是否自动负载均衡，我把万兆数据口拔掉，再重启一下试试
#  罗尔夫(80244085)  19:31:15
#  看switch与cpu之间的口stat 0 27 和stat 1 10
#  k靠，我看错了，是报文只从8110下来的，
#  我又把tx rx看反了
#  陈小阳(251779677)  19:32:30
#
#  呵呵，差不多
#  陈小阳(251779677)  19:35:11
#  我把9053端口的设备重启一下，刚刚升级了，没有重启过设备，可以吗
#  陈小阳(251779677)  19:38:51
#  不回我，那我重启了
#  罗尔夫(80244085)  19:40:29
#  不好意思，这个版本编译有问题
#  陈小阳(251779677)  19:41:05
#  哦，没事，重新编译一个就行
#  估计美亚那个兄弟累着了，不想带机房了，一会儿得撤了
#  陈小阳(251779677)  19:43:08
#  多久能编好
#  吴海波(1191107987)  19:43:17
#  在你撤的时候一定要弄一个能用的版本挂上去
#  我这边远程采集一些数据
#  罗尔夫(80244085)  19:44:27
#  你要是急着走，就先恢复到之前清孟给你的吧，我编出来得先试一下
#  这个版本看不出东西
#  陈小阳(251779677)  19:45:36
#  不是可以远程升级吗
#  管理口的线，不拔
#  罗尔夫(80244085)  19:46:18
#  嗯，别拔
#  陈小阳(251779677)  19:46:30
#  好
#  吴海波(1191107987)  19:48:53
#  确保可以远程登录
#  罗尔夫(80244085)  19:49:08
#  对
#  陈小阳(251779677)  19:49:08
#  我走之前会跟你们说一声，等有肯定答复后，再走
#  陈小阳(251779677)  19:52:32
#  升级好了，我全部重启一下
#  罗尔夫(80244085)  19:52:47
#  hao
#  还是用一个CPU就行
#  陈小阳(251779677)  19:53:07
#  好
#  吴海波(1191107987)  19:54:17
#  对
#  陈小阳(251779677)  20:01:28
#  我配置好了
#  等正常登陆吗
#  远程
#  我试一下
#  地址变了么
#  陈小阳(251779677)  20:02:06
#  没变
#  陈小阳(251779677)  20:03:32
#  行吗
#  吴海波(1191107987)  20:03:49
#  好像进不去
#  陈小阳(251779677)  20:04:43
#  端口 9052、9053
#  罗尔夫(80244085)  20:04:54
#  我能进去
#  吴海波(1191107987)  20:05:19
#  9052么
#  陈小阳(251779677)  20:05:22
#  恩
#  吴海波(1191107987)  20:05:30
#  我怎么进不去啊
#  罗尔夫(80244085)  20:05:35
#  dui
#  陈小阳(251779677)  20:05:46
#  哈哈，人品
#  吴海波(1191107987)  20:06:23
#
#  进去了，填错了
#  陈小阳(251779677)  20:06:48
#  呵呵
#  那我闪人了，
#  吴海波(1191107987)  20:06:55
#  把9052给填写在用户名了
#  陈小阳(251779677)  20:07:12
#  美亚的人都把所有东西收拾好了，等着我闪人呢
#  吴海波(1191107987)  20:07:19
#  好
#  陈小阳(251779677)  20:07:24
#  下了
# 
# 
-----------------------------------------------------------------------------
Auto-merging libexec/zxmx.mk
Auto-merging sse/zxmd_mproc.c
Merge made by recursive.
 Makefile                   |    8 +-
 cli/netgate                |    2 +-
 include/executive-config.h |    3 +
 libexec/Makefile.build     |    6 +-
 libexec/acl/zxmx_acl_hfa.c |  124 ++++++++++++---------
 libexec/acl/zxmx_acl_hfa.h |   20 +++-
 libexec/acl/zxmx_hfa.c     |   73 +++++++++----
 libexec/acl/zxmx_hfa.h     |    6 +-
 libexec/acl/zxmx_hfa_api.h |  269 ++++++++++++++++++++++++++++++++++++++++++++
 libexec/eprm/zxmx_if.c     |    6 -
 libexec/zxmx.mk            |    4 +-
 libexec/zxmx_debug.c       |    6 +
 libexec/zxmx_debug.h       |   15 ++-
 libexec/zxmx_utils.h       |    6 +-
 mduapi/src/mduapi_hfa.c    |   11 +--
 sdk/OCTEON-SDK             |    2 +-
 sse/Makefile               |    7 +-
 sse/zxmd_mproc.c           |   22 +---
 18 files changed, 453 insertions(+), 137 deletions(-)
 create mode 100644 libexec/acl/zxmx_hfa_api.h
-----------------------------------------------------------------------------
Updating 8c92259..61d03e3
Fast-forward
 Config.in                         |   45 +
 cli/netgate                       |    2 +-
 libexec/Kbuild                    |   12 +
 libexec/acl/Kbuild                |   16 +
 libexec/acl/hfa/zxmx_acl_hfa.c    |  338 +++++
 libexec/acl/hfa/zxmx_acl_hfa.h    |  163 ++
 libexec/acl/hfa/zxmx_hfa.c        |  163 ++
 libexec/acl/hfa/zxmx_hfa.h        |   25 +
 libexec/acl/rfc/zxmx_acl.c        | 1106 ++++++++++++++
 libexec/acl/rfc/zxmx_acl.h        |  363 +++++
 libexec/acl/rfc/zxmx_aclex.c      | 1229 +++++++++++++++
 libexec/acl/rfc/zxmx_aclex.h      |  353 +++++
 libexec/acl/rfc/zxmx_acsm2.c      | 3002 +++++++++++++++++++++++++++++++++++++
 libexec/acl/rfc/zxmx_acsm2.h      |  180 +++
 libexec/acl/rfc/zxmx_dheap.c      |  826 ++++++++++
 libexec/acl/rfc/zxmx_dheap.h      |   62 +
 libexec/dpim/3gpp/zxmx_3gpp.h     |    2 -
 libexec/zxmx.mk                   |    2 +-
 libexec/zxmx_pcie.h               |  159 ++-
 mduapi/src/Makefile               |   17 +-
 mduapi/src/mduapi_acl.c           | 1577 +++++++++++++++++++
 mduapi/src/mduapi_acl.h           |  378 +++++
 mduapi/src/mduapi_aclex.c         | 1282 ++++++++++++++++
 mduapi/src/mduapi_aclex.h         |  304 ++++
 mduapi/src/mduapi_pcie.c          | 1261 ++++++++++++++++
 mduapi/src/mduapi_pcie.h          |   61 +
 mduapi/src/mduapi_rfc.c           |  233 +++
 mduapi/src/mduapi_rfc.h           |   23 +
 sdk/OCTEON-SDK                    |    2 +-
 sse/build_data_eth_acsmtest512.sh |  112 --
 sse/build_data_pos.sh             |   56 -
 sse/build_data_vlan.sh            |   57 -
 sse/zxmd_init.c                   |   26 +
 sse/zxmd_main.c                   |    2 +
 sse/zxmd_mproc.c                  |  220 +++-
 35 files changed, 13422 insertions(+), 237 deletions(-)
 create mode 100644 libexec/acl/Kbuild
 create mode 100644 libexec/acl/hfa/zxmx_acl_hfa.c
 create mode 100644 libexec/acl/hfa/zxmx_acl_hfa.h
 create mode 100644 libexec/acl/hfa/zxmx_hfa.c
 create mode 100644 libexec/acl/hfa/zxmx_hfa.h
 create mode 100644 libexec/acl/rfc/zxmx_acl.c
 create mode 100644 libexec/acl/rfc/zxmx_acl.h
 create mode 100644 libexec/acl/rfc/zxmx_aclex.c
 create mode 100644 libexec/acl/rfc/zxmx_aclex.h
 create mode 100644 libexec/acl/rfc/zxmx_acsm2.c
 create mode 100644 libexec/acl/rfc/zxmx_acsm2.h
 create mode 100644 libexec/acl/rfc/zxmx_dheap.c
 create mode 100644 libexec/acl/rfc/zxmx_dheap.h
 create mode 100644 mduapi/src/mduapi_acl.c
 create mode 100644 mduapi/src/mduapi_acl.h
 create mode 100644 mduapi/src/mduapi_aclex.c
 create mode 100644 mduapi/src/mduapi_aclex.h
 create mode 100644 mduapi/src/mduapi_rfc.c
 create mode 100644 mduapi/src/mduapi_rfc.h
 mode change 160000 => 120000 sdk/OCTEON-SDK

报文进入
pre {
width: 580px;
margin: 10px 0 0 0;
padding: 10px;
border: 0;
border: 1px dotted #785;
background: #f5f5f5;
font-family: "Courier New",monospace;
font-size: 12px;
}
900005968985

(http://github.com/sqm2050/wiki/raw/master/fmt_field.png)


 md_ctl_t;
==========
typedef union {
	struct {
		union {
			struct {
				u32 mac:8,
				    type:7,
				    cmd:1,
				    rsv:16;
			} hdr;
			struct {
				u32 hdr:16,
				    acl0:16;
				u32 acl1:16,
				    iif:6,
				    rsv0:2,
				    fmt_first:1,
				    oif:6,	/* Output interface ID */
				    fmt_val:1;  /*hit fmt packet*/
				u32	rsv1:7,
					idx:25;	/* Hash index of packet, RO */
				u16 proto;
				u8 iphdr[0];
			} pkt;	/* Normal IP Packet */
			struct {
				u32 hdr:16,
				    acl0:16;
				u32 acl1:16,
				    rsv0:2,
				    iif:6,
				    first:1,
				    oif:6,
				    fmt_val:1;/*hit fmt packet*/
				u32	rsv1:7,
					idx:25;	/* Hash index of packet, RO */
				u32 proto:16,
				    rsv2:8,
				    ft_proto:8;
				u32 sip;
				u32 dip;
				u32 sp:16,
				    dp:16;
				u32 rsv3;
				u8 iphdr[0];
			} pkt_ex;	/* Extend IP Packet */
			struct {
				u32 hdr:16,
				    tim_in_wqe:8,
				    rsv:8;
				u32 rsv0;
				u32 idx:25,
				    grp:4,
				    rsv1:3;
				u32 rsv5;
				u32 rsv2;
				u32 proto:16,	/* ETH_P_FMT */
				    rsv3:16;
				u32 rsv4;
				fmt_key_t f;	/* Flow tuple */
			} st;		/* stat packet*/
			struct {
				u32 hdr:16,	/* Header above, RO */
				    tim_in_wqe:8,
				    rsv:8;
				u32	rsv0;
				u32 idx:25,
				    grp:4,
				    rsv1:3;
				u32 vlan_out_prot:16,	/*0x8100*/
				    vlan_out_prio:3,
				    vlan_out_cfi:1,
				    vlan_out_tag:12;
				u32 vlan_in_prot:16,	/*0x8100*/
				    vlan_in_prio:3,
				    vlan_in_cfi:1,
				    vlan_in_tag:12;
				u32 rsv2;
				u32 proto:16,
				    rsv3:16;
				u32 rsv4;
				fmt_key_t f;	
			} flow;		
		};
	};
	u8 pad[64];
} md_ctl_t;

typedef union __md_fmt_t {
	struct {
		union {
			struct {
				u64 mac:8,
				    type:7,
				    cmd:1,
				    tim_in_wqe:8,
				    next_ptr:40;
			};
			u64 dword0;
		};
		union {
			struct {
				u32 idx:25,
				    grp:4,
				    is_head:1,
				    tag_type:2;
				struct {
					u32 eth_proto:16,
					    pri:3,
					    cfi:1,
					    tag:12;
				} vlan_out;
			};
			u64 dword1;
		};
		union{
			struct{
				struct{
					u16 eth_proto;
					u16 tag;
				}vlan_in;
				s32 cnt1;
			};
			u64 dword2;
		};
		union {
			union {
				struct {
					u64 proto:16,
					    list:48;
				};
				struct {
					u32 rsv1;
					cvmx_spinlock_t lock;
				};
			};
			u64 dword3;
		};
		fmt_key_t k;
	};
	u8 pad[64];
	u64 data_64[8];
} md_fmt_t;


10.10.165.201 8003 串口
10.10.167.142


4-> 
3-> 
4-> Assertion failed:/home/sqm/tmp/JusonFlow/libexec/url_block/zxmx_url_block.c,line 303 
3-> Assertion failed:/home/sqm/tmp/JusonFlow/libexec/url_block/zxmx_url_block.c,line 303 
2-> Assertion failed:/home/sqm/tmp/JusonFlow/libexec/url_block/zxmx_url_block.c,line 303 
5-> 
5-> Assertion failed:/home/sqm/tmp/JusonFlow/libexec/url_block/zxmx_url_block.c,line 303


 t5 ($13): 0x0000000000000000 	  sp ($29): 0x00000000160ffee8
 t6 ($14): 0x0000000000000000 	  s8 ($30): 0x0000000010060000
 t7 ($15): 0x0000000000000000 	  ra ($31): 0x00000000100029f8
      COP0_CAUSE: 0x00000000c0008008
     COP0_STATUS: 0x0000000050000ce3
   COP0_BADVADDR: 0x0000000000000000
        COP0_EPC: 0x00000000100029f0
******************************************************************
Backtrace:

  #0  0x1004a704
  #1  0x1004a8b0
  #2  0x1004aac0
  #3  0x100029f0
  #4  0x100037d4
  #5  0x10001280
  #6  0x100002f8
******************************************************************
9-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f733f77
9-> :[             dpim_decode_tcp][ 651]:Get a url pkt
Core 9: Unhandled Exception. Cause register decodes to:
tlb load/fetch
******************************************************************
 r0 ($00): 0x0000000000000000 	  s0 ($16): 0x0000000037cd9b00
 at ($01): 0xffffffffffbfffff 	  s1 ($17): 0x0000000037cd9430
 v0 ($02): 0x0000000000000000 	  s2 ($18): 0x0000000000000000
 v1 ($03): 0x00000000100640ca 	  s3 ($19): 0x0000000037cd9444
 a0 ($04): 0x0000000010064110 	  s4 ($20): 0x0000000014000000
 a1 ($05): 0x00000000100640c0 	  s5 ($21): 0x0000000000000000
 a2 ($06): 0x00000000100643d0 	  s6 ($22): 0x00000000100640c0
 a3 ($07): 0x000000000000028c 	  s7 ($23): 0x0000000010060000
 t0 ($08): 0x000000001610003d 	  t8 ($24): 0x0000000000000000
 [[t1]] ($09): 0x000000001006410d 	  t9 ($25): 0x0000000010000ce8
 t2 ($10): 0x00000000100640fd 	  k0 ($26): 0x000000001004a9f8
 t3 ($11): 0x000000001610003d 	  k1 ($27): 0xffffffff80001190
 t4 ($12): 0x0000000000000010 	  gp ($28): 0x0000000012009240
 t5 ($13): 0x0000000000000000 	  sp ($29): 0x00000000160ffee8
 t6 ($14): 0x0000000000000000 	  s8 ($30): 0x0000000010060000
 t7 ($15): 0x0000000000000000 	  ra ($31): 0x00000000100029f8
      COP0_CAUSE: 0x00000000c0008008
     COP0_STATUS: 0x0000000050000ce3
   COP0_BADVADDR: 0x0000000000000000
        COP0_EPC: 0x00000000100029f0
******************************************************************
Backtrace:

  #0  0x1004a704
  #1  0x1004a8b0
  #2  0x1004aac0
  #3  0x100029f0
  #4  0x100037d4
  #5  0x10001280
  #6  0x100002f8
******************************************************************


* HTTP
* zxmx_url_block.c---152

MCDebug(config-zxmdu-cn56a)# 1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f733f77
1-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[             dpim_decode_url][ 174]:URL:www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90 HTTP/1.1
1-> :[             dpim_decode_tcp][ 654]:www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90 HTTP/1.1
1-> Assertion failed:/home/sqm/tmp/JusonFlow/libexec/url_block/zxmx_url_block.c,line 152 

* HTTP ---> ok

2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f733f77
2-> :[             dpim_decode_tcp][ 651]:Get a url pkt
2-> :[             dpim_decode_url][ 174]:URL:www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
2-> 



juson(config-cpu0)# 1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f657272
1-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[             dpim_decode_url][ 174]:URL:
1-> 
1-> Assertion failed:/home/sqm/tmp/JusonFlow/libexec/url_block/zxmx_url_block.c,line 153 
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f657272
2-> :[             dpim_decode_tcp][ 651]:Get a url pkt
Core 2: Unhandled Exception. Cause register decodes to:
address exc, load/fetch
******************************************************************
 r0 ($00): 0x0000000000000000 	  s0 ($16): 0x6572722e74616f62
 at ($01): 0xffffffffffbfffff 	  s1 ($17): 0x00000000d52df0a0
 v0 ($02): 0x0000000000000050 	  s2 ($18): 0x0000000000000030
 v1 ($03): 0x00000000d52df0f0 	  s3 ($19): 0x00000000d52df0a0
 a0 ($04): 0x00000000d52df0a0 	  s4 ($20): 0x0000000000000030
 a1 ($05): 0x6572722e74616f62 	  s5 ($21): 0x00000000160ffaa8
 a2 ($06): 0x0000000000000052 	  s6 ($22): 0x00000000100641a0
 a3 ($07): 0x00000000000002fd 	  s7 ($23): 0x0000000010060000
 t0 ($08): 0x0000000037cd9478 	  t8 ($24): 0x0000000000000000
 t1 ($09): 0x00000000160ffea8 	  t9 ($25): 0x0000000010000ce8
 t2 ($10): 0x00000000160ffaa8 	  k0 ($26): 0x000000001004aad8
 t3 ($11): 0x000000000000006f 	  k1 ($27): 0xffffffff80001190
 t4 ($12): 0x0000000000000010 	  gp ($28): 0x0000000012009240
 t5 ($13): 0x0a0aa8b23d87a97d 	  sp ($29): 0x00000000160ff630
 t6 ($14): 0x000000000a0aa8b2 	  s8 ($30): 0x0000000010060000
 t7 ($15): 0x0000000000009d06 	  ra ($31): 0x00000000100274e4
      COP0_CAUSE: 0x0000000040008010
     COP0_STATUS: 0x0000000050000ce3
   COP0_BADVADDR: 0x6572722e74616f7a
        COP0_EPC: 0x0000000010026d80
******************************************************************
Backtrace:

  #0  0x1004a7e4
  #1  0x1004a990
  #2  0x1004aba0
  #3  0x10026d80
  #4  0x100274e4
  #5  0x10001944
  #6  0x10002a14
  #7  0x100037bc
  #8  0x10001280
  #9  0x100002f8
************************************************



juson(config-cpu0)# 1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f657272
1-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[             dpim_decode_url][ 166]:To process abs_path
1-> :[                get_abs_path][  72]:uri_len: 12 abs_uri:/error1.html
1-> :[                get_abs_path][  91]:Host_len: 14 Host:err.taobao.com
1-> :[                get_abs_path][ 108]:str_len: 26 Host:err.taobao.com/error1.html
1-> :[             dpim_decode_url][ 181]:URL:err.taobao.com/error1.html
1-> :[                    free_url][ 312]:FREE pkt url



1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f657272
1-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[             dpim_decode_url][ 166]:To process abs_path
1-> :[                get_abs_path][  72]:uri_len: 12 abs_uri:/error1.html
1-> :[                get_abs_path][  91]:Host_len: 14 Host:err.taobao.com
1-> :[                get_abs_path][ 108]:str_len: 26 Host:err.taobao.com/error1.html
1-> :[             dpim_decode_url][ 181]:URL:err.taobao.com/error1.html
1-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
1-> :[                     fmt_add][ 447]:add a new url into fmt
Core 1: Unhandled Exception. Cause register decodes to:
address exc, load/fetch
******************************************************************
 r0 ($00): 0x0000000000000000 	  s0 ($16): 0x00000000d52dfe00

 at ($01): 0xffffffffffbfffff 	  s1 ($17): 0x0000000085524dc0
 v0 ($02): 0x0000000000000000 	  s2 ($18): 0x0000000037cd8020
 v1 ($03): 0x00000000d52dfe00 	  s3 ($19): 0x00000000160fff38
 a0 ($04): 0x0000000010060000 	  s4 ($20): 0x0000000037cd8000
 a1 ($05): 0x00000000d52dfe00 	  s5 ($21): 0x0000000085524d80
 a2 ($06): 0x6572722e74616f62 	  s6 ($22): 0x0000000010060000
 a3 ($07): 0x0000000000000000 	  s7 ($23): 0x8001f00000000418
 t0 ($08): 0x000000001610003d 	  t8 ($24): 0xfffffffffffffff0
 t1 ($09): 0x0000000010066bc6 	  t9 ($25): 0x0000000000cee460
 t2 ($10): 0x0000000010066bad 	  k0 ($26): 0x000000001004abe0
 t3 ($11): 0x000000001610003d 	  k1 ($27): 0xffffffff80001190
 t4 ($12): 0x0000000000000019 	  gp ($28): 0x0000000012009240
 t5 ($13): 0x0000000000004000 	  sp ($29): 0x00000000160fff00
 t6 ($14): 0x000000000a0aa8b2 	  s8 ($30): 0x000000fffffffff8
 t7 ($15): 0x000000000000eba5 	  ra ($31): 0x000000001000ca7c
      COP0_CAUSE: 0x0000000040008010
     COP0_STATUS: 0x0000000050000ce3
   COP0_BADVADDR: 0x6572722e74616f62
        COP0_EPC: 0x000000001000cae0
******************************************************************
Backtrace:

```
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f657272
1-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[             dpim_decode_url][ 166]:To process abs_path
1-> :[                get_abs_path][  72]:uri_len: 12 abs_uri:/error1.html
1-> :[                get_abs_path][  91]:Host_len: 14 Host:err.taobao.com
1-> :[                get_abs_path][ 108]:str_len: 26 Host:err.taobao.com/error1.html
1-> :[             dpim_decode_url][ 181]:URL:err.taobao.com/error1.html
1-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
1-> :[                     fmt_add][ 449]:add a new url into fmt
1-> :[                     fmt_add][ 456]:url_addr 0x0 
1-> :[                     fmt_add][ 464]:not old url_addr
1-> :[                     fmt_add][ 468]:get url str for fmt err.taobao.com/error1.html
1-> :[                 cp_and_link][ 207]:get url str for fmt err.taobao.com/error1.html
1-> :[                    free_url][ 312]:FREE pkt url
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f657272
1-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[             dpim_decode_url][ 166]:To process abs_path
1-> :[                get_abs_path][  72]:uri_len: 12 abs_uri:/error1.html
1-> :[                get_abs_path][  91]:Host_len: 14 Host:err.taobao.com
1-> :[                get_abs_path][ 108]:str_len: 26 Host:err.taobao.com/error1.html
1-> :[             dpim_decode_url][ 181]:URL:err.taobao.com/error1.html
1-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
1-> :[                     fmt_add][ 449]:add a new url into fmt
1-> :[                     fmt_add][ 456]:url_addr 0xd52e04d0 
1-> :[                     fmt_add][ 458]:find old url_addr
1-> :[                    free_url][ 312]:FREE pkt url
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f657272
1-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[             dpim_decode_url][ 166]:To process abs_path
1-> :[                get_abs_path][  72]:uri_len: 12 abs_uri:/error1.html
1-> :[                get_abs_path][  91]:Host_len: 14 Host:err.taobao.com
1-> :[                get_abs_path][ 108]:str_len: 26 Host:err.taobao.com/error1.html
1-> :[             dpim_decode_url][ 181]:URL:err.taobao.com/error1.html
1-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
1-> :[                     fmt_add][ 449]:add a new url into fmt
1-> :[                     fmt_add][ 456]:url_addr 0xd52e04d0 
1-> :[                     fmt_add][ 458]:find old url_addr
1-> :[                    free_url][ 312]:FREE pkt url
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f657272
1-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[             dpim_decode_url][ 166]:To process abs_path
1-> :[                get_abs_path][  72]:uri_len: 12 abs_uri:/error1.html
1-> :[                get_abs_path][  91]:Host_len: 14 Host:err.taobao.com
1-> :[                get_abs_path][ 108]:str_len: 26 Host:err.taobao.com/error1.html
1-> :[             dpim_decode_url][ 181]:URL:err.taobao.com/error1.html
1-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
1-> :[                     fmt_add][ 449]:add a new url into fmt
1-> :[                     fmt_add][ 456]:url_addr 0xd52e04d0 
1-> :[                     fmt_add][ 458]:find old url_addr
1-> :[                    free_url][ 312]:FREE pkt url

 get_abs_path][  72]:uri_len: 281 abs_uri:/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
1-> :[                    free_url][ 313]:FREE pkt url
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0xfe58
6-> :[             dpim_decode_tcp][ 648]:Get pkt:0x0
5-> :[                 cp_and_link][ 187]:get url str for fmt api.share.baidu.com/getsharenum?urls=17091797201692772740,11532546021778491826,4607969594987258370,13371752734895889225,5427010760400390956,3331117510697159647,17352347182496212156,17499921033298219140,2856178610194949267&callback=bds.se.like.giveData
4-> :[             dpim_decode_tcp][ 648]:Get pkt:0x0
2-> :[                    free_url][ 313]:FREE pkt url
4-> :[                    free_url][ 313]:FREE pkt url
5-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
7-> :[                    free_url][ 313]:FREE pkt url
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x0
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x0
3-> :[                get_abs_path][  91]:Host_len: 13 Host:www.baidu.com
2-> :[                    free_url][ 313]:FREE pkt url
3-> :[                get_abs_path][ 108]:str_len: 294 Host:www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
7-> :[             dpim_decode_tcp][ 648]:Get pkt:0x0
1-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
6-> :[                    free_url][ 313]:FREE pkt url
7-> :[                    free_url][ 313]:FREE pkt url
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x0
1-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
8-> :[                    free_url][ 313]:FREE pkt url
3-> :[             dpim_decode_url][ 181]:URL:www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
4-> :[             dpim_decode_tcp][ 648]:Get pkt:0x0
5-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
1-> :[                    free_url][ 313]:FREE pkt url
3-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
6-> :[             fmt_stat_report][ 295]:fmt report eif:0
7-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f733f77
9-> :[             dpim_decode_tcp][ 648]:Get pkt:0x485454502f312e31
7-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x2226
4-> :[                    free_url][ 313]:FREE pkt url
1-> :[                    free_url][ 313]:FREE pkt url
3-> :[                     fmt_add][ 470]:add a new url into fmt
6-> :[        url_block_report_url][ 196]:Report 0 url, Total_size:64
4-> :[             dpim_decode_tcp][ 648]:Get pkt:0xe94
7-> :[             dpim_decode_url][ 166]:To process abs_path
3-> :[                     fmt_add][ 475]:url_addr 0xd52df9f0 
5-> :[                    free_url][ 313]:FREE pkt url
8-> :[             dpim_decode_tcp][ 648]:Get pkt:0x43fb
5-> :[             dpim_decode_tcp][ 648]:Get pkt:0xb263
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x2ee8
7-> :[                get_abs_path][  72]:uri_len: 281 abs_uri:/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
9-> :[                    free_url][ 313]:FREE pkt url
7-> :[                get_abs_path][  91]:Host_len: 13 Host:www.baidu.com
3-> :[                     fmt_add][ 477]:find old url_addr
8-> :[                    free_url][ 313]:FREE pkt url
6-> :[        url_block_report_url][ 198]:Fmt delete wqe push
3-> :[             link_url_to_fmt][ 232]:Compare: www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90 www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
6-> :[             dpim_decode_tcp][ 648]:Get pkt:0x3e69
2-> :[                    free_url][ 313]:FREE pkt url
1-> :[                    free_url][ 313]:FREE pkt url
3-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
5-> :[                    free_url][ 313]:FREE pkt url
1-> :[                    free_url][ 313]:FREE pkt url
4-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
7-> :[                get_abs_path][ 108]:str_len: 294 Host:www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
8-> :[             dpim_decode_tcp][ 648]:Get pkt:0x3d6d6b33534c564e
5-> :[             dpim_decode_tcp][ 648]:Get pkt:0x485454502f312e31
6-> :[                    free_url][ 313]:FREE pkt url
7-> :[             dpim_decode_url][ 181]:URL:www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x3d6d6b33534c564e
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x6226
4-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
1-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
3-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
1-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
2-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
4-> :[                    free_url][ 313]:FREE pkt url
1-> :[                    free_url][ 313]:FREE pkt url
6-> :[           zxmd_main_process][  88]:Get fmt aged wqe
2-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
3-> :[                    free_url][ 313]:FREE pkt url
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x441b
9-> :[             dpim_decode_tcp][ 648]:Get pkt:0x377f
3-> :[             dpim_decode_tcp][ 648]:Get pkt:0xe297
1-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
3-> :[                    free_url][ 313]:FREE pkt url
9-> :[                    free_url][ 313]:FREE pkt url
5-> :[                    free_url][ 313]:FREE pkt url
4-> :[                    free_url][ 313]:FREE pkt url
9-> :[             dpim_decode_tcp][ 648]:Get pkt:0x1577
2-> :[                    free_url][ 313]:FREE pkt url
6-> :[             dpim_decode_tcp][ 648]:Get pkt:0xbfc8
3-> :[                    free_url][ 313]:FREE pkt url
7-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
1-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
6-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
3-> :[                    free_url][ 313]:FREE pkt url
1-> :[                    free_url][ 313]:FREE pkt url
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x1f8b080000000000
6-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
3-> :[             dpim_decode_tcp][ 648]:Get pkt:0x6eab
4-> :[             dpim_decode_tcp][ 648]:Get pkt:0x1b51
6-> :[                    free_url][ 313]:FREE pkt url
7-> :[                     fmt_add][ 470]:add a new url into fmt
9-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
2-> :[                    free_url][ 313]:FREE pkt url
8-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
9-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x9ffa8bc33d2f8ea8
7-> :[                     fmt_add][ 475]:url_addr 0xd52df9f0 
1-> :[                    free_url][ 313]:FREE pkt url
4-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
9-> :[                    free_url][ 313]:FREE pkt url
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x34b7
4-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
1-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
4-> :[                    free_url][ 313]:FREE pkt url
7-> :[                     fmt_add][ 477]:find old url_addr
3-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
4-> :[                    free_url][ 313]:FREE pkt url
8-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
9-> :[                    free_url][ 313]:FREE pkt url
1-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
7-> :[             link_url_to_fmt][ 232]:Compare: www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90 www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
8-> :[                    free_url][ 313]:FREE pkt url
9-> :[             dpim_decode_tcp][ 648]:Get pkt:0x6b48
1-> :[                    free_url][ 313]:FREE pkt url
5-> :[             dpim_decode_tcp][ 648]:Get pkt:0xaf41
6-> :[             dpim_decode_tcp][ 648]:Get pkt:0x885b
9-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
3-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x485454502f312e31
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0xe8b8
4-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f722f77
2-> :[                    free_url][ 313]:FREE pkt url
6-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x111d
3-> :[                    free_url][ 313]:FREE pkt url
8-> :[             fmt_stat_report][ 295]:fmt report eif:0
4-> :[             dpim_decode_tcp][ 651]:Get a url pkt
7-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
2-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
4-> :[             dpim_decode_url][ 166]:To process abs_path
6-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
2-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
8-> :[        url_block_report_url][ 196]:Report 1 url, Total_size:107
2-> :[                    free_url][ 313]:FREE pkt url
5-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
7-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
1-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
4-> :[                get_abs_path][  72]:uri_len: 46 abs_uri:/r/www/cache/static/global/img/bg_ba15d188.png
1-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
4-> :[                get_abs_path][  91]:Host_len: 15 Host:s1.bdstatic.com
7-> :[                    free_url][ 313]:FREE pkt url
1-> :[                    free_url][ 313]:FREE pkt url
9-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
6-> :[                    free_url][ 313]:FREE pkt url
3-> :[             dpim_decode_tcp][ 648]:Get pkt:0x1f8b080000000000
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x1577
8-> :[        url_block_report_url][ 198]:Fmt delete wqe push
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x1f8b080000000000
3-> :[                    free_url][ 313]:FREE pkt url
6-> :[             dpim_decode_tcp][ 648]:Get pkt:0x2871
1-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
3-> :[             dpim_decode_tcp][ 648]:Get pkt:0x6226
5-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
1-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
3-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
2-> :[                    free_url][ 313]:FREE pkt url
1-> :[                    free_url][ 313]:FREE pkt url
6-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x441b
5-> :[                    free_url][ 313]:FREE pkt url
6-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
1-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0xaf41
8-> :[             dpim_decode_tcp][ 648]:Get pkt:0x485454502f312e31
1-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
4-> :[                get_abs_path][ 108]:str_len: 61 Host:s1.bdstatic.com/r/www/cache/static/global/img/bg_ba15d188.png
7-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f733f77
2-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
1-> :[                    free_url][ 313]:FREE pkt url
2-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
4-> :[             dpim_decode_url][ 181]:URL:s1.bdstatic.com/r/www/cache/static/global/img/bg_ba15d188.png
6-> :[                    free_url][ 313]:FREE pkt url
3-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
9-> :[                    free_url][ 313]:FREE pkt url
7-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x1b51
3-> :[                    free_url][ 313]:FREE pkt url
4-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
5-> :[                    free_url][ 313]:FREE pkt url
2-> :[                    free_url][ 313]:FREE pkt url
8-> :[                    free_url][ 313]:FREE pkt url
3-> :[             dpim_decode_tcp][ 648]:Get pkt:0xbfc8
5-> :[             dpim_decode_tcp][ 648]:Get pkt:0x9ffa8bc33d2f8ea8
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0xfa92
1-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
7-> :[             dpim_decode_url][ 166]:To process abs_path
9-> :[             dpim_decode_tcp][ 648]:Get pkt:0xffc2
1-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
4-> :[                    free_url][ 313]:FREE pkt url
2-> :[                    free_url][ 313]:FREE pkt url
4-> :[             dpim_decode_tcp][ 648]:Get pkt:0xd20de321343449e5
8-> :[           zxmd_main_process][  88]:Get fmt aged wqe
7-> :[                get_abs_path][  72]:uri_len: 281 abs_uri:/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
6-> :[             dpim_decode_tcp][ 648]:Get pkt:0x485454502f312e31
1-> :[                    free_url][ 313]:FREE pkt url
4-> :[                    free_url][ 313]:FREE pkt url
5-> :[                    free_url][ 313]:FREE pkt url
4-> :[             dpim_decode_tcp][ 648]:Get pkt:0xd778
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x988
3-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
6-> :[                    free_url][ 313]:FREE pkt url
5-> :[             dpim_decode_tcp][ 648]:Get pkt:0xbb91
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x885b
8-> :[           free_url_from_fmt][ 253]:Free one url success
1-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
7-> :[                get_abs_path][  91]:Host_len: 13 Host:www.baidu.com
1-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
2-> :[                    free_url][ 313]:FREE pkt url
8-> :[             dpim_decode_tcp][ 648]:Get pkt:0x485454502f312e31
1-> :[                    free_url][ 313]:FREE pkt url
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x485454502f312e31
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0x48be
2-> :[                    free_url][ 313]:FREE pkt url
6-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f696d67
5-> :[                    free_url][ 313]:FREE pkt url
7-> :[                get_abs_path][ 108]:str_len: 294 Host:www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
3-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
5-> :[             dpim_decode_tcp][ 648]:Get pkt:0x485454502f312e31
6-> :[             dpim_decode_tcp][ 651]:Get a url pkt
3-> :[                    free_url][ 313]:FREE pkt url
5-> :[                    free_url][ 313]:FREE pkt url
3-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f722f77
6-> :[             dpim_decode_url][ 166]:To process abs_path
4-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
7-> :[             dpim_decode_url][ 181]:URL:www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
1-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
7-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
1-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
5-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f696d67
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x485454502f312e31
4-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
2-> :[                    free_url][ 313]:FREE pkt url
4-> :[                    free_url][ 313]:FREE pkt url
5-> :[             dpim_decode_tcp][ 651]:Get a url pkt
1-> :[                    free_url][ 313]:FREE pkt url
2-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f676574
3-> :[             dpim_decode_tcp][ 651]:Get a url pkt
5-> :[             dpim_decode_url][ 166]:To process abs_path
4-> :[             dpim_decode_tcp][ 648]:Get pkt:0xefb0
3-> :[             dpim_decode_url][ 166]:To process abs_path
7-> :[                     fmt_add][ 470]:add a new url into fmt
5-> :[                get_abs_path][  72]:uri_len: 23 abs_uri:/img/baidu_jgylogo3.gif
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0xfa92
4-> :[                    free_url][ 313]:FREE pkt url
5-> :[                get_abs_path][  91]:Host_len: 13 Host:www.baidu.com
9-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
1-> :[                    free_url][ 313]:FREE pkt url
6-> :[                get_abs_path][  72]:uri_len: 23 abs_uri:/img/baidu_jgylogo3.gif
1-> :[             dpim_decode_tcp][ 648]:Get pkt:0xbb91
5-> :[                get_abs_path][ 108]:str_len: 36 Host:www.baidu.com/img/baidu_jgylogo3.gif
7-> :[                     fmt_add][ 475]:url_addr 0xd52df9f0 
1-> :[                    free_url][ 313]:FREE pkt url
8-> :[                    free_url][ 313]:FREE pkt url
2-> :[             dpim_decode_tcp][ 651]:Get a url pkt
6-> :[                get_abs_path][  91]:Host_len: 13 Host:www.baidu.com
3-> :[                get_abs_path][  72]:uri_len: 48 abs_uri:/r/www/cache/static/global/js/common_5955eef4.js
5-> :[             dpim_decode_url][ 181]:URL:www.baidu.com/img/baidu_jgylogo3.gif
4-> :[             dpim_decode_tcp][ 648]:Get pkt:0x474554202f722f77
6-> :[                get_abs_path][ 108]:str_len: 36 Host:www.baidu.com/img/baidu_jgylogo3.gif
4-> :[             dpim_decode_tcp][ 651]:Get a url pkt
2-> :[             dpim_decode_url][ 166]:To process abs_path
5-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
7-> :[                     fmt_add][ 477]:find old url_addr
3-> :[                get_abs_path][  91]:Host_len: 15 Host:s1.bdstatic.com
6-> :[             dpim_decode_url][ 181]:URL:www.baidu.com/img/baidu_jgylogo3.gif
7-> :[             link_url_to_fmt][ 232]:Compare: www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90 www.baidu.com/s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
8-> :[             fmt_stat_report][ 295]:fmt report eif:0
9-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
3-> :[                get_abs_path][ 108]:str_len: 63 Host:s1.bdstatic.com/r/www/cache/static/global/js/common_5955eef4.js
6-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
4-> :[             dpim_decode_url][ 166]:To process abs_path
5-> :[                     fmt_add][ 470]:add a new url into fmt
8-> :[        url_block_report_url][ 196]:Report 1 url, Total_size:126
9-> :[                    free_url][ 313]:FREE pkt url
2-> :[                get_abs_path][  72]:uri_len: 232 abs_uri:/getsharenum?urls=17091797201692772740,11532546021778491826,4607969594987258370,13371752734895889225,5427010760400390956,3331117510697159647,17352347182496212156,17499921033298219140,2856178610194949267&callback=bds.se.like.giveData
3-> :[             dpim_decode_url][ 181]:URL:s1.bdstatic.com/r/www/cache/static/global/js/common_5955eef4.js
5-> :[                     fmt_add][ 475]:url_addr 0xd52df9f0 
2-> :[                get_abs_path][  91]:Host_len: 19 Host:api.share.baidu.com
4-> :[                get_abs_path][  72]:uri_len: 48 abs_uri:/r/www/cache/static/global/js/common_5955eef4.js
7-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
4-> :[                get_abs_path][  91]:Host_len: 15 Host:s1.bdstatic.com
7-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
8-> :[        url_block_report_url][ 198]:Fmt delete wqe push
5-> :[                     fmt_add][ 477]:find old url_addr
2-> :[                get_abs_path][ 108]:str_len: 251 Host:api.share.baidu.com/getsharenum?urls=17091797201692772740,11532546021778491826,4607969594987258370,13371752734895889225,5427010760400390956,3331117510697159647,17352347182496212156,17499921033298219140,2856178610194949267&callback=bds.se.like.giveData
5-> :[             link_url_to_fmt][ 232]:Compare: www.baidu.com/img/baidu_jgylogo3.gif www.baidu.com/img/baidu_jgylogo3.gif
4-> :[                get_abs_path][ 108]:str_len: 63 Host:s1.bdstatic.com/r/www/cache/static/global/js/common_5955eef4.js
8-> :[           zxmd_main_process][  88]:Get fmt aged wqe
4-> :[             dpim_decode_url][ 181]:URL:s1.bdstatic.com/r/www/cache/static/global/js/common_5955eef4.js
2-> :[             dpim_decode_url][ 181]:URL:api.share.baidu.com/getsharenum?urls=17091797201692772740,11532546021778491826,4607969594987258370,13371752734895889225,5427010760400390956,3331117510697159647,17352347182496212156,17499921033298219140,2856178610194949267&callback=bds.se.like.giveData
7-> :[                    free_url][ 313]:FREE pkt url
8-> :[           free_url_from_fmt][ 253]:Free one url success
2-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
5-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
1-> :[             fmt_stat_report][ 295]:fmt report eif:0
4-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
9-> :[             fmt_stat_report][ 295]:fmt report eif:0
4-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
2-> :[                    free_url][ 313]:FREE pkt url
9-> :[        url_block_report_url][ 196]:Report 1 url, Total_size:107
1-> :[        url_block_report_url][ 196]:Report 2 url, Total_size:396
5-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
9-> :[        url_block_report_url][ 198]:Fmt delete wqe push
3-> :[     _zxmd_url_block_process][ 701]:access log vlantag_out:2032
5-> :[                    free_url][ 313]:FREE pkt url
4-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
3-> :[                     fmt_add][ 470]:add a new url into fmt
4-> :[                    free_url][ 313]:FREE pkt url
2-> :[           zxmd_main_process][  88]:Get fmt aged wqe
3-> :[                     fmt_add][ 475]:url_addr 0x0 
1-> :[        url_block_report_url][ 198]:Fmt delete wqe push
2-> :[           free_url_from_fmt][ 253]:Free one url success
4-> :[           zxmd_main_process][  88]:Get fmt aged wqe
3-> :[                 cp_and_link][ 187]:get url str for fmt s1.bdstatic.com/r/www/cache/static/global/js/common_5955eef4.js
6-> :[                     fmt_add][ 470]:add a new url into fmt
3-> :[               eprm_xmit_pkt][ 268]:old vlan:4033
6-> :[                     fmt_add][ 475]:url_addr 0xd52df9f0 
3-> :[               eprm_xmit_pkt][ 271]:new vlan:12225
6-> :[                     fmt_add][ 477]:find old url_addr
3-> :[                    free_url][ 313]:FREE pkt url
6-> :[             link_url_to_fmt][ 232]:Compare: www.baidu.com/img/baidu_jgylogo3.gif www.baidu.com/img/baidu_jgylogo3.gif
```




set sregister url_block send_log enable
set sregister 3gpp enable
set sregister packetio enable
set sregister fmt_manage send_stat enable

set sregister url_block send_log disable
set sregister 3gpp disable
set sregister packetio disable

# 测试并发
1-> Assertion failed:/home/sqm/tmp/JusonFlow/libexec/dpim/zxmx_url.h,line 262

| 16:50 - 17:00 | 实时日志没有命中，发送访问日志.  |
| 17:02 - 17:20 | 添加命中的url，此时发送阻断日志. |
| 17:20 - 17:40 | 添加命中的url，此时发送RST报文.  |

# 测试发包情况下配置
| 18:00 - 18:20 | 添加命中的url，此时发送RST报文. |

GET /s?wd=url%E7%A9%BA%20&rsv_spt=1%20&issp=%%20201&rsv_bp=0&ie=u%20tf-8&tn=ba%20iduho%20%20%20%20%20%20me_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90 HTTP/1.1\r\n

1-> :[   check_ethhdr_and_set_ipif][ 959]:pkt in port:1
1-> :[             dpim_decode_tcp][ 643]:Get pkt:0x474554202f733f77
1-> :[             dpim_decode_tcp][ 646]:Get a url pkt
1-> :[             dpim_decode_url][ 253]:To process abs_path
1-> :[                get_abs_path][ 134]:uri_len: 111 abs_uri:/s?wd=urlw1&rsv_spt=1&issp=r0201&rsv_bp=0&ie=utf-8&tn=baiduhome_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
1-> :[                get_abs_path][ 164]:Host_len: 13 Host:www.baidu.com
1->   77  77  77  2e  62  61  69  64  75  2e  63  6f  6d  2f  73  3f  77  64  3d  75  72  6c  77  19  31  26  72  73  76  5f  73  70  74  3d  31  26  69  73  73  70  3d  72  30  32  30  31  26  72  73  76  5f  62  70  3d  30  26  69  65  3d  75  74  66  2d  38  26  74  6e  3d  62  61  69  64  75  68  6f  6d  65  5f  70  67  26  72  73  76  5f  73  75  67  33  3d  32  26  72  73  76  5f  73  75  67  3d  30  26  72  73  76  5f  73  75  67  31  3d  32  26  72  73  76  5f  73  75  67  34  3d  39  30:[             dpim_decode_url][ 264]:URL:www.baidu.com/s?wd=urlw1&rsv_spt=1&issp=r0201&rsv_bp=0&ie=utf-8&tn=baiduhome_pg&rsv_sug3=2&rsv_sug=0&rsv_sug1=2&rsv_sug4=90
1-> :[                    free_url][ 100]:FREE pkt url
]]]]]]]]]]]]]]]]



1-> :[    zxmx_url_conf_by_bootmem][  81]:Get a linux command

url: err.taobao.com/error1.html
action:drop

juson(config-cpu0)# 1-> :[   check_ethhdr_and_set_ipif][ 959]:pkt in port:1
1-> :[             dpim_decode_tcp][ 643]:Get pkt:0x474554202f657272
1-> :[             dpim_decode_tcp][ 646]:Get a url pkt
1-> :[             dpim_decode_url][ 261]:To process abs_path
1-> :[                get_abs_path][ 148]:uri_len: 12 abs_uri:/error1.html
1-> :[                get_abs_path][ 177]:Host_len: 14 Host:err.taobao.com
1-> :[             dpim_decode_url][ 272]:URL:err.taobao.com/error1.html
1-> :[     _zxmd_url_block_process][ 757]:Hit url 1385274
1-> :[           url_block_add_fmt][ 101]:fmt vlanout:2032
1-> :[           url_block_add_fmt][ 103]:url: err.taobao.com/error1.html
1-> :[             add_fmt_for_pkt][ 374]:url: err.taobao.com/error1.html
1-> :[                     fmt_add][ 390]:url: err.taobao.com/error1.html
1-> :[                    free_url][ 110]:FREE pkt url
1-> :[   check_ethhdr_and_set_ipif][ 959]:pkt in port:1
1-> :[                    free_url][ 110]:FREE pkt url
1-> :[   check_ethhdr_and_set_ipif][ 959]:pkt in port:1
1-> :[                    free_url][ 110]:FREE pkt url
1-> :[   check_ethhdr_and_set_ipif][ 959]:pkt in port:1
1-> :[                    free_url][ 110]:FREE pkt url
1-> :[   check_ethhdr_and_set_ipif][ 959]:pkt in port:1
1-> :[                    free_url][ 110]:FREE pkt url
1-> :[   check_ethhdr_and_set_ipif][ 959]:pkt in port:1

1-> :[             dpim_decode_tcp][ 643]:Get pkt:0x474554202f657272
1-> :[             dpim_decode_tcp][ 646]:Get a url pkt
1-> :[             dpim_decode_url][ 261]:To process abs_path
2-> :[   check_ethhdr_and_set_ipif][ 959]:pkt in port:1
1-> :[                get_abs_path][ 148]:uri_len: 12 abs_uri:/error1.html
2-> :[             dpim_decode_tcp][ 643]:Get pkt:0x474554202f657272
1-> :[                get_abs_path][ 177]:Host_len: 14 Host:err.taobao.com
2-> :[             dpim_decode_tcp][ 646]:Get a url pkt
1-> :[             dpim_decode_url][ 272]:URL:err.taobao.com/error1.html
2-> :[             dpim_decode_url][ 261]:To process abs_path
1-> :[     _zxmd_url_block_process][ 757]:Hit url 1385274
2-> :[                get_abs_path][ 148]:uri_len: 12 abs_uri:/error1.html
1-> :[           url_block_add_fmt][ 101]:fmt vlanout:2032
2-> :[                get_abs_path][ 177]:Host_len: 14 Host:err.taobao.com
1-> :[           url_block_add_fmt][ 103]:url: err.taobao.com/error1.html
2-> :[             dpim_decode_url][ 272]:URL:err.taobao.com/error1.html
1-> :[             add_fmt_for_pkt][ 374]:url: err.taobao.com/error1.html
2-> :[     _zxmd_url_block_process][ 757]:Hit url 1385274
1-> :[                     fmt_add][ 390]:url: err.taobao.com/error1.html
2-> :[           url_block_add_fmt][ 101]:fmt vlanout:2032
1-> :[                     fmt_add][ 480]:add a new url into fmt
2-> :[           url_block_add_fmt][ 103]:url: err.taobao.com/error1.html
1-> :[                     fmt_add][ 485]:url_addr 0x0 
2-> :[             add_fmt_for_pkt][ 374]:url: err.taobao.com/error1.html
1-> :[                 cp_and_link][ 278]:get url str for fmt err.taobao.com/error1.html
2-> :[                     fmt_add][ 390]:url: err.taobao.com/error1.html
1-> :[                    free_url][ 110]:FREE pkt url
2-> :[                     fmt_add][ 480]:add a new url into fmt
2-> :[                     fmt_add][ 485]:url_addr 0xda7e8a30 
2-> :[                     fmt_add][ 487]:find old url_addr
2-> :[             link_url_to_fmt][ 323]:Compare: err.taobao.com/error1.html err.taobao.com/error1.html
2-> :[                    free_url][ 110]:FREE pkt url
1-> :[   check_ethhdr_and_set_ipif][ 959]:pkt in port:1
1-> :[                    free_url][ 110]:FREE pkt url


---------1010101010101010101010---------
tcpreplay [[-i]] eth6 -l 1 128B_GET_A.pcap
add url_block analy.qq.com/Affffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff action=drop

set sregister packetio enable
set sregister fmt_manage send_stat enable
set sregister fmt_manage stat_eif 0
set sregister url_block_eif 0 
add outgroup 0 16
delete outgroup 0 0


Environment size: 1074/131068 bytes
Dream 6645 box # set serverip<INTERRUPT>
Dream 6645 box # ping 10.10.168.178
Using octmgmt0 device
ping failed; host 10.10.168.178 is not alive
Dream 6645 box # ping 10.10.168.178
Using octmgmt0 device
ping failed; host 10.10.168.178 is not alive
Dream 6645 box # set ipaddr=10.10.168.82
Unknown command 'set' - try 'help'
Dream 6645 box # help
?           - alias for 'help'
askenv      - get environment variables from stdin
base        - print or set address offset
base64      - print or set 64-bit address offset
bdinfo      - print Board Info structure
bootelf     - Boot from an ELF image in memory
bootloaderunlzma- UN-LZMA the bootloader image
bootloaderupdate- Update the bootloader in flash
bootloadervalidate- Validate the bootloader image
bootm       - boot application image from memory
bootoct     - Boot from an Octeon Executive ELF image in memory
bootoctelf  - Boot a generic ELF image in memory. NOTE: This command does not
              support simple executive applications, use bootoct for those.
bootoctlinux- Boot from a linux ELF image in memory
bootp       - boot image via network using BOOTP/TFTP protocol
bootvx      - Boot vxWorks from an ELF image
bypass      - DM6335C or DM6645C Copper Bypass sub-system

cdp         - Perform CDP network configuration
chpart      - change active partition
cmp         - memory compare
coninfo     - print console devices and information
cp          - memory copy
crc32       - checksum calculation
detect      - detect FLASH chip
dhcp        - boot image via network using DHCP/TFTP protocol
dns         - lookup the IP of a hostname
echo        - echo args to console
editenv     - edit environment variable
eeprom      - EEPROM sub-system
env         - environment handling commands
erase       - erase FLASH memory
eraseenv    - erase the environment in flash
fdt         - flattened device tree utility commands
flinfo      - print FLASH memory information
flush_dcache- Flushes and invalidates the data cache
flush_l2c   - Flushes the L2 cache
freeprint   - Print list of free bootmem blocks
go          - start application at address 'addr'
gpio        - Octeon GPIO rx/tx function

gunzip      - unzip a memory region (deprecated, use unzip instead)
help        - print command description/usage
i2c         - I2C sub-system
imxtract    - extract a part of a multi-image
inv_icache  - Invalidates the instruction cache
itest       - return true/false on integer compare
loadb       - load binary file over serial line (kermit mode)
loads       - load S-Record file over serial line
loady       - load binary file over serial line (ymodem mode)
loop        - infinite loop on address range
md          - memory display
md5sum      - compute MD5 message digest
mii         - MII utility commands
mm          - memory modify (auto-incrementing address)
mtdparts    - define flash/nand partitions
mtest       - simple RAM read/write test
mw          - memory write (fill)
namedalloc  - Allocate a named bootmem block
namedfree   - Free a named bootmem block
namedprint  - Print list of named bootmem blocks
nfs         - boot image via network using NFS protocol
nm          - memory modify (constant address)
nmi         - Generate a non-maskable interrupt
octreginfo  - print register information
pci         - list and access PCI Configuration Space
ping        - send ICMP ECHO_REQUEST to network host
printenv    - print environment variables
protect     - enable or disable FLASH write protection
qlm         - Octeon QLM debug function (dangerous - remove from final product)
read64      - read 64 bit word from 64 bit address
read64b     - read 8 bit word from 64 bit address
read64l     - read 32 bit word from 64 bit address
read64s     - read 16 bit word from 64 bit address
reset       - Perform RESET of the CPU
run         - run commands in an environment variable
saveenv     - save environment variables to persistent storage
saves       - save S-Record file over serial line
setenv      - set environment variables
setexpr     - set environment variable as the result of eval expression
sha1sum     - compute SHA1 message digest
sleep       - delay execution for some time
source      - run script from memory
strings     - display strings
tftpboot    - boot image via network using TFTP protocol
tlv_eeprom  - EEPROM data parsing
unzip       - unzip a memory region
upgrade     - upgrade FLASH data
version     - print monitor, compiler and linker version
write64     - write 64 bit word to 64 bit address
write64b    - write 8 bit word to 64 bit address
write64l    - write 32 bit word to 64 bit address
write64s    - write 16 bit word to 64 bit address



====================
root@juson:~# PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  
PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  
PP1:~CONSOLE-> ffff ffff ffff ffff ffff ffff 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 10 01 48 00 00  00 00 ff80 11 39 ff96 00 00 
PP1:~CONSOLE-> 00 00 ffff ffff ffff ffff 00 44  00 43 01 34 3f ffb0 01 01 
PP1:~CONSOLE-> 06 00 ff8a ffea ffab 3a 00 03  

root@juson:~# PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  

root@juson:~# PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  

root@juson:~# PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  

root@juson:~# PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  

root@juson:~# PP1:~CONSOLE-> ffff ffff ffff ffff ffff ffff 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 10 01 48 00 00  00 00 ff80 11 39 ff96 00 00 
PP1:~CONSOLE-> 00 00 ffff ffff ffff ffff 00 44  00 43 01 34 3f ffac 01 01 
PP1:~CONSOLE-> 06 00 ff8a ffea ffab 3a 00 07  
PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  
PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  

root@juson:~# PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  
PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  
PP1:~CONSOLE-> ffec 17 2f fff2 ffd7 ffb5 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 00 05 2f ffdd 10  40 00 40 06 ffbe fff7 0a 0a 
PP1:~CONSOLE-> ffa8 ffb2 3d ff87 ffa9 7d ff9d 06  00 50 18 26 ffa4 28 7e 74 
PP1:~CONSOLE-> 5c 45 50 18 39 08 ff9e ffe2  
PP1:~CONSOLE-> ffff ffff ffff ffff ffff ffff 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 10 01 48 00 00  00 00 ff80 11 39 ff96 00 00 
PP1:~CONSOLE-> 00 00 ffff ffff ffff ffff 00 44  00 43 01 34 3f ffa3 01 01 
PP1:~CONSOLE-> 06 00 ff8a ffea ffab 3a 00 10  
PP1:~CONSOLE-> 00 03 00 00 00 00 00 00  ffff ffff ffff ff81 ff81 00 2f ffc1 
PP1:~CONSOLE-> ff92 00 01 01 00 00 00 00  ff90 03 00 01 02 03 04 05 
PP1:~CONSOLE-> 06 07 08 09 0a 0b 0c 0d  0e 0f 10 11 12 13 14 15 
PP1:~CONSOLE-> 16 02 18 19 1a 1b 1c 1d  
PP1:~CONSOLE-> 00 03 00 00 00 00 00 00  ffff ffff ffff ff81 ff81 00 2f ffc1 
PP1:~CONSOLE-> ff92 00 01 01 00 00 00 00  ff90 03 00 01 02 03 04 05 
PP1:~CONSOLE-> 06 07 08 09 0a 0b 0c 0d  0e 0f 10 11 12 13 14 15 
PP1:~CONSOLE-> 16 02 18 19 1a 1b 1c 1d  

root@juson:~# PP1:~CONSOLE-> 00 03 00 00 00 00 00 00  ffff ffff ffff ff81 ff81 00 2f ffc1 
PP1:~CONSOLE-> ff92 00 01 01 00 00 00 00  ff90 03 00 01 02 03 04 05 
PP1:~CONSOLE-> 06 07 08 09 0a 0b 0c 0d  0e 0f 10 11 12 13 14 15 
PP1:~CONSOLE-> 16 02 18 19 1a 1b 1c 1d  

root@juson:~# PP1:~CONSOLE-> 00 03 00 00 00 00 00 00  ffff ffff ffff ff81 ff81 00 2f ffc1 
PP1:~CONSOLE-> ff92 00 01 01 00 00 00 00  ff90 03 00 01 02 03 04 05 
PP1:~CONSOLE-> 06 07 08 09 0a 0b 0c 0d  0e 0f 10 11 12 13 14 15 
PP1:~CONSOLE-> 16 02 18 19 1a 1b 1c 1d  

root@juson:~# PP1:~CONSOLE-> 00 03 00 00 00 00 00 00  ffff ffff ffff ff81 ff81 00 2f ffc1 
PP1:~CONSOLE-> ff92 00 01 01 00 00 00 00  ff90 03 00 01 02 03 04 05 
PP1:~CONSOLE-> 06 07 08 09 0a 0b 0c 0d  0e 0f 10 11 12 13 14 15 
PP1:~CONSOLE-> 16 02 18 19 1a 1b 1c 1d  

root@juson:~# PP1:~CONSOLE-> 00 03 00 00 00 00 00 00  ffff ffff ffff ff81 ff81 00 2f ffc1 
PP1:~CONSOLE-> ff92 00 01 01 00 00 00 00  ff90 03 00 01 02 03 04 05 
PP1:~CONSOLE-> 06 07 08 09 0a 0b 0c 0d  0e 0f 10 11 12 13 14 15 
PP1:~CONSOLE-> 16 02 18 19 1a 1b 1c 1d  





PP1:~CONSOLE-> ffff ffff ffff ffff ffff ffff 04 7d  7b 5f 2f ffca ff81 00 2f ffc1 
PP1:~CONSOLE-> 08 00 45 10 01 48 00 00  00 00 ff80 11 39 ff96 00 00 
PP1:~CONSOLE-> 00 00 ffff ffff ffff ffff 00 44  00 43 01 34 3f ff9a 01 01 
PP1:~CONSOLE-> 06 00 ff8a ffea ffab 3a 00 19  


ROR PEMX_INT_SUM(0)[SE]: System Error, RC Mode Only.])

		export OCTEON_REMOTE_PROTOCOL=linux
		/mnt/oct-remote-csr PEM0_INT_ENB 0x0000000000003bf0
		
juson(config-cpu0)# 
PP1:~CONSOLE-> out grp 63
PP1:~CONSOLE-> out id 0
PP1:~CONSOLE-> vlan id fbf
PP1:~CONSOLE-> new_vlan_id fbf

juson(config-cpu0)# add ruleset int aclmask 0 sip=10.10.168.178/24-10.10.169.244/24,action=forward,slotgroup=0,outgroup=2
add aclmask successful

juson(config-cpu0)# sync ruleset int aclmask 
sync aclmask successful


juson(config-cpu0)# show ruleset int aclmask 0 

 ruleset: [int] aclmask configuration
	 aclmask[0]: pri=0,aging=0,sip=10.10.168.178/24-10.10.169.244/24,dip=0.0.0.0/0,sport=0-65535,dport=0-65535,protocol=any,action=forward,fmt_add=disable,reverse=disable,slotgroup=0,outgroup=2
	 Flag_Enable: 1	 Flag_Sync: 1

juson(config-cpu0)#
PP1:~CONSOLE-> out grp 2
PP1:~CONSOLE-> out id 0
PP1:~CONSOLE-> vlan id fbf
PP1:~CONSOLE-> new_vlan_id fbf
PP1:~CONSOLE-> 2 new vlan fbf

juson(config-cpu0)# PP1:~CONSOLE-> out grp 2
PP1:~CONSOLE-> bal 4168240 num 1 id 0
PP1:~CONSOLE-> vlan id fbf
PP1:~CONSOLE-> new_vlan_id fbf
PP1:~CONSOLE-> 2 new vlan fbf

