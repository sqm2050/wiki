/**
 * 使用头指针的双向链表
 */

/* 头指针 */
typedef struct {
	void	*next;
	union {
		spinlock_t	spinlock;
		wp_lock_t	rwlock;
	};
} hash_list_head_t;

/* 节点-链地址 */
typedef struct {
	void	*next;
	void	*prev;
} hash_list_t;

/* 在头部插入 */
static inline void
hash_list_link(hash_list_head_t *h, hash_list_t *p)
{
	/* 保存第一个节点指针 */
	hash_list_t *next = h->next;

	/* 插入p */
	h->next = p;

	/* 节点p，list地址赋值 */
	p->next = next;
	p->prev = h;

	/* 设定next节点的前一节点为p */
	if (next)
		next->prev = p;
}

static inline void
hash_list_unlink(hash_list_t *n)
{
	/* 保存前后节点指针 */
	hash_list_t *prev = n->prev;
	hash_list_t *next = n->next;

	/* 前节点指向后节点 */
	prev->next = n->next;

	/* 设定next节点的前一节点为n的前节点 */
	if (next)
		next->prev = n->prev;
}
