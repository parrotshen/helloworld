#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool test;

    printf("\n");
    printf("sizeof( bool ) = %ld\n", sizeof( bool ));
    printf("\n");
    printf("bool = -9999 -> %d\n", (test = -9999));
    printf("bool = -999 -> %d\n", (test = -999));
    printf("bool = -99 -> %d\n", (test = -99));
    printf("bool = -1 -> %d\n", (test = -1));
    printf("bool = 0 -> %d\n", (test = 0));
    printf("bool = 1 -> %d\n", (test = 1));
    printf("bool = 99 -> %d\n", (test = 99));
    printf("bool = 999 -> %d\n", (test = 999));
    printf("bool = 9999 -> %d\n", (test = 9999));
    printf("\n");

    return 0;
}

