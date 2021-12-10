#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int ch;

    if (argc < 2)
    {
        printf("Usage: format [-f] [-p] [-w WIDTH]\n\n");
        return 0;
    }

    opterr = 0;
    while ((ch=getopt(argc, argv, "fpw:")) != -1)
    {
        switch ( ch )
        {
            case 'f':
            {
                printf("printf(\"[1;31m%%-16s[0m\\n\", \"Hello\");\n");
                printf("[7m%-16s[27m\n\n", "Hello");
                printf("printf(\"[1;31m%%016d[0m\\n\", 1);\n");
                printf("[7m%016d[27m\n\n", 1);
                printf("printf(\"[1;31m%%#x[0m\\n\", 6512);\n");
                printf("[7m%#x[27m\n\n", 6512);
                break;
            }
            case 'p':
            {
                printf("printf(\"[1;31m%%p[0m\\n\", &ch);\n");
                printf("[7m%p[27m\n\n", &ch);
                break;
            }
            case 'w':
            {
                int width = atoi( optarg );
                printf(
                    "printf(\"[1;31m%%.*s[0m\\n\", [1;33m%d[0m, \"123456789\");\n",
                    width
                );
                printf("[7m%.*s[27m\n\n", width, "123456789");
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
