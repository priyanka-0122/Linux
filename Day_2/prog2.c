#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	// create a file "may.txt", specify the read write permission and open a file
 	int fd = open("may.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
 
        if(fd<0)
        {
                printf("Failed to create may.txt\n");
                exit(1);
        }
        else
        {
                int w=write(fd,"Blackfig Technologies",21);
 
                if(w<0)
                {
                        printf("Write failed\n");
                        exit(1);
                }
                else
                {
                        char buffer[21];
 
                        int fd2=open("may.txt",O_RDONLY);
 
                        if(fd2<0)
                        {
                                printf("Failed to open the file\n");
                                exit(1);
                        }
                        else
                        {
                                read(fd2,buffer,sizeof(buffer));
 
                                printf("Content read from the file may.txt is %s\n",buffer);
                        }
                        close(fd2);
                }
                close(fd);
        }
 
        return 0;
}

