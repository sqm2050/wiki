#include "apue.h"
#include <sys/wait.h>
void pr_exit(int status)
{
	if (WIFEXITED(status))
		printf("normal termination, exit status = %d\n",
				WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n",
				WTERMSIG(status),
#ifdef	WCOREDUMP
		WCOREDUMP(status) ?"(core file gernerated)":"");
#else
		"");
#endif
	else if (WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n",
				WSTOPSIG(status));
}
/* wait一有终止进程就会返回，这里多次wait */
int main()
{
	pid_t pid;
	int status;

	/*	exit	*/
	if ((pid = fork()) < 0)
		printf("fork error\n");
	else if (pid == 0)
		exit(7);
	if (wait(&status) != pid)
		printf("wait error\n");
	pr_exit(status);		//exit(7)

	/* 	abort	*/
	if ((pid = fork()) < 0)
		printf("fork error\n");
	else if (pid == 0)
		abort();
	if (wait(&status) != pid)
		printf("wait error\n");
	pr_exit(status);		//abort();

	/*	/0	*/
	if ((pid = fork()) < 0)
		printf("fork error\n");
	else if (pid == 0)
		status /= 0;
	if (wait(&status) != pid)
		printf("wait error\n");
	pr_exit(status);		///0

	exit(0);
}
