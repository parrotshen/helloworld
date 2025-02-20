#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>


#define IGNORE_SIGPIPE 1


void *thread_server(void *arg)
{
    struct sockaddr_in  addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    unsigned char buf[128];
    int option;
    int fd_server = -1;
    int fd = -1;

    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    if ((fd_server = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror( "socket" );
        goto _EXIT1;
    }

    option = 1;
    if (setsockopt(fd_server, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0)
    {
        perror( "setsockopt" );
        goto _EXIT1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons( 50168 );
    addr.sin_addr.s_addr = htonl( INADDR_ANY );
    if (bind(fd_server, (struct sockaddr *)&addr, addr_len) < 0)
    {
        perror( "bind" );
        goto _EXIT1;
    }

    if (listen(fd_server, 16) < 0)
    {
        perror( "listen" );
        goto _EXIT1;
    }

    printf("TCP server listen\n");

    if ((fd = accept(fd_server, NULL, NULL)) < 0)
    {
        perror( "accept" );
        goto _EXIT1;
    }

    sleep(3);

    printf("TCP server 1st send\n");
    memset(buf, 0x11, 128);
    if (write(fd, buf, 128) <= 0) perror( "write" );

    sleep(1);

    printf("TCP server 2nd send\n");
    memset(buf, 0x22, 128);
    if (write(fd, buf, 128) <= 0) perror( "write" );

    sleep(1);

    printf("TCP server 3th send\n");
    memset(buf, 0x33, 128);
    if (write(fd, buf, 128) <= 0) perror( "write" );

    printf("TCP server closed\n");

_EXIT1:
    if (fd_server >= 0) close( fd_server );
    if (fd >= 0) close( fd );
    pthread_exit(NULL);
}

void *thread_client(void *arg)
{
    struct sockaddr_in  addr;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    int option;
    int fd = -1;

    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    if ((fd=socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror( "socket" );
        goto _EXIT2;
    }

    option = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0)
    {
        perror( "setsockopt" );
        goto _EXIT2;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons( 0 );
    addr.sin_addr.s_addr = htonl( INADDR_ANY );
    if (bind(fd, (struct sockaddr *)&addr, addr_len) < 0)
    {
        perror( "bind" );
        goto _EXIT2;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons( 50168 );
    addr.sin_addr.s_addr = inet_addr( "127.0.0.1" );
    if (connect(fd, (struct sockaddr *)&addr, addr_len) < 0)
    {
        perror( "connect" );
        goto _EXIT2;
    }

    printf("TCP client connected\n");
    sleep(1);
    printf("TCP client closed\n");

_EXIT2:
    if (fd >= 0) close( fd );
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t thread[2];
    pthread_attr_t tattr;


    printf("broken_pipe: start\n");

    #if (IGNORE_SIGPIPE)
    signal(SIGPIPE, SIG_IGN);
    #endif

    pthread_attr_init( &tattr );
    pthread_attr_setdetachstate(&tattr, PTHREAD_CREATE_JOINABLE);
    if (pthread_create(&(thread[0]), &tattr, thread_server, NULL) != 0)
    {
        printf("ERR: fail to create TCP server thread\n");
        perror( "pthread_create" );
    }
    pthread_attr_destroy( &tattr );

    pthread_attr_init( &tattr );
    pthread_attr_setdetachstate(&tattr, PTHREAD_CREATE_JOINABLE);
    if (pthread_create(&(thread[1]), &tattr, thread_client, NULL) != 0)
    {
        printf("ERR: fail to create TCP client thread\n");
        perror( "pthread_create" );
    }
    pthread_attr_destroy( &tattr );


    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    printf("broken_pipe: end\n");
    return 0;
}

