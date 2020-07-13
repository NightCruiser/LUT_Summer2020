#include <stdio.h>
#include "lista.h"

int main(int argc, char *argv[]) {
        node_t *pStart = NULL;
        node_t *pCur = NULL;
        int valinta = 0;
        int listLen = 0;
        int prevLen = 0;
        int numCounter = 0;
        int orderNum = 0;

        printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");
        do {
                printf("1) Luo lista\n"
                       "2) Lisää alkio listan loppuun\n"
                       "3) Lisää alkio listan keskelle\n"
                       "4) Tyhjennä lista\n"
                       "5) Poista alkio listasta\n"
                       "6) Tulosta lista\n"
                       "0) Lopeta\n"
                       "Anna valintasi: ");
                scanf(" %d", &valinta);
                clearStdin();
                switch (valinta) {
                        case 1 : //Luo lista
                                printf("Anna listan pituus: ");
                                scanf(" %d", &listLen);
                                clearStdin();
                                if (listLen < 0) {
                                        printf("Listan pituus ei voi olla "
                                               "negatiivinen.\n");
                                        listLen = prevLen;
                                        break;
                                }
                                if (pStart) pStart = vapaa(pStart);
                                pStart = luoLista(&pCur, listLen, &numCounter);
                                tulosta(pStart);
                                prevLen = listLen;
                                break;
                        case 2 : //Lisää alkio listan loppuun
                                if (listLen == 0) break;
                                pCur = addloppuun(pCur, &listLen, &numCounter);
                                tulosta(pStart);
                                break;
                        case 3 : //Lisää alkio listan keskelle
                                printf("Monenneksi solmuksi alkio lisätään: ");
                                scanf(" %d", &orderNum);
                                clearStdin();
                                if (orderNum - listLen == 1) {
                                        pCur = addloppuun(pCur, &listLen,
                                                                 &numCounter);
                                        tulosta(pStart);
                                        break;
                                }
                                if (checkOrderNum(&listLen, &orderNum)) break;
                                if (orderNum == 1) {
                                        pStart = addInPos(pStart, orderNum,
                                                          &numCounter);

                                } else {
                                        addInPos(pStart, orderNum,
                                                 &numCounter);
                                }
                                listLen++;
                                tulosta(pStart);
                                break;
                        case 4 : //Tyhjennä lista
                                pStart = vapaa(pStart);
                                listLen = 0;
                                break;
                        case 5 : //Poista alkio listasta
                                printf("Monennesta solmusta "
                                       "alkio poistetaan: ");
                                scanf(" %d", &orderNum);
                                clearStdin();
                                if (orderNum == 1) {
                                        pStart = rmFromPos(pStart, orderNum,
                                                           &listLen);
                                        break;
                                }
                                if (checkOrderNum(&listLen, &orderNum)) break;
                                rmFromPos(pStart, orderNum, &listLen);
                                break;
                        case 6 : //Tulosta lista
                                tulosta(pStart);
                                break;
                        case 0 : //Lopeta
                                printf("Kiitos ohjelman käytöstä.\n");
                                pStart = vapaa(pStart);
                                break;
                        default:
                                printf("Tuntematon valinta, "
                                       "yritä uudestaan.\n");
                }
        } while (valinta != 0);
        return 0;
}
