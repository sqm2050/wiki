#include "apue.h"
#include <string.h>
#include <sys/wait.h>
static void sig_int()
{
	printf("interupt\n %%");
}
main()
{
	char buf[20];
	int status;
	pid_t pid;
	printf("%%");

	if (signal(SIGINT, sig_int) == SIG_ERR)
		printf("signal error\n");

	while (fgets(buf, 20, stdin) != NULL) {
#if 1
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0;
		/* fork一个新进程 */
		pid = fork();
		printf("here is print test0000000000\n"); 
		if (pid == 0) {
			/* 子进程执行buf命令，成功完成后退出，否则继续 */
			execlp(buf, buf, (char *)0);
			printf("yes, here don't execute the command\n");
		}
		printf("here is print test1111111111\n");
		/* 这里子进程不会执行 */
		if ((pid = waitpid(pid, &status, 0)) < 0)
			printf("waitpid error\n");
		printf("%%");
#endif
	}
}
