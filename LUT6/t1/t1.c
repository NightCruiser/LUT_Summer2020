#include <stdio.h>
#include <stdlib.h>

struct Node {
        int data;
        struct Node *pNext;
};

typedef struct Node node_t;

int main(int argc, char *argv[]) {
        node_t *pStart = NULL;
        node_t *pCurrent = NULL;
        node_t *pPrevious = NULL;
        int valinta = 0;

        printf("Anna listan luvut.\n");

        do {
                printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
                scanf(" %d", &valinta);
                while (1) {
                        if (getchar() == '\n') break;
                }
                switch(valinta) {
                        case 0 :
                                printf("Listassa on seuraavat luvut: ");
                                pCurrent = pStart;
                                while(pCurrent != NULL) {
                                        printf("%d ", pCurrent->data);
                                        pCurrent = pCurrent->pNext;
                                }

                                while(pStart != NULL) {
                                        pCurrent = pStart;
                                        pStart = pCurrent->pNext;
                                        free(pCurrent);
                                }

                                printf("\nKiitos ohjelman käytöstä.\n");
                                break;
                        default :
                                pPrevious = pCurrent;
                                if ((pCurrent = (node_t *)malloc(sizeof(node_t))
                                    )== NULL) {
                                        perror("Muistinvaraus epäonnistui");
                                        exit(-1);
                                }
                                if (pStart == NULL) {
                                        pStart = pCurrent;
                                }
                                pCurrent->data = valinta;
                                pCurrent->pNext = NULL;
                                if (pPrevious) {
                                        pPrevious->pNext = pCurrent;
                                }
                }
        } while (valinta != 0);
        return 0;
}
