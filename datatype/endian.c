#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    uint16_t u16 = 0x1234;
    uint32_t u32 = 0x12345678;
    uint8_t *u8;


    u8 = (uint8_t *)&u16;
    printf("                      [1;36mH[0m [1;36mL[0m\n");
    printf("               u16 = %04Xh\n", u16);
    printf("(u16 >>  8) & 0xFF = [1;33m%02X[0mh\n", (u16 >> 8) & 0xFF);
    printf("(u16      ) & 0xFF =   [1;33m%02X[0mh\n", (u16) & 0xFF);
    printf("             u8[0] = [1;33m%02X[0mh\n", u8[0]);
    printf("             u8[1] =   [1;33m%02X[0mh\n", u8[1]);
    printf("\n");

    u8 = (uint8_t *)&u32;
    printf("                      [1;36mH[0m     [1;36mL[0m\n");
    printf("               u32 = %08Xh\n", u32);
    printf("(u32 >> 24) & 0xFF = [1;33m%02X[0mh\n", (u32 >> 24) &0xFF);
    printf("(u32 >> 16) & 0xFF =   [1;33m%02X[0mh\n", (u32 >> 16) &0xFF);
    printf("(u32 >>  8) & 0xFF =     [1;33m%02X[0mh\n", (u32 >> 8) &0xFF);
    printf("(u32      ) & 0xFF =       [1;33m%02X[0mh\n", (u32) & 0xFF);
    printf("             u8[0] = [1;33m%02X[0mh\n", u8[0]);
    printf("             u8[1] =   [1;33m%02X[0mh\n", u8[1]);
    printf("             u8[2] =     [1;33m%02X[0mh\n", u8[2]);
    printf("             u8[3] =       [1;33m%02X[0mh\n", u8[3]);

    return 0;
}

