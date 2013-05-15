#include "apue.h"
int glob = 6;
int main(void)
{
	int var = 88;
	pid_t pid;

	printf("before vfork\n");
	if((pid = vfork()) < 0) {
		printf("vfork erro\n");
	} else if (pid == 0) {	/* child */
		glob++;		/* modify parent's variables */
		var++;
//		_exit(0);	/* child terminates */
//		exit(0);
		fflush(stdout);
	}

	printf("pid = %d, glob = %d, var = %d\n", getpid(), glob, var);
	exit(0);
}
