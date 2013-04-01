#include "apue.h"
int main(void)
{
	int ret1, ret2;
	char buf[100000];

	ret1 = lseek(0, 0, SEEK_CUR);
	read(0, buf, 10000);
	ret2 = lseek(0, 0, SEEK_CUR);

	printf("%s\n", buf);

	printf("%4d, %4d\n", ret1, ret2);
}
