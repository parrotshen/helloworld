#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kdf.h"


void K_RRC_ENC(
    uint8  k_rrc_enc[32], // OUT
    uint8  k_gnb[32],     // IN
    uint8  neax           // IN
)
{
    uint8  KEY[32];
    uint8  S[8];
    uint8  buf[32];

    memcpy(KEY, k_gnb, 32);

    /* FC */
    S[0] = 0x69;
    /* P0 */
    S[1] = 0x03; /* N-RRC-enc-alg */
    /* L0 */
    S[2] = 0x00;
    S[3] = 0x01;
    /* P1 */
    S[4] = neax; /* 5G-EAx */
    /* L1 */
    S[5] = 0x00;
    S[6] = 0x01;

    //mem_dump("Key", KEY, 32);
    //mem_dump("S", S, 7);

    kdf(KEY, 32, S, 7, buf);
    memcpy(k_rrc_enc, buf+16, 16);
    mem_dump("K_RRC_ENC", k_rrc_enc, 16);
}

