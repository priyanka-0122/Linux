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

	signal(SIGFPE, myhandle);
	int a=10, b=0, result;
	result= a/b;
	return 0;
}
