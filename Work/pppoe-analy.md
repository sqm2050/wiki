# PPPoE
## PPPoE入口
以太网协议号：PPPoE发现阶段 `0x8863`, PPPoE会话阶段`0x8864`
PPPoE协议号：`0xc223`CHAP报文,`0xc023`PAP报文,`0xc021`LCP报文。

## PPPoE分析模块
1. 在确定是PPPoE报文之后，获得$源MAC$，$目的MAC$，$会话ID$。
2. PAP报文，只提取请求报文中$用户名$，不等待验证确认报文。
3. CHAP报文，只提取响应报文中$用户名$，不等待验证成功报文。

## PPPoE存储模块
利用分析模块提取的元素，建立存储结构。
$源MAC$，$目的MAC$，$会话ID$作为索引，和查找条件。
超时时间`120`分钟，检查时间`1`分钟。

## PPPoE提取
利用`源、目的MAC`、`会话ID`.查找存储模块建立的表，第一次没有查到，反方向再次查找。

## 节点删除 
1. 根据PADT包（发现终止包-PPPoE Active Discovery Terminate）
2. 根据PPP-LCP终止消息

## 节点时间更新
1. 相应的IP报文经过
2. 相应的回音响应报文经过
## PPPoE打印
打印结构：
`9100`(2 octets), `tot_len`(1 octet), `user_name`(0 ~ 50)
