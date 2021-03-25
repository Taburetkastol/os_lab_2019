#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    pid_t id;
    id = fork();
    if(id > 0)
    {
        printf("From the parent process");
        sleep(100);
    }
    else {
        printf("From the child process");
    }
    return 0;
}