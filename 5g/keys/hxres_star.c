#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include "kdf.h"


void HXRES_STAR(
    uint8  hxres_star[16], // OUT
    uint8  xres_star[16],  // IN
    uint8  _rand[16]       // IN
)
{
    uint8  S[32];
    uint8  buf[32];

    /* P0 */
    memcpy(S, _rand, 16);
    /* P1 */
    memcpy(S+16, xres_star, 16);

    //mem_dump("S", S, 32);

    SHA256(S, 32, buf);
    memcpy(hxres_star, buf+16, 16);
    mem_dump("HXRES*", hxres_star, 16);
}

