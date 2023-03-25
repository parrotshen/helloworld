#include <stdio.h>
#include <string.h>
#include <inttypes.h>


int main(void)
{
    double    maxdb, mindb;
    float     maxft, minft;
    uint64_t  max64, min64;
    uint32_t  max32, min32;
    uint16_t  max16, min16;
    uint8_t   max8, min8;
    int  shift;

    printf("\n");
    printf("===============================================================\n");
    printf(" Integer type    | Maximum              | Minimum\n");
    printf("===============================================================\n");
    memset(&min8, 0x00, sizeof( uint8_t ));
    memset(&max8, 0xff, sizeof( uint8_t ));
    printf(" unsigned  8-bit | %u                  | %u\n", max8, min8);
    printf("                 | 0x%x                 | 0x%02x\n", max8, min8);
    printf("-----------------+----------------------+----------------------\n");
    shift = (8 * sizeof( int8_t )) - 1;
    min8 = (0x1 << shift);
    max8 = min8 - 1;
    printf("   signed  8-bit | %d                  | %d\n", (int8_t)max8, (int8_t)min8);
    printf("                 | 0x%x                 | 0x%x\n", max8, min8);
    printf("-----------------+----------------------+----------------------\n");
    memset(&min16, 0x00, sizeof( uint16_t ));
    memset(&max16, 0xff, sizeof( uint16_t ));
    printf(" unsigned 16-bit | %u                | %u\n", max16, min16);
    printf("                 | 0x%x               | 0x%04x\n", max16, min16);
    printf("-----------------+----------------------+----------------------\n");
    shift = (8 * sizeof( int16_t )) - 1;
    min16 = (0x1 << shift);
    max16 = min16 - 1;
    printf("   signed 16-bit | %d                | %d\n", (int16_t)max16, (int16_t)min16);
    printf("                 | 0x%x               | 0x%x\n", max16, min16);
    printf("-----------------+----------------------+----------------------\n");
    memset(&min32, 0x00, sizeof( uint32_t ));
    memset(&max32, 0xff, sizeof( uint32_t ));
    printf(" unsigned 32-bit | %u           |  %u\n", max32, min32);
    printf("                 | 0x%x           | 0x%08x\n", max32, min32);
    printf("-----------------+----------------------+----------------------\n");
    shift = (8 * sizeof( int32_t )) - 1;
    min32 = (0x1 << shift);
    max32 = min32 - 1;
    printf("   signed 32-bit | %d           | %d\n", (int32_t)max32, (int32_t)min32);
    printf("                 | 0x%x           | 0x%02x\n", max32, min32);
    printf("-----------------+----------------------+----------------------\n");
    memset(&min64, 0x00, sizeof( uint64_t ));
    memset(&max64, 0xff, sizeof( uint64_t ));
    printf(" unsigned 64-bit | %llu | %llu\n", max64, min64);
    printf("                 | 0x%llx   | 0x%016llx\n", max64, min64);
    printf("-----------------+----------------------+----------------------\n");
    shift = (8 * sizeof( int64_t )) - 1;
    min64 = (0x1LL << shift);
    max64 = min64 - 1;
    printf("   signed 64-bit | %lld  | %lld\n", (int64_t)max64, (int64_t)min64);
    printf("                 | 0x%llx   | 0x%llx\n", max64, min64);
    printf("-----------------+----------------------+----------------------\n");
    *((uint32_t *)(&minft)) = 0xff7fffff;
    *((uint32_t *)(&maxft)) = 0x7f7fffff;
    printf("    float 32-bit | %e         | %e\n", maxft, minft);
    printf("                 | 0x%x           | 0x%x\n", *((uint32_t *)(&maxft)), *((uint32_t *)(&minft)));
    printf("-----------------+----------------------+----------------------\n");
    *((uint64_t *)(&mindb)) = 0xffefffffffffffffLL;
    *((uint64_t *)(&maxdb)) = 0x7fefffffffffffffLL;
    printf("   double 64-bit | %e        | %e\n", maxdb, mindb);
    printf("                 | 0x%llx   | 0x%llx\n", *((uint64_t *)(&maxdb)), *((uint64_t *)(&mindb)));
    printf("===============================================================\n");
    printf("\n");

    return 0;
}

