#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    srand(time(NULL));
    printf("Parent about to fork! PID: %d\n ", getpid());

    
    int f;

    f = fork();
    
    if (f) 
    {   
        rand();
        f= fork();
    }

    if (f) 
    {
        int status;
        int p = wait(&status);
        printf("My child with PID: %d ended! Slept %d\n", p, WEXITSTATUS(status));
        printf("Parent ended!\n");
        return 0;
    }
    else 
    {
        printf("Child created! PID: %d\n", getpid());
        int time = rand() % 9 + 2;
        sleep(time);
        printf("Child ended! PID: %d\n", getpid());

        return time;

    }


}