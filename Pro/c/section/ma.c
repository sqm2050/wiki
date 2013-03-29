#include <stdio.h>
extern unsigned char kallsyms[] __attribute__((weak,section(".sunjianxi")));
main()
{
	int i;
	printf("%s\n",kallsyms);
	printf("%d\n",*((char *)kallsyms + 8));
	printf("%d\n",*((char *)kallsyms + 9));
	printf("%s\n",((char *)kallsyms + 8));
	printf("%d\n", *(long *)((char *)kallsyms + 11));
	for (i = 0; i < 10; i++)
	{
		printf("%d, <==11+ %d\n",*((char *)kallsyms + 11 + i ), i);
	}


	printf("sizeof long %d\n", sizeof(long));
}
