#include<stdio.h>
#include<unistd.h> //unix standards--system calls are part of unistd.h
#include<signal.h>
#include<stdlib.h>

void myhandle(int a)
{
	printf("Signal number received %d\n",a);
	exit(0);
}

int main()
{

	signal(SIGINT, myhandle);
	while(1)
	{
		printf("Process Id: %d\n",getpid());
		sleep(2);
	}	
	return 0;
}
