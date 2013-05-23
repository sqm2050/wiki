#include "sem_sync.h"
int main()
{
	sem_t *sem_a_task_is_free;
	sem_t *sem_b_task_is_free;

	sem_a_task_is_free = sem_open(SEM_A_TASK_IS_FREE, O_CREAT,0644,1);
	sem_b_task_is_free = sem_open(SEM_B_TASK_IS_FREE, O_CREAT,0644,0);

	if (sem_a_task_is_free == SEM_FAILED || sem_b_task_is_free == SEM_FAILED) {
		perror("unable to create semaphore");
		sem_unlink(SEM_A_TASK_IS_FREE);
		exit(-1);
	} 

	while (1) {
		printf("run a task ...\n");
		getchar();
		sem_post(sem_a_task_is_free);
		printf("send->a_task_is_free\n");
		sem_wait(sem_b_task_is_free);
		printf("recv<-sem_b_task_is_free\n");
	} 
	sem_close(sem_a_task_is_free);
	sem_unlink(SEM_A_TASK_IS_FREE);
	_exit(0);
} 
