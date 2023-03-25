#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


void dump(unsigned char *pByte, int len)
{
    int i;

    for (i=0; i<len; i++)
    {
        printf(" %02x", pByte[i]);
    }
    printf("\n\n");
}

char g_buf[16] = {
     '1',  '2',  '3',  '4',  '5', 0x00, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

int main(int argc, char *argv[])
{
    char  *s1 = "12345";
    char  *s2 = g_buf;
    char **s3 = &s2;
    char   s4[] = "12345";
    char   s5[128] = "12345";


    printf("s1:\n");
    printf(" \"%s\"\n", s1);
    printf(" sizeof(*s1) = %d\n", sizeof(*s1));
    dump((void *)s1, 16);

    printf("s2:\n");
    printf(" \"%s\"\n", s2);
    printf(" sizeof(*s2) = %d\n", sizeof(*s2));
    dump((void *)s2, 16);

    printf("s3:\n");
    printf(" \"%s\"\n", (*s3));
    printf(" sizeof(*s3) = %d\n", sizeof(*s3));
    dump((void *)(*s3), 16);

    printf("s4:\n");
    printf(" \"%s\"\n", s4);
    printf(" sizeof(s4) = %d\n", sizeof(s4));
    dump((void *)s4, 16);

    printf("s5:\n");
    printf(" \"%s\"\n", s5);
    printf(" sizeof(s5) = %d\n", sizeof(s5));
    dump((void *)s5, 16);

    return 0;
}

