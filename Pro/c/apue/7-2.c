#include "apue.h"
static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
	if (atexit(my_exit2) != 0)
		puts("can't register my_exit2");

	if (atexit(my_exit1) != 0)
		puts("can't register my_exit1");
	if (atexit(my_exit1) != 0)
		puts("can't register my_exit1");

	puts("main is done");
	return 0;
}

static void my_exit1(void)
{
	printf("fun--------------------1\n");
}

static void my_exit2(void)
{
	printf("fun--------------------2\n");
}
