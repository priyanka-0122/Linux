#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *func()
{
	printf("testing threads\n");
	sleep(2);
	printf("Ending threads\n");
	return NULL;
}

int main()
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, func, NULL);	//default attributes to the thread
						//Not passing any arguments to the function
	pthread_create(&t2, NULL, func, NULL);
	pthread_join(t1, NULL);	//joining t1 to the process
	pthread_join(t2, NULL);
	printf("Back in main function\n");
	pthread_exit(NULL);
	
	return 0;
}
