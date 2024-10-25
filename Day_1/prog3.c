#include<stdio.h>
#include<unistd.h> //unix standards--system calls are part of unistd.h
#include<sys/wait.h>
#include<stdlib.h>
#include<signal.h>

void myhandle(int a)
{
	printf("Signal received: %d\n",a);
	exit(0);
}

int main()
{

	signal(SIGCHLD, myhandle);
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
//		wait(0);
		printf("======INSIDE PARENT PROCESS=====\n");
	}	
	return 0;
}
