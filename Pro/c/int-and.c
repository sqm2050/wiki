#include <stdio.h>
#include "prt_bit.c"
main()
{
	int a = 0x50;
	int b = -0x50;
	prt_bit(a);
	prt_bit(b);
	printf("a = %d, b = %d\n", a, b);

	printf("%d\n", a & -a);
}
