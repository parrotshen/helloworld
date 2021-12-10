#include <stdio.h>

int main(void)
{
    unsigned long long  val64;
    unsigned short  val16;

    val16 = 45000;
    printf("   val16 = %u\n", val16);

    val64 = (val16 * 100000);
    printf("1) val16 * 100000 = %llu (0x%llx)\n", val64, val64);

    val64 = (val16 * 100000ULL);
    printf("2) val16 * 100000ULL = %llu (0x%llx)\n", val64, val64);
    printf("\n");

    val64  = val16;
    printf("   val64 = %llu\n", val64);
    val64 = (val64 * 100000);
    printf("3) val64 * 100000 = %llu (0x%llx)\n", val64, val64);
    printf("\n");

    return 0;
}

