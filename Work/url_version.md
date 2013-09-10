# URL版本
## url提取

### 不同形式url的统一、最简解义
* host后面的`%20`应该简化
* 大小写统一

### 发现一个tcp报文中可能会有多个http get的报文:
* 解析时候要全部解析
* dpp结构里面要加上组织成链表添加url
* 匹配时候要多次进行查找
```
    struct url_str {
    	struct url_str	*next;
    	char 			*str;
    };
```

### 字符串隐晦规则
字符串长度,数组和字符串常量最后一位都是0x00，printf(%s)通过这个进行判断,内存所以比实际长度长一位：
```
    char tmp[] = "abcd";	/* sizeof = 5,最后一位是0x00 */
    char tmp_1[4] = "abcd"; /* sizeof = 4,打印字符串最后有乱码 */
    char *p = "abcd";		/* sizeof = 8,地址占用的长度。不清楚字符串常量长度怎么确定，有人说和tmp[]相似 */
```
就是说字符串存储默认在最后一位留下`0x00`作为结束符，也方便使用库函数（printf、strlen）等函数处理。

### 绝对URL abs_url：
```
    http://www.---
```

### 绝对路径 abs_path：
```
    /s?get=adad&dadad
```
url起始位置：不带着`http://`

cvmx_malloc: 内存申请size可否是0.

### void *ptr = str;无类型指针被赋值后，使用时可以进行强转后使用。
```
	struct {
			void *url;
	} dpp;
```

## 模块位置
模块按照分层的，结构还是分格---》最后称为网格结构。

## 日志系统
阻断日志实时的进行发送，不依赖于流表
访问日志是依赖流表原有的发送功能

### 访问日志开关和出口设置
```
juson(config-cpu0)# set sregister fmt_manage
ttlset               set fmt default aging time
stat_eif             set egress interface group that fmt stat packet will go with
send_stat            set enable of send fmt stat packet
```

## 删除url_block send_log 开关
作为访问日志的开关使用，没有删除

## 组织访问日志逻辑
### 流表结构添加新位域
<table>
	<tr>
		<td> zxmx_fmt_api.h </td>
		<td> fmt_key_t </td>
		<td> md_fmt_t </td>
	</tr>
</table>

```
	#ifndef CONFIG_URL_BLOCK                                              
                    pkts:40;    /* Total packets in Flow, RO */       
	#else                                                                 
                    bidir_en:1,                                       
                    rst_en:1,   /* reset flag */                      
                    rst_num:4,  /* the pkts after sent reset packet */
                    [[pkts:34;]]    /* Total packets in Flow, RO */       
	#endif                                                                
```
### 各个规则模块添加rst标志，定义一个通用的结构给各个规则模块

## vlan更改
66从掩码从6位变作5位

#### 30s-3min 没有发送访问日志(只在30s 3min发送访问日志)

> 30s-3min的那是建流表时候设置活动位，以后search的时候在把活动位置位，但是现在命中的报文被url模块给劫持了，活动位失效了，就不会这段时间就不会发送访问日志了（不过发没有命中的相同流报文可以激活活动位，再次发送访问日志）

保证30s-3min发送，在`fmt_add()` _find :exist_ 的地方设置`dyn = 1`；
强调性能，只在3min时候发送，在`fmt_timeout()` 30s检测地方，把判断`dyn == 1`然后发送的地方注释掉，在aged或ttl减到零时候发送
 
ttl在search_refresh处会被刷新fl->k.ttl = fl->k.ttl_set;

#### 发送10个或者10的倍数个相同报文，会发送两个日志(和30-3问题同时存在时候，在3min时候也会发送两个)

> 发送两个两个报文肯定是建立连个不同的流表，所以每个流表项才都会发送两个

> 观察发送出来的两个报文发现port结构位置的port位不对，一次是0，一次是1

* 09bf 0050  *0* 411 2200
* 09bf 0050  *1* 411 2200

定位到fmt_proto的枚举，往常在流表模块开启的时候dpp->fmt_proto在fmt_process中设置: `dpp->fmt_proto = FMT_PROTO_TCP;`

上面两个问题都是由于url模块加在流表模块之间，考虑不周全导致的问题。

## 性能-效率优化
#### URL解析优化
> 一开始每个http都动态一个url给dpp，因为要给留给后续fmt用。但是后来又有改动，fmt赋值一份儿过去，dpp的url生命周期跟随dpp结束。这样子，dpp的url就可以优化了。
* URL在dpp中的内存，可以不用动态申请，固定申请fpa给它，做一个指针数组。
* 尝试过使用静态内存-全局数组（地址`12000480`），但是pkt模块无法使用这块地址。
* 使用`cvmx_bootmem_alloc`的地址是`0x1230680`这时候，可以正常使用。


### 规则集
#### 分析

### 端口数据结构
#### 条目结构
```
struct _prot_act {
		struct _comm_tgt ctg;
}
```

### IP数据结构

### host数据结构


## BUG
### 内存一次申请,多次释放
在申请给流表的时候内存是一次申请，分别填充链表结构，字符串。然后把字符串地址赋给结构中的指针。但是释放的时候把指向结构的指针和结构中指向字符串的指针都去释放了。
```
	struct url_str {
			char *str;
			struct url_str *next;
	};
```

### 临时指针的使用
free链表的时候使用临时指针
```
static inline void free_url_from_fmt(md_fmt_t *f)
{
	ASSERT(f != NULL);
	struct url_str *p, *tmp;

	p = cvmx_phys_to_ptr(f->k.url_addr);
	f->k.url_addr = 0;
	while (p) {
		ZXMX_MODULE_DEBUG("URL_BLOCK","Free one url success\n");
		tmp = p;
		p = p->next;
		cvmx_free(tmp);
	}
}
```

### 数组越界更改上一级函数栈区
下一级函数:
```
static inline int set_xmit_arr(report_arr *array,struct url_str *head, 
	int maxlen)
{
	ASSERT(array != NULL && head != NULL);
	int len = 0;
	
	/* 这里array长度是15，bug之前没有限定len < maxlen */
	while(head != NULL && len < maxlen) {
		array->addr = head->str;
		array->size = strlen((char *)head->str) + 1;
		ZXMX_MODULE_DEBUG("URL_BLOCK","url%d:%d, %s\n",
				len, array->size , (char *)array->addr);
		head = head->next;
		array++;
		len++;
	}
	return len;
}
```
造成上上上级的函数中的临时锁变量被覆盖重写，在去unlock的时候是错的锁，然后死锁，有时候会是错误地址。

### FPA-cache没有写回
> 在测试哈希冲突下的性能的时候，cache没有写回，在下次cache miss的时候会造成读入错误的值。

桶内结构：
```
block {
		entry[7];
		block *next ;
};
```
依次(从头到尾)删除桶内entry，删除一个entry后要遍历到最后一个entry进行内存紧凑操作然后删除最后一个block，时候过一段时间链表内net指针又会恢复而且，entry也会恢复。

### 内存对齐引入的bug
申请了一个`128*N`的内存，里面每个节点也是`(128 - 8) / sizeof`长度的数组加上一个8字节的指针，所以这个潜意识也认为整个结构是128对齐的，在clear整个hash表的时候使用了`memset(ptr, 0x00, 128)`把下一个节点的值也给memset了.
```
memset(url_head + i, 0, URL_BLOCK_SIZE);
```
#### 使用共用体强制对齐：
```
#define CVMX_FPA_URL_POOL_SIZE              CVMX_FPA_POOL_1_SIZE
#define URL_BLOCK_SIZE 		CVMX_FPA_URL_POOL_SIZE
#define PER_BLOCK_ENTRY 	((URL_BLOCK_SIZE - 8) / sizeof(url_entry))

typedef struct __url_entry{
	char *url;
	uint32_t act:3,
		 rst_en:1,
		 fwd_grp:6,
		 _rsv:22;
}url_entry;

typedef union __url_block{
	struct {
		url_entry entry[PER_BLOCK_ENTRY];
		union __url_block *next;
	};
	uint8_t data[128];
}url_block;
```
