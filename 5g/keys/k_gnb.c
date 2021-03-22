#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kdf.h"


void K_gNB(
    uint8  k_gnb[32], // OUT
    uint8  k_amf[32], // IN
    uint32 nas_count  // IN
)
{
    uint8  KEY[32];
    uint8  S[10];

    memcpy(KEY, k_amf, 32);

    /* FC */
    S[0] = 0x6E;
    /* P0 */
    S[1]  = ((nas_count >> 24) & 0xFF);
    S[2]  = ((nas_count >> 16) & 0xFF);
    S[3]  = ((nas_count >>  8) & 0xFF);
    S[4]  = ((nas_count      ) & 0xFF);
    /* L0 */
    S[5] = 0x00;
    S[6] = 0x04;
    /* P1 */
    S[7] = 0x01; /* 3GPP access */
    /* L1 */
    S[8] = 0x00;
    S[9] = 0x01;

    //mem_dump("Key", KEY, 32);
    //mem_dump("S", S, 10);

    kdf(KEY, 32, S, 10, k_gnb);
    mem_dump("K_gNB", k_gnb, 32);
}

