1.单个进程吞报文，单链表，没有锁，在尾节点添加，删除是起线程监视添加时间距现在
的时间，删除的位置是随机。线程循环遍历所有节点。双向循环链表。
问题：
	1). 线程遍历效率---> 多节点，多线程,sleep去操作。
	2). 没有锁保证链表完整 --->加锁
	    add:
		while( cur->nxt ){      
        	cur = cur->nxt; 
		}                       
		cur->nxt = tmp;         
		tmp->pre = cur;         
	    del:
		else if( cur->nxt == NULL ){  
			cur->pre->nxt = NULL; 
		}                             

	    error:（乱序执行，穷举）
		cur->nxt == NULL
		cur->nxt = tmp;         
		cur->pre->nxt = NULL; 
		tmp->pre = cur;         

2.单个进程吞报文，hash表，一个mutex ，俩个静态全区哈希桶。一个节点对应一个守护
线程，进行监视删除.
	1). 一个锁，影响hash表的效率
	2). 两个哈希桶，会误操作目的数据

3.单个进程吞报文，hash表，mutex全局数组，对应于hash 桶，在单向循环链表，在头指
针处插入。
	1). del:
		NODE *np = hashtab[hi];
		NODE *tmp;             
		while (1) {
			tmp = np;     
			np = np->next;
			if (del(np)) {
				tmp = np->next;	// 只改变了临时指针，
			}			// 应该是tmp->next = np->next;
		}
	2). 此时，删除已是多线程并发，所以，不能只注意首节点的操作冲突。进入这
	    个链就应该加锁了。

