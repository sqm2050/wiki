/* 创建一个共享内存区段，并显示其相关信息，然后删除该内存共享区 */
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MY_SHM_ID 60000

int main()
{
	/* 获得系统内页面的大小 */
	printf("page size=%d\n", getpagesize());

	int shmid, ret;

	/* 
	 * 创建了一个4KB大小共享内存区段。指定的大小必须是当前系统构架
	 * 中页面大小的整数倍
	 */
	shmid = shmget(MY_SHM_ID, 4096,0666|IPC_CREAT);

	if (shmid > 0)
		printf("create a shared memory segment %d\n", shmid);

	/* 获取一个内存区段的信息 */
	struct shmid_ds shmds;
	ret = shmctl(shmid, IPC_STAT, &shmds);
	if (ret == 0)
	{
		printf("size of memory segment is %d\n", (int)shmds.shm_segsz);
		printf("number of attaches %d\n", (int)shmds.shm_nattch);
	} else {
		printf("shmctl() call failed \n");
	}

	/* 删除该共享内存区 */
#if 0
	ret = shmctl(shmid, IPC_RMID, 0);
	if (ret == 0)
		printf("shared memory removed \n");
	else
		printf("shared memory remove failed \n");

#endif
	return 0;
}
