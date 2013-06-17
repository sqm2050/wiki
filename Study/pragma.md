## 结构中有数组、结构体、结构体数组的对齐方式
32位:
```
A. struct P1 { short a[3]; char b[3]; };//6+3 = 9 然后9按照2对齐 =10
B. struct P2 { short a[3]; char *b[3]; }; //6+4*3=18 按照4对齐=20
C. struct P3 { struct P2 *a; char b; struct P1 a[2]; };//4+1+2*10=25  按照4对齐到28
```
64位再例:
```
typedef struct __url_entry{
	char *url;
	uint32_t act:3,
		 rst_en:1,
		 fwd_grp:6,
		 _rsv:22;
}url_entry;

typedef struct _url_block{
	url_entry entry[7];
	struct _url_block *next;
}url_block;
```
上面第一个结构体大小是`16`位（指针类型`8`位---按照此大小对齐）.第二个结构体大小是`120(16 * 7 + 8)`,所以不是按照本结构中的成员的组合类型的大小对齐,而是基本类型中最大的.
第一个数组按照数组类型大小进行排列:`16 * 7 = 112`;正好是`8`位对齐的,后面的指针也就紧挨着排列,整个结构体大小是`120`.

> 在第二个结构体中已经说明结构体数组是按照结构体的大小进行排列的
```
url_block arr[3];
&arr[0];	0
&arr[1];	120
&arr[2];	240
```
数组都是按照结构体类型大小进行排列的.
