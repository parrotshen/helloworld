#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _tData
{
    int foo;
    int bar;
    int baz;
    int qux;
} tData;

int main(void)
{
    unsigned long ptr;

    ptr = (unsigned long)malloc( 128 );
    memset((void*)ptr, 0x41, 128);
    ((char*)ptr)[127] = 0x00;

    printf("\n");
    printf("sizeof( void*          ) = %ld\n", sizeof( void* ));
    printf("sizeof( unsigned long  ) = %ld\n", sizeof( unsigned long ));
    printf("sizeof( ptr            ) = %ld\n", sizeof( ptr ));
    printf("sizeof( *((char*)ptr)  ) = %ld\n", sizeof( *((char*)ptr) ));
    printf("sizeof( *((tData*)ptr) ) = %ld\n", sizeof( *((tData*)ptr) ));
    printf("\n");

    free( (void*)ptr );

    return 0;
}

