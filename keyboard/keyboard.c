#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


char g_buf[256];

int main(int argc, char *argv[])
{
    char *pDevice = "/dev/input/event0";
    struct input_event ev;
    fd_set flags;
    int fd;
    int rc;


    if (argc > 1) pDevice = argv[1];

    fd = open(pDevice, O_RDONLY);
    if (fd < 0)
    {
        perror( "open" );
        return 0;
    }

    printf("Enter 'exit' to terminate ...\n\n");

    FD_ZERO( &flags );
    while ( 1 )
    {
        FD_CLR(0,  &flags);
        FD_CLR(fd, &flags);
        FD_SET(0,  &flags);
        FD_SET(fd, &flags);

        rc = select((fd + 1), &flags, NULL, NULL, NULL);
        if (rc > 0)
        {
            if (FD_ISSET(0, &flags))
            {
                if (read(0, g_buf, sizeof(g_buf)) > 0)
                {
                    if (0 == strncmp("exit", g_buf, 4)) break;
                }
            }

            if (FD_ISSET(fd, &flags))
            {
                if (read(fd, &ev, sizeof(struct input_event)) > 0)
                {
                    if (EV_KEY == ev.type)
                    {
                        printf(
                            "key[ %i ] %s\n",
                            ev.code,
                            (0 == ev.value) ? "release" :
                            (1 == ev.value) ? "press" : "hold"
                        );
                    }
                }
            }
        }
        else if (0 == rc)
        {
            /* timeout */
            ;
        }
        else
        {
            perror( "select" );
            break;
        }
    }

    close( fd );

    return 0;
}

