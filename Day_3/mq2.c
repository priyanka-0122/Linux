#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>

struct msg {
	long msgno;
	char str[50];
};

int main()
{
	key_t key = 99;
	int msg_id = msgget(key, IPC_EXCL);
	
	if (msg_id < 0 )
	{
		printf("Message queue does not exist\n");
		exit(1);
	}
	else
	{
		printf("Message ID: %d\n",msg_id);
		struct msg m;
		msgrcv(msg_id, &m, sizeof(m),15, 0); //.,.,.,message id(if want to receive all the msgs then write 0, no need to specify the permission as this is reading
		
		printf("Message numer: %ld\n",m.msgno);
		printf("Message: %s\n",m.str);
	}
	return 0;
}
