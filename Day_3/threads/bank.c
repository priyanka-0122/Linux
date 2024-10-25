#include<stdio.h>
#include "bank.h"
#include<unistd.h>

int balance = 0;

int read_balance()
{
	sleep(2);
	return balance;
}

void write_balance(int new_balance)
{
	sleep(2);
	balance = new_balance;
}
