#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

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
