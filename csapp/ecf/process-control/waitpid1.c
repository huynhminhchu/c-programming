#include "csapp.h"

#define N 2

int main()
{
    int status, i;
    pid_t pid;

    for (i = 0; i < N; i++) {
        if ( (pid = Fork()) == 0) // if this is child process
            exit(100+i);
    }

    while 
}