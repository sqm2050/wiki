#include "apue.h"
#include <fcntl.h>
#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{
	umask(RWRWRW);					/* umaks 会掩掉后面mode_t的设置 */
	if (creat("foo", RWRWRW) < 0)
		printf("creat error for foo\n");

	printf("%x\n", RWRWRW);

	umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);

	if (creat("bar", RWRWRW) < 0)
		printf("create error for bar\n");

	exit(0);
}
