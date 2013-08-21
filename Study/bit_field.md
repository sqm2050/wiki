```
#include <stdio.h>
#include <stdint.h>
void prt_bin(char *, int);
main()
{
	union {
		struct {
			uint16_t a:10,
				 b:4,
				 c:4,	/**< c是超出这个short类型的位域，放到下一个类型位域中了。
				 d:4;
		};
		uint32_t data;
	} dd;
	dd.data = 0; 		/**< 必须初始化位域 */
	dd.a = 0x3ff;
	dd.b = 0x8;
	dd.c = 0x9;
	dd.d = 0xf;

	printf("%#x\n", dd.data);
	printf("%#x\n", dd.b);
	printf("%#x\n", dd.c);
	prt_bin((char *)&dd, 4);
}

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
```
0xf907ff
0x1
0x9
11111111 00100011 11111001 00000000 
aaaaaaaa xxbbbbaa ddddcccc

$xx$代表超出部分，变成预留。
