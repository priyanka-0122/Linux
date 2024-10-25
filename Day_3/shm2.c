#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	key_t key = 70;
	void *address;
	
	int shmid = shmget(key, 1024, IPC_EXCL);
	
	if(shmid < 0)
	{
		printf("Shared memory doesnot exist\n");
		exit(1);
	}
	printf("Shared memory ID: %d\n", shmid);
	address = shmat(shmid, NULL, 0);//NULL attaches the shared memory to the address space of this process
					// 0 enables the read write permission in this case
	printf("Address to which Shared Memory Segment got attached: %p\n", address);
	printf("Content read from the Shared Memory: %s\n", (char*)address);
	return 0;
}
