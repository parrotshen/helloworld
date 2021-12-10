#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>


wchar_t wc1[] = L"ABCDEFG";
wchar_t wc2[] = L"中文";

unsigned char wc3[] = {
    0x42, 0x30, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00,
    0x44, 0x30, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00,
    0x46, 0x30, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00,
    0x48, 0x30, 0x00, 0x00,
    0x20, 0x00, 0x00, 0x00,
    0x4A, 0x30, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};


void dump(void *pAddr, int len)
{
    unsigned char *pByte = pAddr;
    int i;

    if ( pAddr )
    {
        for (i=0; i<len; i++)
        {
            if ((0 != i) && (0 == (i % 16)))
            {
                fprintf(stderr, "\n");
            }
            fprintf(stderr, " %02x", pByte[i]);
        }
        fprintf(stderr, "\n");
        fprintf(stderr, " (%d bytes)\n\n", len);
    }
}

int main(int argc, char *argv[])
{
    /* inherit locale setting from environment */
    setlocale(LC_ALL, "");

    wprintf(L"%ls (%d characters)\n", wc1, wcslen(wc1));
    dump(wc1, sizeof(wc1));

    wprintf(L"%ls (%d characters)\n", wc2, wcslen(wc2));
    dump(wc2, sizeof(wc2));

    wprintf(L"%ls (%d characters)\n", (wchar_t *)wc3, wcslen((wchar_t *)wc3));
    dump(wc3, sizeof(wc3));

    return 0;
}

