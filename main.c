#include <stdio.h>
#include <stdlib.h>
#include "hash_table.c"

int main(int argc, char *argv){

    char a = 'B';
    void *p = &a;
    printf("%d, %d", *(char *)p, *(char *)p);


    int num = hashfunction(p);
    printf(" %d", num);

    return 0;
}