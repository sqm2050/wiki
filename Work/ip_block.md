## IP Block

### 模块位置
IP Port模块都可以放在FMT模块之前，因为查找速度比五元组要快的。

### 快速查找结构
#### IP Trie树
Trie树： _256*4_ 的树,叉值是 _256_ ，深度是 _4_ 
最坏空间是:
```
256 + 256^2 + 256^3 + 256^4 = 4311810304

2^32 = 4294967296
```
相比全部存储还要大，所以不敢冒险使用。
* 叉树越大，觉接近于 _2^32_ 的内存大小。
* 前缀越紧凑越有效，可以用作地址分类时候(即网络地址相同)

#### 哈希结构
32位int型数据CRC计算，66盒子，1000W次，花费1 1000 0014 个时钟周期，平均一个花费10个时钟

使用哈希结构。
> 模块关闭打开，和模块优先级切换，详见<a href="block_switch.html"><font color=#d14>block switch</font></a>

## ip_block接口
### 文件1 mduapi/src/ip_block/mduapi_ip_block.h
错误号：
```
#define MDUAPI_IP_BLOCK_RET_BEGIN 270
#define MDUAPI_IP_BLOCK_RET_END   279
```
### 添加ip规则
暂时只支持`drop，forward`两个行为, 没有与 _fmt_ 相关，即没有访问日志、加流表项等动作.

也没有添加`rst`动作.
> `rst`针对于旁路 _tcp_ 连接

结构体:
```
typedef struct _ip_block_rule {
	comm_tgt	common;
	uint16_t	cmd;
	uint32_t	ip;
} __attribute__((packed)) ip_block_rule;
```
两个 *行为* 添加在`common`中:
```
enum {
	IP_BLOCK_FORWARD = ACT_FWD,
	IP_BLOCK_DROP = ACT_DROP,
};
```

命令支持 *添加、删除、清除、查询* :
```
enum {
	IP_CMD_SUC = 0,	/* must be 0 */
	IP_CMD_ADD,
	IP_CMD_DEL,
	IP_CMD_CLR,
	IP_CMD_GET,
	IP_CMD_FAIL = 0xff,
};
int mduapi_ip_block_rule(ip_block_rule *rule);
int mduapi_ip_block_clr();
```
## 业务口管理报文
### 报文结构图:
> 和url相同
<img src="url.png">

### 模块类型：
file: libexec/common/include/zxmx_common.h
```
enum{
	CTL_URL_BLOCK = 0,
	CTL_FMT,
	CTL_SSN,
	CTL_IP_BLOCK,
};
```

### 命令
file: mduapi/src/ip_block/mduapi_ip_block.h
```
enum {
	IP_CMD_SUC = 0,	/* must be 0 */
	IP_CMD_ADD,
	IP_CMD_DEL,
	IP_CMD_CLR,
	IP_CMD_GET,
	IP_CMD_FAIL = 0xff,
};
```
### 行为 
file: mduapi/src/ip_block/mduapi_ip_block.h
```
/* action */
enum {
	IP_BLOCK_FORWARD = ACT_FWD,
	IP_BLOCK_DROP = ACT_DROP,
};
```
