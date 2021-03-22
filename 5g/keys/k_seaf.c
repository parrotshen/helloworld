#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kdf.h"


void K_SEAF(
    uint8  k_seaf[32], // OUT
    uint8  k_ausf[32], // IN
    uint8  snn[32]     // IN
)
{
    uint8  KEY[32];
    uint8  S[35];


    memcpy(KEY, k_ausf, 32);

    /* FC */
    S[0]  = 0x6C;
    /* P0 */
    memcpy(S+1, snn, 32);
    /* L0 */
    S[33] = 0x00;
    S[34] = 0x20;

    //mem_dump("Key", KEY, 32);
    //mem_dump("S", S, 35);

    kdf(KEY, 32, S, 35, k_seaf);
    mem_dump("K_SEAF", k_seaf, 32);
}

