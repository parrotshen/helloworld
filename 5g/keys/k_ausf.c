#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kdf.h"


void K_AUSF(
    uint8  k_ausf[32], // OUT
    uint8  ck[16],     // IN
    uint8  ik[16],     // IN
    uint8  ak[6],      // IN
    uint8  sqn[6],     // IN
    uint8  snn[32]     // IN
)
{
    uint8  KEY[32];
    uint8  S[43];

    memcpy(KEY,    ck, 16);
    memcpy(KEY+16, ik, 16);

    /* FC */
    S[0]  = 0x6A;
    /* P0 */
    memcpy(S+1, snn, 32);
    /* L0 */
    S[33] = 0x00;
    S[34] = 0x20;
    /* P1 */
    S[35] = (sqn[0] ^ ak[0]);
    S[36] = (sqn[1] ^ ak[1]);
    S[37] = (sqn[2] ^ ak[2]);
    S[38] = (sqn[3] ^ ak[3]);
    S[39] = (sqn[4] ^ ak[4]);
    S[40] = (sqn[5] ^ ak[5]);
    /* L1 */
    S[41] = 0x00;
    S[42] = 0x06;

    //mem_dump("Key", KEY, 32);
    //mem_dump("S", S, 43);

    kdf(KEY, 32, S, 43, k_ausf);
    mem_dump("K_AUSF", k_ausf, 32);
}

