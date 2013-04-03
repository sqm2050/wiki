#include "apue.h"

main()
{
	chown("./bar", 1000, 1000);

	printf("%d\n%d\n", getuid(),getgid());
}
