#include <stdio.h>
#include <string.h>


void dump(unsigned char *pData, int size)
{
    int i;

    printf("(");
    for (i=0; i<size; i++)
    {
        printf("%02x", pData[i]);
        if (i < (size - 1)) printf(" ");
    }
    printf(")\n");
}

int main(void)
{
    char   val8;
    short  val16;
    int    val32;
    double valfloat;
    unsigned short dat16;


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


        dat16 = 0xE802; val8 = (char)dat16;
    printf("unsigned 16-bit to signed 8-bit\n");
    printf("   %u ", dat16);
    dump((void *)&dat16, sizeof(short));
    printf("=> %d ", val8);
    dump((void *)&val8, sizeof(char));
    printf("\n");


    dat16 = 0xE802; val16 = (short)dat16;
    printf("unsigned 16-bit to signed 16-bit\n");
    printf("   %u ", dat16);
    dump((void *)&dat16, sizeof(short));
    printf("=> %d ", val16);
    dump((void *)&val16, sizeof(short));
    printf("\n");


    dat16 = 0xE802; val32 = (int)dat16;
    printf("unsigned 16-bit to signed 32-bit\n");
    printf("   %u ", dat16);
    dump((void *)&dat16, sizeof(short));
    printf("=> %d ", val32);
    dump((void *)&val32, sizeof(int));
    printf("\n");
    
    
    return 0;
}

