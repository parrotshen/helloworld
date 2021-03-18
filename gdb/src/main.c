#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "morse.h"


char g_code[1024];


int main(int argc, char *argv[])
{
    char *pMsg = "Hello world!";
    char *pBuf;
    char *pCode;
    int n;
    int i;

    if (argc > 1)
    {
        pMsg = argv[1];
    }

    printf("\"%s\"\n\n", pMsg);

    pBuf = g_code;
    for (i=0; i<strlen(pMsg); i++)
    {
        pCode = morse_code( pMsg[i] );
        n = sprintf(pBuf, "%s ", pCode);
        pBuf += n;
    }

    printf("%s\n\n", g_code);

    return 0;
}
