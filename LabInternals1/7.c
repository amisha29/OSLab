#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void childProcess()
{
    printf("\nFrom child\n");
    printf("Child proocess id : %d \nParent process id : %d\n",getpid(),getppid());
}

void parentProcess()
{
    printf("\nFrom parent\n");
    printf("\nparent process id : %d\n",getpid());
}

int main()
{
    pid_t pid;
    printf("\nActual PArent process id : %d\n", getpid());
    for(int i = 0; i < 2; i++)
    {
        pid = fork();
        if(pid < 0)
        {
            printf("\nerror during forking\n");
            exit(0);
        }
        else if(pid == 0)
            childProcess();
        else
        {
            wait(NULL);
            parentProcess();
        }
    }
}