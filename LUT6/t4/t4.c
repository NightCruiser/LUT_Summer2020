#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *pNext;
};

typedef struct node node_t;

int main(int argc, char *argv[]) {
        int valinta = 0;
        size_t listLen = 0;
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
                        case 1 :
                                printf("In Develompent\n");
                                break;
                        case 2 :
                                printf("In Develompent\n");
                                break;
                        case 3 :
                                printf("In Develompent\n");
                                break;
                        case 4 :
                                printf("In Develompent\n");
                                break;
                        case 5 :
                                printf("In Develompent\n");
                                break;
                        case 6 :
                                printf("In Develompent\n");
                                break;
                        case 0 :
                                printf("In Develompent\n");
                                break;
                        default:
                                printf("Tuntematon valinta.\n");

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
        return pNew;
}

void vapaa(node_t *pAlku) {
        node_t *ptr = NULL;
        while (pAlku != NULL) {
                ptr = pAlku->pNext;
                free(pAlku);
                pAlku = ptr;
        }
}
