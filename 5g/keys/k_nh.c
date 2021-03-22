#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kdf.h"


void K_NH(
    uint8  k_nh[32],  // OUT
    uint8  k_amf[32], // IN
    uint8  k_gnb[32]  // IN
)
{
    uint8  KEY[32];
    uint8  S[36];

    memcpy(KEY, k_amf, 32);

    /* FC */
    S[0]  = 0x6F;
    /* P0 */
    memcpy(S+1, k_gnb, 32);
    /* L0 */
    S[33] = 0x00;
    S[34] = 0x20;

    //mem_dump("Key", KEY, 32);
    //mem_dump("S", S, 35);

    kdf(KEY, 32, S, 35, k_nh);
    mem_dump("K_NH", k_nh, 32);
}

