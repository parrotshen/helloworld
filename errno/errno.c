#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char str[8];
    int i;

    if (argc > 1)
    {
        errno = atoi( argv[1] );
        sprintf(str, "%3d", errno);
        perror( str );
        return 0;
    }

    for (i=0; i<150; i++)
    {
        errno = i;
        sprintf(str, "%3d", errno);
        perror( str );
    }

    return 0;
}

