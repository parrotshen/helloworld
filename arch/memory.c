#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <errno.h>

/*
* High address +===================+
*              |    Environment    | Command-line arguments
*              |                   | and environment variables
*              +===================+
*              |       Stack       |
*              |- - - - - - - - - -|
*              |         |         |
*              |         v         |
*              |                   |
*              |                   |
*              |         ^         |
*              |         |         |
*              |- - - - - - - - - -|
*              |        Heap       |
*              +===================+
*              |        BSS        | Un-initialized data
*              +===================+
*              |        Data       | Initialized data
*              +-------------------+
*              |        Text       |
*              |                   |
* Low address  +===================+
*/


char g_string[] = "Hello world !!\n";

void *get_ebp(void)
{
    asm("mov (%ebp), %eax");
}

unsigned long vtop(unsigned long vaddr)
{
#define PAGEMAP_ENTRY (8)
    unsigned long paddr = 0;
    unsigned long long pfn = 0;
    unsigned long offset;
    unsigned long psize;
    FILE *pagemap;

    /* https://www.kernel.org/doc/Documentation/vm/pagemap.txt
     *
     * Bits 0-54  page frame number (PFN) if present
     * Bits 0-4   swap type if swapped
     * Bits 5-54  swap offset if swapped
     * Bit  55    pte is soft-dirty (see Documentation/vm/soft-dirty.txt)
     * Bit  56    page exclusively mapped (since 4.2)
     * Bits 57-60 zero
     * Bit  61    page is file-page or shared-anon (since 3.5)
     * Bit  62    page swapped
     * Bit  63    page present
     */
    pagemap = fopen("/proc/self/pagemap", "rb");
    if ( !pagemap )
    {
        perror( "fopen" );
        return 0;
    }

    psize = sysconf(_SC_PAGESIZE);
    offset = (vaddr / psize * PAGEMAP_ENTRY);

    if (fseek(pagemap, offset, SEEK_SET) != 0)
    {
        perror( "fseek" );
        fclose( pagemap );
        return 0;
    }

    if (fread(&pfn, PAGEMAP_ENTRY, 1, pagemap) != 1)
    {
        perror( "fread" );
        fclose( pagemap );
        return 0;
    }

    /* check if page present */
    if (pfn & (1ULL << 63))
    {
        pfn &= ((1ULL << 54) - 1);
        #if 0
        printf("page frame number 0x%llx\n", pfn);
        #endif
        paddr = ((pfn * psize) + (vaddr % psize));
    }

    fclose( pagemap );

    return paddr;
}

void dump(const void *pAddr, unsigned int size, int verbose)
{
    unsigned char *pByte = (unsigned char *)pAddr;
    int num;
    int i;

    if ( verbose )
    {
        if (pAddr == NULL)
        {
            printf("NULL\n\n");
            return;
        }

        num = ((size + (4 - 1)) / 4);
        for (i=0; i<num; i++)
        {
            printf(
                "%p : %02x %02x %02x %02x\n",
                pByte,
                pByte[0],
                pByte[1],
                pByte[2],
                pByte[3]
            );
            pByte += 4;
        }
    }
    printf("\n");
}

/*
*  cat /proc/$PID/maps
*
*  address            perms  offset    dev    inode  pathname
*  08048000-08056000  r-xp   00000000  03:0c  64593  /usr/sbin/gpm
*/
int main(int argc, char *argv[])
{
    static void *pAlloc;
    uintptr_t addr1;
    uintptr_t addr2;
    uintptr_t addr3;
    uintptr_t addr4;
    uintptr_t addr5;
    uintptr_t addr6;
    uintptr_t addr7;
    uintptr_t addr8;
    int verbose = 0;
    int hold = 0;
    char command[80];


    if (argc > 1)
    {
        verbose = atoi( argv[1] );
        if (argc > 2)
        {
            hold = atoi( argv[2] );
        }
    }

    printf("[1] Text segment\n");
    {
        addr1 = vtop( (uintptr_t)main );
        addr2 = vtop( (uintptr_t)printf );

        printf("printf() -> %p (%p)\n", printf, (void *)addr2);
        printf("main()   -> %p (%p)\n", main, (void *)addr1);
        dump(main, 32, verbose);
    }


    printf("[2] Initialized data segment\n");
    {
        addr3 = vtop( (uintptr_t)g_string );

        printf("g_string -> %p (%p)\n", g_string, (void *)addr3);
        dump(g_string, sizeof(g_string), verbose);
    }


    printf("[3] Un-initialized data segment\n");
    {
        addr4 = vtop( (uintptr_t)&pAlloc );

        printf("&pAlloc  -> %p (%p)\n", &pAlloc, (void *)addr4);
        dump(&pAlloc, 16, verbose);
    }


    printf("[4] Heap\n");
    pAlloc = malloc( 32 );
    if ( pAlloc )
    {
        int i;

        addr5 = vtop( (uintptr_t)pAlloc );

        for (i=0; i<32; i++)
        {
            ((unsigned char *)pAlloc)[i] = (i + 1);
        }

        printf("pAlloc   -> %p (%p)\n", pAlloc, (void *)addr5);
        dump(pAlloc, 32, verbose);

        free( pAlloc );
    }


    printf("[5] Stack\n");
    {
        addr6 = vtop( (uintptr_t)&addr1 );
        addr7 = vtop( (uintptr_t)get_ebp() );

        printf("&addr1   -> %p (%p)\n", &addr1, (void *)addr6);
        printf("EBP      -> %p (%p)\n", get_ebp(), (void *)addr7);
        dump(&addr1, 16, verbose);
    }


    printf("[6] Environment\n");
    {
        addr8 = vtop( (uintptr_t)&argc );

        printf("&argc    -> %p (%p)\n", &argc, (void *)addr8);
        dump(&argc, 16, verbose);
    }


    printf("\n");
    printf("PID: %d\n", getpid());
    sprintf(command, "cat /proc/%d/maps", getpid());
    system( command );
    printf("\n");

    if ( hold )
    {
        printf("Press ENTER to continue ...\n");
        getchar();
    }

    return 0;
}

