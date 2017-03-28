#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>

void childProcess()
{
    printf("\nFrom child\n");
    printf("Child proocess id : %d \nParent process id : %d",getpid(),getppid());
}

void parentProcess()
{
    printf("\nFrom parent\n");
    printf("parent process id : %d",getpid());
}

int main()
{
    pid_t pid;
    pid = fork();
    if(pid < 0)
    {
        printf("\nError");
        exit(-1);
    }

    else if(pid == 0)
        childProcess();

    else
    {
        pid = wait(NULL);
        if(pid>0)
        {
            printf("\nFrom Parent: Child Pid: %d\n",pid);                
        }
        parentProcess();
        
    }
}