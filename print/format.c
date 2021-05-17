#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ch;

    if (argc < 2)
    {
        printf("Usage: format [-f] [-w WIDTH]\n\n");
        return 0;
    }

    opterr = 0;
    while ((ch=getopt(argc, argv, "fw:")) != -1)
    {
        switch ( ch )
        {
            case 'f':
            {
                printf("printf(\"%%[1;31m-[0m8s\\n\", \"Hello\");\n");
                printf("\"%-8s\"\n\n", "Hello");
                printf("printf(\"%%[1;31m08[0md\\n\", 1);\n");
                printf("\"%08d\"\n\n", 1);
                printf("printf(\"%%[1;31m#[0mx\\n\", \"6512\");\n");
                printf("\"%#x\"\n\n", 6512);
                break;
            }
            case 'w':
            {
                int width = atoi( optarg );
                printf("printf(\"%%[1;31m.*[0ms\\n\", [1;33m%d[0m, \"123456789\");\n", width);
                printf("\"%.*s\"\n\n", width, "123456789");
                break;
            }
            default:
            {
                ;
            }
        }
    }

    return 0;
}
