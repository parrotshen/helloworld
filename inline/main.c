#include <stdio.h>

static inline int test1(int i)
{
    int j = 0;

_LABEL_T11:
    j = i + i;

_LABEL_T12:
    printf("_LABEL_T11 at [1;33m%p[0m\n", &&_LABEL_T11);
    printf("_LABEL_T12 at [1;33m%p[0m\n", &&_LABEL_T12);
    return j;
}

int test2(int i)
{
    int j = 0;

_LABEL_T21:
    j = i * i;

_LABEL_T22:
    printf("_LABEL_T21 at [1;36m%p[0m\n", &&_LABEL_T21);
    printf("_LABEL_T22 at [1;36m%p[0m\n", &&_LABEL_T22);
    return j;
}

int main(void)
{
    int i = 168;

_LABEL_M01:
    test1( i );
    printf("\n");

_LABEL_M02:
    test2( i );
    printf("\n");

_LABEL_M03:
    test1( i );
    printf("\n");

_LABEL_M04:
    test2( i );
    printf("\n");

_LABEL_M05:
    printf("_LABEL_M01 at %p\n", &&_LABEL_M01);
    printf("_LABEL_M02 at %p\n", &&_LABEL_M02);
    printf("_LABEL_M03 at %p\n", &&_LABEL_M03);
    printf("_LABEL_M04 at %p\n", &&_LABEL_M04);
    printf("_LABEL_M05 at %p\n", &&_LABEL_M05);
    return 0;
}

