#include "apue.h"
int main()
{
	printf("read uid = %d, effective uid = %d\n", getuid(), geteuid());
	system("echo test-root >> aaaaa");
}
