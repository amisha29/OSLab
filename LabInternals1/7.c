#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void childProcess()
{
    printf("\nFrom child");
    printf("\nChild proocess id : %d \n",getpid());
}

void parentProcess()
{
    printf("\nFrom parent");
    printf("\nparent process id : %d\n",getpid());
}

int main()
{
    pid_t pid;
    printf("\nActual PArent process id : %d\n", getpid());
    for(int i = 0; i < 3; i++)
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