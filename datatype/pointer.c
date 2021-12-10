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
    printf("sizeof( void*          ) = %d\n", sizeof( void* ));
    printf("sizeof( unsigned long  ) = %d\n", sizeof( unsigned long ));
    printf("sizeof( ptr            ) = %d\n", sizeof( ptr ));
    printf("sizeof( *((char*)ptr)  ) = %d\n", sizeof( *((char*)ptr) ));
    printf("sizeof( *((tData*)ptr) ) = %d\n", sizeof( *((tData*)ptr) ));
    printf("\n");

    free( (void*)ptr );

    return 0;
}

