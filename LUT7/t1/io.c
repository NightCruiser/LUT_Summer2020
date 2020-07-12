#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

int lue_askeleet_listaan(int *lista, int len) {
        int summa = 0;
        char buffer[LEN];
        FILE *pFile = NULL;
        int i = 0;

        if (!(pFile = fopen("./askeldata.txt","rt"))) {
                perror("askeldata.txt");
                exit(-1);
        }

        while (len > 0) {
                int counter = 0;

                fgets(buffer, LEN, pFile);
                while (buffer[counter] != ':') {
                        counter++;
                }
                sscanf(buffer + counter, ":%d", &lista[i]);
                summa += lista[i];
                i++;
                len--;
        }
        fclose(pFile);
        return summa;
}


void tulosta_lista(int *lista, int len) {
        int  i = 0;
        while(i < len) {
                printf("%d ", lista[i]);
                i++;
        }
        printf("\n");
}
