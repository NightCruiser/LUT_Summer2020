#ifndef LISTA_H
#define LISTA_H

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
#endif /*LISTA_H*/
