#include<stdio.h>
#include<unistd.h> //unix standards--system calls are part of unistd.h
#include<sys/types.h>

int main()
{
	
	// Creates a child process by duplicating the calling process and return its id
	pid_t ret = fork(); //pid_rt is a system defined data type

	fork();
	fork();
	fork();
	fork();
	printf("Process Id: %d\n",getpid());
	printf("Value of ret: %d\n",ret);	

	return 0;
}
