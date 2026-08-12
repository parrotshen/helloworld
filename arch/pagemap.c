#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <inttypes.h>


uintptr_t toPhysical(int pid, uintptr_t vaddr)
{
#define PAGEMAP_ENTRY (8)
    uintptr_t paddr = 0;
    unsigned long long frame = 0;
    unsigned long offset;
    unsigned long psize;
    char procFile[128];
    FILE *pFile;

    static int N = 0x1;
    int endian;
    int buf[PAGEMAP_ENTRY];
    int byte;
    int i;


    endian = ((*(char *)&N) == 0);

    sprintf(procFile, "/proc/%u/pagemap", pid);
    pFile = fopen(procFile, "rb");
    if ( pFile )
    {
        psize = getpagesize();
        offset = ((unsigned long)vaddr / psize * PAGEMAP_ENTRY);

        if (0 == fseek(pFile, offset, SEEK_SET))
        {
            // https://www.kernel.org/doc/Documentation/vm/pagemap.txt
            printf("Page Map:\n");
            for (i=0; i<PAGEMAP_ENTRY; i++)
            {
                byte = getc( pFile );
                if (EOF == byte)
                {
                    printf("\nERR: EOF\n");
                    fclose( pFile );
                    return 0;
                }
                printf("[%d]0x%X ", i, byte);

                if ( endian )
                {
                    /* big endian */
                    buf[i] = byte;
                }
                else
                {
                    /* little endian */
                    buf[PAGEMAP_ENTRY - i - 1] = byte;
                }
            }
            printf("\n\n");

            for (i=0; i<PAGEMAP_ENTRY; i++)
            {
                frame = (frame << 8) + buf[i];
            }

            /* check if page present */
            if (frame & (1ULL << 63))
            {
                frame &= ((1ULL << 54) - 1);
                #if 0
                printf("page frame number 0x%llx\n", frame);
                #endif

                paddr = ((frame * psize) + (vaddr % psize));
            }
        }

        fclose( pFile );
    }

    return paddr;
}

int main(int argc, char *argv[])
{
    uintptr_t vaddr;
    uintptr_t paddr;
    int pid;


    if (argc != 3)
    {
        printf("Usage: pagemap PID VIRTUAL_ADDRESS\n\n");
        return 0;
    }

    pid = strtol(argv[1], NULL, 10);
    vaddr = strtol(argv[2], NULL, 16);

    printf("Page Size:\n%u\n\n", getpagesize());

    paddr = toPhysical(pid, vaddr);
    printf("Physical Address:\n");
    printf("%p -> [1;33m%p[0m\n\n", (void *)vaddr, (void *)paddr);

    return 0;
}

