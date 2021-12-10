#include <stdio.h>
#include <string.h>


void dump(unsigned char *pData, int size)
{
    int i;

    printf("(");
    for (i=0; i<size; i++)
    {
        printf("%02x ", pData[i]);
    }
    printf(")\n");
}

int main(void)
{
    char   val8;
    int    val32;
    double valfloat;


    printf("\n");
    val8 = 127; val32 = (int)val8;
    printf("8-bit to 32-bit\n");
    printf("   %d ", val8);
    dump((void *)&val8, sizeof(char));
    printf("=> %d ", val32);
    dump((void *)&val32, sizeof(int));
    printf("\n");


    val32 = 87654321; val8 = (char)val32;
    printf("32-bit to 8-bit\n");
    printf("   %d ", val32);
    dump((void *)&val32, sizeof(int));
    printf("=> %d ", val8);
    dump((void *)&val8, sizeof(char));
    printf("\n");


    val32 = -1234; valfloat = (double)val32;
    printf("32-bit to double\n");
    printf("   %d ", val32);
    dump((void *)&val32, sizeof(int));
    printf("=> %f ", valfloat);
    dump((void *)&valfloat, sizeof(double));
    printf("\n");


    valfloat = 1234.5678; val32 = (int)valfloat;
    printf("double to 32-bit\n");
    printf("   %f ", valfloat);
    dump((void *)&valfloat, sizeof(double));
    printf("=> %d ", val32);
    dump((void *)&val32, sizeof(int));
    printf("\n");


    return 0;
}

