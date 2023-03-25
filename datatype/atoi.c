#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INTEGER_32BIT "4294967295" /* 0xffffffff */

int main(int argc, char *argv[])
{
    unsigned long long u64;
    signed long long   i64;
    unsigned int       u32;
    signed int         i32;
    unsigned short     u16;
    signed short       i16;
    unsigned char      u8;
    signed char        i8;


    if (argc > 1)
    {
        printf("\"%s\" -> %d\n", argv[1], atoi( argv[1]) );
        return 0;
    }

    u64 = atoi( MAX_INTEGER_32BIT );
    i64 = atoi( MAX_INTEGER_32BIT );
    u32 = atoi( MAX_INTEGER_32BIT );
    i32 = atoi( MAX_INTEGER_32BIT );
    u16 = atoi( MAX_INTEGER_32BIT );
    i16 = atoi( MAX_INTEGER_32BIT );
    u8  = atoi( MAX_INTEGER_32BIT );
    i8  = atoi( MAX_INTEGER_32BIT );

    printf("\"%s\" -> u64 %llu\n", MAX_INTEGER_32BIT, u64);
    printf("\"%s\" -> i64 %lld\n", MAX_INTEGER_32BIT, i64);
    printf("\"%s\" -> u32 %u\n", MAX_INTEGER_32BIT, u32);
    printf("\"%s\" -> i32 %d\n", MAX_INTEGER_32BIT, i32);
    printf("\"%s\" -> u16 %u\n", MAX_INTEGER_32BIT, u16);
    printf("\"%s\" -> i16 %d\n", MAX_INTEGER_32BIT, i16);
    printf("\"%s\" -> u8  %u\n", MAX_INTEGER_32BIT, u8);
    printf("\"%s\" -> i8  %d\n", MAX_INTEGER_32BIT, i8);

    return 0;
}
