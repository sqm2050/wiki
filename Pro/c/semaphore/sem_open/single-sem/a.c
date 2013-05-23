#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *sem_a_name = "sem_a";
	sem_t *sem_a_ptr;

	sem_a_ptr = sem_open(sem_a_name, O_CREAT,0644,2);

	if (sem_a_ptr == SEM_FAILED){
		perror("unable to create semaphore");
		sem_unlink(sem_a_name);
		exit(-1);
	} 

	while (1) {
		printf("run a task ...\n");
		sem_wait(sem_a_ptr);
		printf("recv->a_task_is_free\n");
	} 
	sem_close(sem_a_ptr);
	sem_unlink(sem_a_name);
	_exit(0);
} 
