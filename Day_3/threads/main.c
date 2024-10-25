#include<stdio.h>
#include "bank.h"
#include<unistd.h>
#include<pthread.h>

void *deposit(void *amount);

int main()
{
	pthread_t  t1, t2;
	
	int before=read_balance();
	printf("Balance Amount(Before): %d\n", before);

	int deposit1=500, deposit2=300;

	pthread_create(&t1, NULL, deposit, (void *)&deposit1);
	pthread_create(&t2, NULL, deposit, (void *)&deposit2);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	int after = read_balance();
	printf("Balance amount(After): %d\n", after);
	
	pthread_exit(NULL);
	return 0;
}

void *deposit(void *amount)
{
	int account_balance = read_balance();

	account_balance += *((int*)amount);
	write_balance(account_balance);
	return NULL;
}
