#include <stdlib.h>
#include <stdio.h>
int *varaaMuistiaNumeroille(int size)
{
        int *ptr = NULL;
        int i = 0;
        if (!(ptr = (int *)malloc(size * sizeof(int)))) {
                perror("Muistin varaus epäonnistui!");
                exit(-1);
        }
        for (i = 0; i < size; i++) {
                ptr[i] = 0;
        }
        return ptr;
}

void vapautaMuisti(int *ptr)
{
        if (ptr) free(ptr);
}
