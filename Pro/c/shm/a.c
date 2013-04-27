//共享内存区段的挂载,脱离和使用  
//理解共享内存区段就是一块大内存  
#include <stdio.h>  
#include <sys/shm.h>  
#include <sys/ipc.h>  
#include <errno.h>  
#define MY_SHM_ID 67483  
int main(  )  
{  
        //共享内存区段的挂载和脱离  
        int shmid,ret;  
        void* mem;  
//        shmid=shmget( MY_SHM_ID,0,0 );  
	shmid = shmget(MY_SHM_ID,4096,0666|IPC_CREAT );
        if( shmid>=0 )  
            {  
                mem=shmat( shmid,( const void* )0,0 );  
                //shmat()返回进程地址空间中指向区段的指针  
                if( ( int )mem!=-1 )  
                    {  
                        printf( "Shared memory was attached in our address space at %p\n",mem );  
                        //向共享区段内存写入数据  
                        strcpy( ( char* )mem,"This is a test string.\n" );  
                        printf( "%s\n",(char*)mem );  
			sleep(10);
                        //脱离共享内存区段  
                        ret=shmdt( mem );  
                        if( ret==0 )  
                            printf( "Successfully detached memory \n" );  
                        else  
                            printf( "Memory detached failed %d\n",errno );  
                    }  
                else  
                    printf( "shmat(  ) failed\n" );  
                  
            }  
        else  
            printf( "shared memory segment not found\n" );  
        return 0;  
    }  
#if 0
/*内存共享区段与旗语和消息队列不同，一个区段可以被锁定。 
  被锁定的区段不允许被交换出内存。这样做的优势在于，与其 
  把内存区段交换到文件系统，在某个应用程序调用时再交换回内存， 
  不如让它一直处于内存中，且对多个应用程序可见。从提升性能的角度 
  来看，很重要的。 
 */  
int shmid;  
//...  
shmid=shmget( MY_SHM_ID,0,0 );  
ret=shmctl( shmid,SHM_LOCK,0 );  
if( ret==0 )  
    printf( "Locked!\n" );  
////////////////////////////////////////////////////////////////////////  
/*使用旗语协调共享内存的例子 
  使用和编译命令 
  gcc -Wall test.c -o test 
  ./test create 
  ./test use a & 
  ./test use b & 
  ./test read & 
  ./test remove  
 */  
#include <stdio.h>  
#include <sys/shm.h>  
#include <sys/ipc.h>  
#include <sys/sem.h>  
#include <string.h>  
#include <stdlib.h>  
#include <unistd.h>  
#define MY_SHM_ID 34325  
#define MY_SEM_ID 23234  
#define MAX_STRING 200  
typedef struct  
{  
    int semID;  
    int counter;  
    char string[ MAX_STRING+1 ];  
}MY_BLOCK_T;  
int main(int argc,char** argv)  
    {  
        int shmid,ret,i;  
        MY_BLOCK_T* block;  
        struct sembuf sb;  
        char user;  
        //make sure there is a command  
        if( argc>=2 )  
            {  
                //create the shared memory segment and init it  
                //with the semaphore  
              if( !strncmp(argv[ 1 ],"create",6) )  
                    {  
                        //create the shared memory segment and semaphore  
                        printf( "Creating the shared memory\n" );  
                        shmid=shmget( MY_SHM_ID,sizeof( MY_BLOCK_T ),( IPC_CREAT|0666 ) );  
                        block=( MY_BLOCK_T* )shmat( shmid,( const void* )0,0 );  
                        block->counter=0;  
                        //create the semaphore and init  
                        block->semID=semget(MY_SEM_ID,1,( IPC_CREAT|0666 ));  
                        sb.sem_num=0;  
                        sb.sem_op=1;  
                        sb.sem_flg=0;  
                        semop( block->semID,&sb,1 );  
                        /\now detach the segment  
                        shmdt( ( void* )block );  
                        printf( "Create the shared memory and semaphore successuflly\n" );  
                          
                    }  
                else if( !strncmp(argv[ 1 ],"use",3) )  
                    {  
                        /*use the segment*/  
                        //must specify  also a letter to write to the buffer  
                        if( argc<3 ) exit( -1 );  
                        user=( char )argv[ 2 ][ 0 ];  
                        //grab the segment  
                        shmid=shmget( MY_SHM_ID,0,0 );  
                        block=( MY_BLOCK_T* )shmat( shmid,( const void* )0,0 );  
                          
                        /*##########重点就是使用旗语对共享区的访问###########*/  
                        for( i=0;i<100;++i )  
                        {  
                            sleep( 1 ); //设置成1s就会看到 a/b交替出现，为0则a和b连续出现  
                        //grab the semaphore  
                        sb.sem_num=0;  
                        sb.sem_op=-1;  
                        sb.sem_flg=0;  
                        if( semop( block->semID,&sb,1 )!=-1 )  
                            {  
                                //write the letter to the segment buffer  
                                //this is our CRITICAL SECTION  
                                block->string[ block->counter++ ]=user;  
                                  
                                sb.sem_num=0;  
                                sb.sem_op=1;  
                                sb.sem_flg=0;  
                                if( semop( block->semID,&sb,1 )==-1 )  
                                    printf( "Failed to release the semaphore\n" );  
                                  
                            }  
                        else  
                            printf( "Failed to acquire the semaphore\n" );  
                        }  
                          
                       //do some clear work  
                        ret=shmdt(( void*)block);  
                          
                    }  
                else if( !strncmp(argv[ 1 ],"read",4) )  
                    {  
                        //here we will read the buffer in the shared segment  
                        shmid=shmget( MY_SHM_ID,0,0 );  
                        if( shmid!=-1 )  
                            {  
                                block=( MY_BLOCK_T* )shmat( shmid,( const void* )0,0 );  
                                block->string[ block->counter+1 ]=0;  
                                printf( "%s\n",block->string );  
                                printf( "Length=%d\n",block->counter );  
                                ret=shmdt( ( void*)block );  
                             }  
                        else  
                            printf( "Unable to read segment\n" );  
                  
                    }  
                else if( !strncmp(argv[ 1 ],"remove",6) )  
                    {  
                        shmid=shmget( MY_SHM_ID,0,0 );  
                        if( shmid>=0 )  
                            {  
                                block=( MY_BLOCK_T* )shmat( shmid,( const void* )0,0 );  
                                //remove the semaphore  
                                ret=semctl( block->semID,0,IPC_RMID );  
                                if( ret==0 )  
                                    printf( "Successfully remove the semaphore \n" );  
                                //remove the shared segment  
                                ret=shmctl( shmid,IPC_RMID,0 );  
                                if( ret==0 )  
                                    printf( "Successfully remove the segment \n" );  
                            }  
                    }  
                else  
                    printf( "Unkonw command\n" );  
            }  
        return 0;  
      }
#endif
