#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdlib.h>
 
struct msg
{
        long msgno;
        char str[50];
};
 
int main()
{
        key_t key = 99;
        int msgid=msgget(key,IPC_CREAT|0666);
 
        if(msgid<0)
        {
                printf("Message Queue creation failed\n");
                exit(1);
        }
        else
        {
                printf("Message Queue ID : %d\n",msgid);
 
                struct msg m;
 
                m.msgno=10;
                strcpy(m.str,"C Programming");
                msgsnd(msgid,&m,sizeof(m),0); //0 block/secured mode
 
                m.msgno=12;
                strcpy(m.str,"C++ Programming");
                msgsnd(msgid,&m,sizeof(m),0);
 
                m.msgno=15;
                strcpy(m.str,"Python Programming");
                msgsnd(msgid,&m,sizeof(m),0);
 
                m.msgno=17;
                strcpy(m.str,"Java Programming");
                msgsnd(msgid,&m,sizeof(m),0);
 
                m.msgno=19;
                strcpy(m.str,"Javascript");
                msgsnd(msgid,&m,sizeof(m),0);
 
                m.msgno=21;
                strcpy(m.str,"Shell Scripting");
                msgsnd(msgid,&m,sizeof(m),0);
        }
        return 0;
}
