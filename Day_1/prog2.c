#include<stdio.h>
#include<unistd.h> //unix standards--system calls are part of unistd.h
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	
	// Creates a child process by duplicating the calling process and return its id
	pid_t ret = fork(); //pid_rt is a system defined data type

	printf("Process Id: %d\n",getpid());
	if (ret < 0)
	{
		printf("Child process failed\n");
	}
	else if(ret == 0)
	{
		printf("======INSIDE CHILD PROCESS=====\n");
	}
	else
	{
		wait(0);
		printf("======INSIDE PARENT PROCESS=====\n");
	}	
	return 0;
}
