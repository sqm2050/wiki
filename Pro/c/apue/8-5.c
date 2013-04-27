#include "apue.h"
#include <sys/wait.h>

int main(void)
{
	pid_t pid;

	if ((pid = fork()) < 0) {
		printf("fork error\n");
	} else if (pid == 0) {		/* first child */
		if ((pid = fork()) < 0)
			printf("fork error\n");
		else if (pid ==0)
			printf("second child, parent pid = %d\n", getppid());
		else if (pid > 0) {
			sleep(1);
			exit(0);	/* paren from second fork == first child */
		}

		sleep(2);
		printf("second child, parent pid = %d\n", getppid());
		exit(0);
	}

	printf("waiting %d\n", pid);
	if (waitpid(pid, NULL, 0) != pid) /* wait for first child */
		printf("waitpid error\n");

	exit(0);
}
