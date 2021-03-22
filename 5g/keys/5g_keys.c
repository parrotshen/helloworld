#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kdf.h"


typedef enum
{
    ID_NIA0     = 0,
    ID_128_NIA1 = 1,
    ID_128_NIA2 = 2,
    ID_128_NIA3 = 3
} tNIAx;

typedef enum
{
    ID_NEA0     = 0,
    ID_128_NEA1 = 1,
    ID_128_NEA2 = 2,
    ID_128_NEA3 = 3
} tNEAx;


uint8  _rand[16] = {
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint8  xres[16] = {
 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};

uint8  ck[16] = {
 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x00
};

uint8  ik[16] = {
 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09,
 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x00, 0x01
};

uint8  ak[6] = {
 0x03, 0x04, 0x05, 0x06, 0x07, 0x08
};

uint8  sqn[6] = {
 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF
};

uint8  snn[32] = {
 /* PLMN-ID: 001.01 */
 '5', 'G',
 ':',
 'm', 'n', 'c', '0', '0', '1',
 '.',
 'm', 'c', 'c', '0', '0', '1',
 '.',
 '3', 'g', 'p', 'p', 'n', 'e', 't', 'w', 'o', 'r', 'k',
 '.',
 'o', 'r', 'g'
};

uint8  supi[15] = {
 /* IMSI: 001.01.0123456789 */
 '0', '0', '1',
 '0', '1',
 '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
};

uint8  abba[2] = {
 0x00, 0x00
};

uint32 nas_count = 0;

int niax = ID_128_NIA2;
int neax = ID_128_NEA2;


extern void XRES_STAR(
    uint8  xres_star[16], // OUT
    uint8  xres[16],      // IN
    int    xres_len,      // IN
    uint8  _rand[16],     // IN
    uint8  ck[16],        // IN
    uint8  ik[16],        // IN
    uint8  snn[32]        // IN
);

extern void HXRES_STAR(
    uint8  hxres_star[16], // OUT
    uint8  xres_star[16],  // IN
    uint8  _rand[16]       // IN
);

extern void K_AUSF(
    uint8  k_ausf[32], // OUT
    uint8  ck[16],     // IN
    uint8  ik[16],     // IN
    uint8  ak[6],      // IN
    uint8  sqn[6],     // IN
    uint8  snn[32]     // IN
);

extern void K_SEAF(
    uint8  k_seaf[32], // OUT
    uint8  k_ausf[32], // IN
    uint8  snn[32]     // IN
);

extern void K_AMF(
    uint8  k_amf[32],  // OUT
    uint8  k_seaf[32], // IN
    uint8  supi[15],   // IN
    uint8  abba[2]     // IN
);

extern void K_NAS_INT(
    uint8  k_nas_int[16], // OUT
    uint8  k_amf[32],     // IN
    int    niax           // IN
);

extern void K_NAS_ENC(
    uint8  k_nas_enc[16], // OUT
    uint8  k_amf[32],     // IN
    int    neax           // IN
);

extern void K_gNB(
    uint8  k_gnb[32], // OUT
    uint8  k_amf[32], // IN
    uint32 nas_count  // IN
);

extern void K_NH(
    uint8  k_nh[32],  // OUT
    uint8  k_amf[32], // IN
    uint8  k_gnb[32]  // IN
);

extern void K_RRC_INT(
    uint8  k_rrc_int[32], // OUT
    uint8  k_gnb[32],     // IN
    uint8  niax           // IN
);

extern void K_RRC_ENC(
    uint8  k_rrc_enc[32], // OUT
    uint8  k_gnb[32],     // IN
    uint8  neax           // IN
);

extern void K_UP_INT(
    uint8  k_up_int[16], // OUT
    uint8  k_gnb[32],    // IN
    uint8  niax          // IN
);

extern void K_UP_ENC(
    uint8  k_up_enc[16], // OUT
    uint8  k_gnb[32],    // IN
    uint8  neax          // IN
);

int main(void)
{
    uint8  xres_star[16];
    uint8  hxres_star[16];
    uint8  k_ausf[32];
    uint8  k_seaf[32];
    uint8  k_amf[32];
    uint8  k_nas_int[16];
    uint8  k_nas_enc[16];
    uint8  k_gnb[32];
    uint8  k_nh[32];
    uint8  k_rrc_int[16];
    uint8  k_rrc_enc[16];
    uint8  k_up_int[16];
    uint8  k_up_enc[16];


    XRES_STAR(xres_star, xres, 16, _rand, ck, ik, snn);

    HXRES_STAR(hxres_star, xres_star, _rand);

    K_AUSF(k_ausf, ck, ik, ak, sqn, snn);

    K_SEAF(k_seaf, k_ausf, snn);

    K_AMF(k_amf, k_seaf, supi, abba);

    K_NAS_INT(k_nas_int, k_amf, niax);

    K_NAS_ENC(k_nas_enc, k_amf, neax);

    K_gNB(k_gnb, k_amf, nas_count);

    K_NH(k_nh, k_amf, k_gnb);

    K_RRC_INT(k_rrc_int, k_gnb, niax);

    K_RRC_ENC(k_rrc_enc, k_gnb, neax);

    K_UP_INT(k_up_int, k_gnb, niax);

    K_UP_ENC(k_up_enc, k_gnb, neax);

    return 0;
}

