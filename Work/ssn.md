# SSN
## 结构
`ssn_t`中包含两个`fmt_t`,用于保存双向的信息。

## 逻辑
### flow_find(dpp)
首先计算两个方向的哈希值,获取两个哈希桶的头部。 头部结构：
```
	typedef struct {
			uint64_t next;
			cvmx_spinlock_t lock;
	} ssn_idx_t;
```

加锁时候因为要加上两个桶的锁，为了保证顺序，加之前增加了判断，判断两个锁的地址：
```
static inline void ssn_order_lock(cvmx_spinlock_t *l0, cvmx_spinlock_t *l1)
{
	if (l0 < l1) {
		cvmx_spinlock_lock(l0);
		cvmx_spinlock_lock(l1);
	} else if (l0 > l1) {
		cvmx_spinlock_lock(l1);
		cvmx_spinlock_lock(l0);
	} else {
		cvmx_spinlock_lock(l0);
	}
}
```

`flow_t`里面保存的是前后节点的物理地址-uint64，所以通过头部或其他节点获得后续节点的时候必须作转换：
```
static inline flow_t *flow_next(flow_t *fl)
{
	if (fl->next)
		return cvmx_phys_to_ptr(fl->next);
	return NULL;
}

fl = flow_next((void *)h0);
```
* 这里连`ssn_idx_t *h0`都强转成`flow_t`类型了，恰巧`next`成员在两个结构中的偏移一样。

* 还有se因为是1_to_1映射所以下面一直使用的物理地址，这里做转换是为了以后兼容。而且使用物理地址后，在其他核的linux上也可以转后去操作。
 


