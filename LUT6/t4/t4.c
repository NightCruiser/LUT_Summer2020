#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *pNext;
};

typedef struct node node_t;

node_t *addnode(node_t *pPrev);
node_t *vapaa(node_t *pAlku);
void tulosta(node_t *pAlku);
node_t *luolista(node_t *pAlku, int len, int *i);

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
                while (1) {
                        if (getchar() == '\n') break;
                }
                switch (valinta) {
                        case 1 : //valmis
                                printf("Anna listan pituus: ");
                                scanf(" %d", &listLen);
                                while (1) {
                                        if (getchar() == '\n') break;
                                }
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
                        case 2 : //valmis
                                if (listLen == 0) break;
                                pCur = addnode(pCur);
                                pCur->data = numCounter + 1;
                                listLen++;
                                numCounter++;
                                tulosta(pStart);
                                break;
                        case 3 : //in progress
                                printf("Monenneksi solmuksi alkio lisätään: ");
                                scanf(" %d", &orderNum);
                                break;
                        case 4 : //valmis
                                pStart = vapaa(pStart);
                                listLen = 0;
                                break;
                        case 5 : //in progress
                                printf("Monennesta solmusta "
                                       "alkio poistetaan: ");
                                scanf(" %d", &orderNum);
                                while (1) {
                                        if (getchar() == '\n') break;
                                }

                                break;
                        case 6 : //valmis
                                tulosta(pStart);
                                break;
                        case 0 : //valmis
                                printf("Kiitos ohjelman käytöstä.\n");
                                pStart = vapaa(pStart);
                                break;
                        default: //valmis
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

node_t *luolista(node_t *pAlku, int len, int *i) {
        node_t *pCurrent = NULL;
        int localCounter = 1;
        pAlku->data = *i + 1;
        (*i)++;
        while (localCounter < len) {
                pCurrent = addnode(pAlku);
                pCurrent->data = *i + 1;
                (*i)++;
                localCounter++;
                pAlku = pCurrent;
        }
        return pCurrent;
}
