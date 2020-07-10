#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *pNext;
};

typedef struct node node_t;

_Bool checkOrderNum(int *len, int *order);
void clearStdin();
node_t *addnode(node_t *pPrev);
node_t *vapaa(node_t *pAlku);
node_t *luolista(node_t *pAlku, int len, int *numCounter);
void tulosta(node_t *pAlku);
void addRemoveInPosition(node_t *pStart, int orderNum, int *numCounter,
                         char c);

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
                        case 1 : //Luo lista / Create List
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
                        case 2 : //Lisää alkio listan loppuun / Add to end
                                if (listLen == 0) break;
                                pCur = addnode(pCur);
                                pCur->data = numCounter + 1;
                                listLen++;
                                numCounter++;
                                tulosta(pStart);
                                break;
                        case 3 : //Lisää alkio listan keskelle / Add in position
                                printf("Monenneksi solmuksi alkio lisätään: ");
                                scanf(" %d", &orderNum);
                                clearStdin();
                                if (checkOrderNum(&listLen, &orderNum)) break;
                                addRemoveInPosition(pStart, orderNum,
                                                    &numCounter, '+');
                                listLen++;
                                break;
                        case 4 : //Tyhjennä lista / Clear list
                                pStart = vapaa(pStart);
                                listLen = 0;
                                break;
                        case 5 : //Poista alkio listasta / remove from position
                                printf("Monennesta solmusta "
                                       "alkio poistetaan: ");
                                scanf(" %d", &orderNum);
                                clearStdin();
                                if (checkOrderNum(&listLen, &orderNum)) break;
                                addRemoveInPosition(pStart, orderNum,
                                                    &numCounter, '-');
                                listLen--;
                                break;
                        case 6 : //Tulosta lista / print list
                                tulosta(pStart);
                                break;
                        case 0 : //Lopeta / Close
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

node_t *addnode(node_t *pPrev) {
        node_t *pNew = NULL;
        if (!(pNew = (node_t *)malloc(sizeof(node_t)))) {
                perror("Muistin varaus epäonnistui\n");
                exit(-1);
        }
        if (pPrev) {
                pPrev->pNext = pNew;
        }
        pNew->pNext = NULL;
        return pNew;
}

node_t *vapaa(node_t *pAlku) {
        node_t *ptr = NULL;
        while (pAlku) {
                ptr = pAlku->pNext;
                free(pAlku);
                pAlku = ptr;
        }
        return pAlku;
}

void tulosta(node_t *pAlku) {
        while (pAlku) {
                printf("%d ", pAlku->data);
                pAlku = pAlku->pNext;
        }
        printf("\n");
}

node_t *luolista(node_t *pAlku, int len, int *numCounter) {
        node_t *pCurrent = NULL;
        int i = 1;
        pAlku->data = (*numCounter) + 1;
        (*numCounter)++;
        while (i < len) {
                pCurrent = addnode(pAlku);
                pCurrent->data = *numCounter + 1;
                (*numCounter)++;
                i++;
                pAlku = pCurrent;
        }
        return pCurrent;
}

void addRemoveInPosition(node_t *pStart, int orderNum, int *numCounter,
                         char c) {
        int i = 0;
        node_t *ptrNext = NULL;
        node_t *ptr = NULL;
                while (i <  orderNum - 2) {
                        pStart = pStart->pNext;
                        i++;
                }
                ptrNext = pStart->pNext;
                if (c == '+') {
                        pStart = addnode(pStart);
                        pStart->pNext = ptrNext;
                        (*numCounter)++;
                        pStart->data = *numCounter;
                } else if (c == '-') {
                        ptr = ptrNext->pNext;
                        free(ptrNext);
                        pStart->pNext = ptr;
        }
}

void clearStdin() {
        while (1) {
                if (getchar() == '\n') break;
        }
}

_Bool checkOrderNum(int *len, int *order) {
        if (*order < 0) {
                printf("Järjestys ei voi olla "
                       "negatiivinen.\n" );
                return 1;
        }
        if (*order == 0) {
                printf("Järjestysnumeron pitää olla suurempi kuin nolla.\n" );
                return 1;
        }
        if (*order > *len) {
                printf("Liian iso järjestysnumero, "
                       "ei alkiota.\n");
                return 1;
        }
        return 0;
}
