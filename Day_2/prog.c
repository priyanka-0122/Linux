#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void myhandle_sigusr()
{
        printf("Received SIGUSR1!\n");
        exit(0);
}
int main()
{
        if(signal(SIGUSR1,myhandle_sigusr)==SIG_ERR)
        {
                printf("Unable to catch sigusr1\n");
                exit(1);
        }
 
        printf("Waiting for the SIGUSR1. My PID is %d\n",getpid());
 
        while(1)
        {
                pause();
        }
        return 0;
}
