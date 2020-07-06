#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ajoneuvo {
        char ajoneuvo[15];
        int vuosimalli;
        struct Ajoneuvo *pNext;
};

typedef struct Ajoneuvo ajo_t;

ajo_t *structFromFile(FILE *pFile);
void structTulostaa(ajo_t *pAlku);
void muistivapaaminen(ajo_t *pAlku);

int main(int argc, char *argv[]) {
        ajo_t *pStart = NULL;
        FILE *tiedosto;

        if (argc < 2) {
                printf("Et antanut tiedoston nimeä.\n");
                return 0;
        }
        printf("Luetaan tiedot tiedostosta %s.\n", argv[1]);
        if (!(tiedosto = fopen(argv[1], "rt"))) {
                printf("Tiedoston avaus epäonnistui.\n");
                return 0;
        }

        pStart = structFromFile(tiedosto);
        fclose(tiedosto);
        structTulostaa(pStart);
        muistivapaaminen(pStart);

        return 0;
}

ajo_t *structFromFile(FILE *pFile) {
        char ajoneuvo[15];
        int vuosi = 0;
        ajo_t *pAlku = NULL;
        ajo_t *ptr = NULL;
        ajo_t *pPrev = NULL;

        while (fscanf(pFile, "%s" " %d", ajoneuvo, &vuosi) != EOF) {
                if (pAlku == NULL) {
                        if (!(pAlku = (ajo_t *)malloc(sizeof(ajo_t)))) {
                                perror("Muistinvaraus epäonnistui");
                                exit(-1);
                        }
                        ptr = pAlku;
                } else {
                        pPrev = ptr;
                        if (!(ptr = (ajo_t *)malloc(sizeof(ajo_t)))) {
                                perror("Muistinvaraus epäonnistui");
                                exit(-1);
                        }
                }
                if (pPrev != NULL) {
                        pPrev->pNext = ptr;
                }
                strcpy(ptr->ajoneuvo, ajoneuvo);
                ptr->vuosimalli = vuosi;
                ptr->pNext = NULL;
        }
        printf("Tiedot luettu linkitettyyn listaan.\n");
        return pAlku;
}

void structTulostaa(ajo_t *pAlku) {
        char i = 1;
        if (pAlku == NULL) {
                printf("Ajoneuvoja ei löytynyt.\n");
                exit(0) ;
        }
        while (pAlku->pNext != NULL) {
                printf("%d. ajoneuvo: %s vuosimalli %d.\n",
                        i, pAlku->ajoneuvo, pAlku->vuosimalli);
                i++;
                pAlku = pAlku->pNext;
        }
        printf("%d. ajoneuvo: %s vuosimalli %d.\n",
                i, pAlku->ajoneuvo, pAlku->vuosimalli);
}

void muistivapaaminen(ajo_t *pAlku) {
        ajo_t *pCur = NULL;
        while (pAlku != NULL) {
                pCur = pAlku;
                pAlku = pAlku->pNext;
                free(pCur);
        }
        printf("Muisti vapautettu.\n");
}
