#include <stdio.h>
#include <stdlib.h>


int tarkistaNumero(int *ptr, int numero, int size)
{
        int i = 0;
        for (i = 0; i < size; i++) {
                if (ptr[i] == numero) return 1;
        }
        return (0);
}

void arvoNumerot(int *ptr, int size)
{
        int i = 0;
        int num = 0;
        srand(40);
        for (i = 0; i < size; i++) {
                do {
                        num = rand() % 38;
                } while (tarkistaNumero(ptr, num, size));
                ptr[i] = num;
        }
}

void tulostaNumerot(int *ptr, int size)
{
        int i = 0;
        for (i = 0; i < size; i++) {
                printf("%d ", ptr[i]);
        }
        printf("\n");
}
