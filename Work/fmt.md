fmt位域图:

![image text](Work/fmt_field.png)

## hash table
初始化了桶个数为`0x400000`的哈希表，每个桶长度是2。这样每个桶正好占用一个`cacheline`
```
    #define FMT_HEAD_SIZE 0x400000
```

## vlan
流管理报文的vlan起始设置为2。
```
    #define FMT_API_FLOW_PKT_VLAN_BEGIN	2
```
报文进入首先检查vlan(第一个vlan字段)号码是否属于流管理报文，如是流管理报文的vlan范围，检查报文类型是否正确，如果冲突drop报文。
```
    dpim_decode_pre:
    if((eth->tag >= FMT_API_FLOW_PKT_VLAN_BEGIN) && \
		(eth->tag < (FMT_API_FLOW_PKT_VLAN_BEGIN +ZXMX_MAX_IPIF_NUM)))
    if(cvmx_unlikely(ctl->flow.proto != ETH_P_FMT))	/* 9003 */
```
判断流表报文的第16位的值决定是什么行为0 read, 1 write
```
	if (ctl->hdr.cmd) {
        fmt_set((md_fmt_t *)(&ctl->flow));
    } else {
        fmt_search();
    }

```
### fmt_add
fmt_head是全局的为什么还要作为函数参数。
```
/* refresh the action */
fl->k.act = fkey->act;  
```

### fmt_set(md_fmt_t *src)
报文中第3个32字中的前25位是idx，

### fmt_search
如果送进来的idx是invalid的（0x1ffffff），那么需要自己计算。

定位到相应的桶然后查看第一个元素：
```
    fl = &fmt_head[*hash].h[0];
```
如果第一个不匹配，那么继续处理：
```
    #define SUF_MASK_R(x)	(~0UL << (x)) /**< 把64位0变成64四位1，然后左移x位 */
    /**
     * 提取64位的指针的前48位，并把把48位置1.后面置0
     */
    static inline md_fmt_t *fmt_slave(md_fmt_t * f)
    {
        return (md_fmt_t *) (((u64) f & SUF_MASK_R(6)) | (1 << 6));
    }
    /**
     * 
    static inline md_fmt_t fmt_next(md_fmt_t *f)
    {
        if (fmt_slave(f)->list & SUF_MASK_R(7))
            return cvmx_phys_to_ptr(fmt_slave(f)->list & SUF_MASK_R(7));
        else
            return NULL;
    }
```
### 流表结构
URL阻断作为一个URL_BLOCK和HFA都会实现的功能，即hfa可以去做url匹配（在url被解析到的情况下）。所以对于流表结构有两种情况会更改:
* 一是打开url总功能开关，用于保存url
* 二是reset报文发送后的计数和reset开关，其他模块也能在旁路情况下发送reset
 
而url、reset更改同一个位域，所以他们的开关组合成两成4种情况(2^n).

注意pkts一定放在最后面，因为fmt_add时候，初始化一个流表entry时候，用`|0x01`进行的初始化报文数。

### 流表和acl配置的实时性
> 增加了一个`real_mode`开关
#### real_mode开启情况下
* 对于命中流表`drop`行为的报文，执行`drop`，退出
* 对于命中流表`forward`行为的报文，继续走下面acl路径，acl模块更新fmt(`forward->drop`)的行为和出接口。
* 为什么这么做，而不是`drop`行为的继续:
	* 实时性要求高的是转发行为的（相比较于drop的）
	* 被`drop`的流会被阻断，建立新的流表
	* 可以开启实时后进行配置，然后一段时间(流老化时间)后,关闭实时开关恢复性能

## 其他模块与fmt模块之间位置
