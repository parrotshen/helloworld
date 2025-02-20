#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    printf("Before assert\n");
    printf("argc = %d\n", argc);
    assert( argc > 1 );
    printf("After assert\n");
    return 0;
}

