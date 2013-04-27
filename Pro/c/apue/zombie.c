#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
main()
{
	pid_t pid;
	char buf[1024];
	int i, status;
	fgets(buf, 1024, stdin);
	if (buf[strlen(buf) - 1] == '\n')
		buf[strlen(buf) - 1] = 0x00;

	pid = fork();
	printf("---------------------------------------------%d\n", pid);

	if (pid == 0) {
//		sleep(9);//引起父进程阻塞waitpid
		execlp(buf, buf, (char *)0);
		exit(127);
	}
/* 如果不wait去进行资源回收，子进程已经结束，在父进程sleep的时间内，称为僵死进程 */ 	
	if ((pid = waitpid(pid, &status, 0)) < 0)	
		printf("waitpid error\n");
	printf("wating..\n");
	sleep(20);

	printf("waitpid %d\n", status);
}
