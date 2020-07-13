#ifndef LISTA_H
#define LISTA_H

struct node {
        int data;
        struct node *pNext;
};

typedef struct node node_t;
node_t *rmFromPos(node_t *pStart, int orderNum, int *listLen);
node_t *addInPos(node_t *pStart, int orderNum, int *numCounter);
node_t *addloppuun(node_t *pStart, int *listLen, int *numCounter);
node_t *getPreviousPointer(node_t *pStart, int orderNum);
node_t *addnode();
node_t *luoLista(node_t **, int, int *);
_Bool checkOrderNum(int *, int *);
void clearStdin();
node_t *vapaa(node_t *);
void tulosta(node_t *);
#endif /*LISTA_H*/
