#include <stdlib.h>
#include <stdio.h>


char *bin_string(unsigned char n)
{
    static char _string[16];

    sprintf(
        _string,
        "%d%d%d%d%d%d%d%d",
        ((n >> 7) & 0x1),
        ((n >> 6) & 0x1),
        ((n >> 5) & 0x1),
        ((n >> 4) & 0x1),
        ((n >> 3) & 0x1),
        ((n >> 2) & 0x1),
        ((n >> 1) & 0x1),
        ((n     ) & 0x1)
    );

    return _string;
}

int main(void)
{
    unsigned char byte = 0;
    unsigned char byteAbs;
    int i;

    printf("\n");
    for (i=0; i<256; i++)
    {
        byteAbs = (byte & 0x80) ? ((byte ^ 0xff) + 1) : byte;

        if (0 == (i & 0x0f))
        {
            printf("[1;36m     bin  hex   u8    i8  abs[0m\n");
        }
        printf(
            "%s   %02x  %3u  %4d  %3u\n",
            bin_string( byte ),
            byte,
            byte,
            (char)byte,
            byteAbs
        );

        byte++;
    }
    printf("\n");

    return 0;
}
 
