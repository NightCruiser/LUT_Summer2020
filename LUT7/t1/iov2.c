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
                exit(0);
        }

        while (i < 10 && fgets(buffer, LEN, pFile) != NULL) {
                strtok(buffer, ":");
                lista[i] = atoi(strtok(NULL, "\n"));
                summa += lista[i];
                i++;
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
