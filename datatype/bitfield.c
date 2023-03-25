#include <stdio.h>

/*
*  1  1  1  1  1  1  1  1
* +--+--+--+--+--+--+--+--+
* |b7|b6|b5|b4|b3|b2|b1|b0|
* +--+--+--+--+--+--+--+--+
*/
typedef struct tBits
{
   unsigned char b0 : 1,
                 b1 : 1,
                 b2 : 1,
                 b3 : 1,
                 b4 : 1,
                 b5 : 1,
                 b6 : 1,
                 b7 : 1;
} tBits;

int main(void)
{
    tBits data;
    unsigned char *byte;
    int i;

    byte = (unsigned char*)&data;

    printf("data  b7 b6 b5 b4 b3 b2 b1 b0\n");
    for (i=0; i<16; i++)
    {
        *byte = i;
        printf(
            "0x%02X   %u  %u  %u  %u  %u  %u  %u  %u\n",
            *byte,
            data.b7,
            data.b6,
            data.b5,
            data.b4,
            data.b3,
            data.b2,
            data.b1,
            data.b0
        );
    }

    printf("sizeof(tBits) = %ld\n", sizeof(tBits));
    return 0;
}

