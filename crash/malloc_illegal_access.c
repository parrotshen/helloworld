#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void dump(void *pAddr, int size)
{
    unsigned char *pByte = pAddr;
    int i;

    for (i=0; i<size; i++)
    {
        if ((i != 0) && ((i % 16) == 0)) printf("\n");
        if ((i % 16) == 0) printf("%p :", (pByte + i));
        printf(" %02x", pByte[i]);
    }
    printf("\n");
    printf("(%d bytes)\n", size);
    printf("\n");
}

int main(void)
{
    unsigned char *pBuf;
    int i;

    pBuf = malloc( 100 );

    /* malloc(): corrupted top size */
    for (i=0; i<110; i++)
    {
        pBuf[i] = i + 1;
    }

    dump(pBuf, 110);

    free( pBuf );

    return 0;
}

