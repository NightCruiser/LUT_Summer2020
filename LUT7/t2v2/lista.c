#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

node_t *addnode() {
        node_t *pNew = NULL;
        if (!(pNew = (node_t *)malloc(sizeof(node_t)))) {
                printf("Muistin varaus epäonnistui\n");
                exit(-1);
        }
        pNew->pNext = NULL;
        return pNew;
}

node_t *luoLista(node_t **pCur, int listLen, int *numCounter) {
        node_t *pPrev = NULL;
        node_t *pStart = NULL;

        pStart = *pCur = addnode();
        while (listLen > 0) {
                pPrev = *pCur;
                if (listLen > 1) *pCur = pPrev->pNext = addnode();
                pPrev->data = (*numCounter) + 1;
                listLen--;
                (*numCounter)++;
        }
        return pStart;
}

node_t *addInPos(node_t *pStart, int orderNum, int *numCounter) {
        node_t *tmpPtr = NULL;
        if (orderNum == 1) {
                tmpPtr = pStart;
                pStart = addnode();
                pStart->data = ++(*numCounter);
                pStart->pNext = tmpPtr;
                return pStart;
        }
        pStart = getPreviousPointer(pStart, orderNum);
        tmpPtr = pStart->pNext;
        pStart->pNext = addnode();
        pStart->pNext->data = ++(*numCounter);
        pStart->pNext->pNext = tmpPtr;
        return pStart->pNext;
}

node_t *rmFromPos(node_t *pStart, int orderNum, int *listLen) {
        node_t *tmpPtr = NULL;
        if (orderNum == 1) {
                tmpPtr = pStart->pNext;
                free(pStart);
                (*listLen)--;
                return tmpPtr;
        }
        pStart = getPreviousPointer(pStart, orderNum);
        tmpPtr = pStart->pNext->pNext;
        free(pStart->pNext);
        pStart->pNext = tmpPtr;
        listLen--;
        return pStart;
}

node_t *getPreviousPointer(node_t *pStart, int orderNum) {
        int i = 0;
        if (orderNum == 1 || orderNum == 2) return pStart;
        for (i = 2; i < orderNum; i++) {
                pStart = pStart->pNext;
        }
        return pStart;
}

node_t *addloppuun(node_t *pStart, int *listLen, int *numCounter){
        pStart->pNext = addnode();
        pStart->pNext->data = ++(*numCounter);
        (*listLen)++;
        return pStart->pNext;
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
