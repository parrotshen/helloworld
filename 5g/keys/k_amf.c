#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kdf.h"


void K_AMF(
    uint8  k_amf[32],  // OUT
    uint8  k_seaf[32], // IN
    uint8  supi[15],   // IN
    uint8  abba[2]     // IN
)
{
    uint8  KEY[32];
    uint8  S[22];

    memcpy(KEY, k_seaf, 32);

    /* FC */
    S[0]  = 0x6D;
    /* P0 */
    memcpy(S+1, supi, 15);
    /* L0 */
    S[16] = 0x00;
    S[17] = 0x0F;
    /* P1 */
    S[18] = abba[0];
    S[19] = abba[1];
    /* L1 */
    S[20] = 0x00;
    S[21] = 0x02;

    //mem_dump("Key", KEY, 32);
    //mem_dump("S", S, 22);

    kdf(KEY, 32, S, 22, k_amf);
    mem_dump("K_AMF", k_amf, 32);
}

