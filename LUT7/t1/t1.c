#include <stdio.h>
#include "io.h"

int main(int argc, char *argv[]) {
        int askList[SIZE] = {0};
        int summa = 0;

        summa = lue_askeleet_listaan(askList, SIZE);
        printf("Askelanalyysi\n"
               "Listan askeleet: ");
        tulosta_lista(askList, SIZE);
        printf("Askelia yhteensä: %d\n", summa);
        return 0;
}
