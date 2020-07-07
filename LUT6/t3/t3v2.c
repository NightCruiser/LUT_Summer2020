#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *pNext;
};

typedef struct node node_t;
node_t *initList(node_t *pAlku, int Len);
void vapaa(node_t *pAlku);
void tulosta(node_t *pAlku);

int main(int argc, char *argv[]) {
        node_t *pStart = NULL;
        int valinta = 0;
        int prevLen = 0;
        int listLen = 0;

        do {
                printf("1) Tulosta listan alkiot\n"
                       "2) Muuta listan pituutta\n"
                       "0) Lopeta\n"
                       "Anna valintasi: ");
                scanf(" %d", &valinta);
                while(1) {
                        if (getchar() == '\n') break;
                }
                switch (valinta) {
                        case 1 :
                                if (pStart == NULL) {
                                        printf("Lista on tyhjä.\n");
                                        break;
                                }
                                tulosta(pStart);
                                break;
                        case 2 :
                                if (pStart != NULL) {
                                        vapaa(pStart);
                                        pStart = NULL;
                                }
                                printf("Anna listan uusi pituus: ");
                                scanf(" %d", &listLen);
                                while(1) {
                                        if (getchar() == '\n') break;
                                }
                                if (listLen < 0) {
                                        printf("Listan pituus ei voi olla "
                                               "negatiivinen.\n");
                                               listLen = prevLen;
                                               break;
                                }
                                if (listLen == 0) {
                                        vapaa(pStart);
                                        pStart = NULL;
                                        break;
                                }
                                pStart = initList(pStart, listLen);
                                prevLen = listLen;
                                break;
                        case 0 :
                                if (pStart != NULL) {
                                        vapaa(pStart);
                                }
                                printf("Kiitos ohjelman käytöstä.\n");
                                break;
                        default:
                                printf("Tuntematon valinta, "
                                       "yritä uudestaan.\n");
                }
        } while (valinta != 0);
        return 0;
}

node_t *initList(node_t *pAlku, int Len) {
        node_t *pCur = NULL;
        node_t *pPrev = NULL;
        int  i = 0;
        for (i = 0; i < Len; i++) {
                if (!(pCur = (node_t *)malloc(sizeof(node_t)))) {
                        perror("Muistin varaus epäonnistui");
                        exit(0);
                }
                if (pAlku == NULL) pAlku = pCur;
                if (pPrev != NULL) pPrev->pNext = pCur;
                pCur->data = i;
                pCur->pNext = NULL;
                pPrev = pCur;
        }
        return pAlku;
}

void vapaa(node_t *pAlku) {
        node_t *pCur = NULL;
        while (pAlku != NULL) {
                pCur = pAlku;
                pAlku = pAlku->pNext;
                free(pCur);
        }
}

void tulosta(node_t *pAlku) {
        printf("Listassa on seuraavat luvut: \n");
        while(pAlku != NULL) {
                printf("%d ", pAlku->data);
                pAlku = pAlku->pNext;
        }
        printf("\n");
}
