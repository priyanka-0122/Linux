#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
 
void myhandle(int signo)
{
        printf("Signal Number Received : %d\n",signo);
}

int main()
{
        signal(SIGPIPE,myhandle);
        int arr[2];
        pipe(arr); //Create an unnamed pipe
        //close(arr[0]); //closing the read end
        int w=write(arr[1],"Embedded",8);
        if(w<0)
        {
                printf("Write Failed\n");
                exit(1);
        }
        char buffer[8];
        read(arr[0],buffer,sizeof(buffer));
        printf("Content read from the buffer : %s\n",buffer);
        return 0;
}
