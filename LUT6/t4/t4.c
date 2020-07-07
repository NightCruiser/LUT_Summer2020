include <stdio.h>
include <stdlib.h>

struct node {
        int data;
        struct node *pNext;
};

typedef struct node node_t;

int main(int argc, char *argv[]) {
        int valinta = 0;
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
                                break;
                        case 2 :
                                break;
                        case 3 :
                                break;
                        case 4 :
                                break;
                        case 5 :
                                break;
                        case 6 :
                                break;
                        case 0 :
                                break;
                        default:

                }
        } while (valinta != 0);
        return 0;
}
