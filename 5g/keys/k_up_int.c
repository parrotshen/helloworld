#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kdf.h"


void K_UP_INT(
    uint8  k_up_int[16], // OUT
    uint8  k_gnb[32],    // IN
    uint8  niax          // IN
)
{
    uint8  KEY[32];
    uint8  S[8];
    uint8  buf[32];

    memcpy(KEY, k_gnb, 32);

    /* FC */
    S[0] = 0x69;
    /* P0 */
    S[1] = 0x06; /* N-UP-int-alg */
    /* L0 */
    S[2] = 0x00;
    S[3] = 0x01;
    /* P1 */
    S[4] = niax; /* 5G-IAx */
    /* L1 */
    S[5] = 0x00;
    S[6] = 0x01;

    //mem_dump("Key", KEY, 32);
    //mem_dump("S", S, 7);

    kdf(KEY, 32, S, 7, buf);
    memcpy(k_up_int, buf+16, 16);
    mem_dump("K_UP_INT", k_up_int, 16);
}

