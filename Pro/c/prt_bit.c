#include <stdio.h>
prt_bit(int a)
{
	int i;
	for (i = 0; i < 32; i++) {
		printf("%d", a >> (32 - 1 -i) & 0x01);

		if ((i + 1) % 4 == 0)
			printf(" ");
	}
	printf("\n");
}
#if 0
main()
{
	long a = 0x40;
	prt_bit(a);
}
#endif
