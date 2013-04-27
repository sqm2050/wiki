#include "apue.h"
int glob = 6;
char buf[] = "a write to stdout\n";

int main(void)
{
	int	var = 88;
	pid_t	pid;

	if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) -1)
		puts("write error");

	puts("before fork");	// 如果不冲洗stdout，重定向到文件，就会打印两次before fork
//	fflush(stdout);

	if ((pid = fork()) < 0) {
		puts("fork error");
	} else if (pid == 0) {
		glob++;
		var++;
	} else {
		sleep(2);
	}

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
}
