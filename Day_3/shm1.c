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
	char buffer[100];
	void *address;
	
	int shmid = shmget(key, 1024, IPC_CREAT|0666);
	
	if(shmid < 0)
	{
		printf("Shared memory creation failed\n");
		exit(1);
	}
	else
	{
		printf("Shared memory ID: %d\n", shmid);
		address = shmat(shmid, NULL, 0);//NULL attaches the shared memory to the address space of this process
						//0 enables the read and write permissions
		printf("Address to which Shared Memory Segment got attached: %p\n", address);
		read(0, buffer, sizeof(buffer));
		strncpy(address,buffer, sizeof(buffer));
		printf("Content written to Shared Memory: %s\n", (char*)address);
	}
	return 0;
}
