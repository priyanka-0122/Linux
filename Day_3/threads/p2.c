#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;

void *func()
{
	pthread_mutex_lock(&mutex);
	printf("testing threads\n");
	sleep(2);
	printf("Ending threads\n");
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main()
{
	pthread_t t1, t2;
	
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, func, NULL);	//default attributes to the thread
						//Not passing any arguments to the function
	pthread_create(&t2, NULL, func, NULL);
	pthread_join(t1, NULL);	//joining t1 to the process
	pthread_join(t2, NULL);
	printf("Back in main function\n");

	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);
	
	return 0;
}
