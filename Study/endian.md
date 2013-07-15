如果只要分析一部分，只需要使用正常结构体，swap要用的那一部分

如果涉及到位域，那么一定要先做swap，并做结构体倒置

大端：
地址：[00000000][00000001][00000002][00000003]
数据：|abbcccdd||ddeeeeef||fffffggg||gggggggg|
小端：
地址：[00000000][00000001][00000002][00000003]
数据：|ddcccbba||feeeeedd||gggfffff||gggggggg|

```
#include <stdio.h>
#include <stdint.h>
void prt_bin(char *p, int len)
{
	int i, j;
	for (i = 0; i < len; i++) {
		for (j = 7; j >= 0; j--) {
			printf("%d", *p >> j & 0x01);
		}
		p++;
		printf(" ");
	}
	printf("\n");
}
main()
{
	union {
		struct {
			uint16_t a:1,
				b:3,
				c:6,
				d:6;
		};
		uint16_t data;
	}__attribute__((aligned(8))) little;

	little.a = 1;		/* 1 	*/
	little.b = 1;		/* 001	*/
	little.c = 0x2b;	/* 101011 */
	little.d = 0x38;	/* 111000 */

	printf("%#x\n", little.data);
	prt_bin((char *)&little, 2);
}
```
result:

> 0xe2b3
> 10110011 11100010 
位图：|ccccbbba|ddddddcc|
BIG：|ddddddcc|ccccbbba|

```
struct {
		uint16_t d:6,
				c:6,
				b:3,
				a:1;
};
```
}
