#include <stdio.h>
#include "muisti.h"
#include "io.h"

int getValinta();

int main(int argc, char *argv[])
{
        int valinta = 0;
        int lisaNum = 0;
        int *numArray = NULL;
        int *lisaArray = NULL;

        printf("Lottoarvonta\n"
               "Kuinka monta numeroa arvotaan: ");
        valinta = getValinta();
        printf("Kuinka monta lisänumeroa arvotaan: ");
        lisaNum = getValinta();

        numArray = varaaMuistiaNumeroille(valinta);
        lisaArray = varaaMuistiaNumeroille(lisaNum);

        arvoNumerot(numArray, valinta);
        arvoNumerot(lisaArray, lisaNum);

        printf("\nArvottiin seuraavat numerot ja lisänumerot.\n"
               "Numerot: ");
        tulostaNumerot(numArray, valinta);
        printf("Lisänumerot: ");
        tulostaNumerot(lisaArray, lisaNum);

        vapautaMuisti(numArray);
        vapautaMuisti(lisaArray);

        return 0;
}

int getValinta()
{
        int valinta = 0;
        do {
                scanf(" %d", &valinta);
                while (1) {
                        if (getchar() == '\n') break;
                }
                if (valinta > 37 || valinta < 0) {
                        printf("Valinta pitäisi olla suuremmaksi 37 "
                               "ja pienemmaksi 0\n");
                }
        } while (valinta > 37 || valinta < 0 );
        return valinta;
}
