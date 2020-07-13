#include <stdio.h>
#include "lista.h"

int main(int argc, char *argv[]) {
        int valinta = 0;
        int listLen = 0;
        int prevLen = 0;
        int orderNum = 0;
        int numCounter = 0;
        node_t *pStart = NULL;
        node_t *pCur = NULL;

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
                                pStart = addnode(pStart);
                                pCur = luolista(pStart, listLen, &numCounter);
                                tulosta(pStart);
                                prevLen = listLen;
                                break;
                        case 2 : //Lisää alkio listan loppuun
                                if (listLen == 0) break;
                                pCur = addnode(pCur);
                                pCur->data = numCounter + 1;
                                listLen++;
                                numCounter++;
                                tulosta(pStart);
                                break;
                        case 3 : //Lisää alkio listan keskelle
                                printf("Monenneksi solmuksi alkio lisätään: ");
                                scanf(" %d", &orderNum);
                                clearStdin();
                                if (checkOrderNum(&listLen, &orderNum)) break;
                                addRemoveInPosition(pStart, orderNum,
                                                    &numCounter, '+');
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
                                if (checkOrderNum(&listLen, &orderNum)) break;
                                if (orderNum == 1) {
                                        node_t *tmp = pStart;
                                        pStart = addnode(pStart);
                                        pStart->pNext = tmp;
                                        pStart->data = numCounter;
                                } else {
                                        addRemoveInPosition(pStart, orderNum,
                                                            &numCounter, '-');
                                }
                                listLen--;
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
