#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("Program %s will be executedn\n\n", argv[0]);
    execv("sequential_min_max", argv);
    return 0;
}