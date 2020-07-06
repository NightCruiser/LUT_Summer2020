#include <stdio.h>
#include <stdlib.h>
#define VAR 2

#if VAR == 1

struct Node {

        int iluku ;
        struct Node *pNext ;
} ;

typedef struct Node Solmu ;

int main(int argc, char *argv[]) {

        Solmu *pAlku = NULL, *pLoppu = NULL, *ptr ;
        int i ;
/*listan luonti*/
        for( i = 0 ; i < 10 ; i++ ) {
/*Muistin Varaus*/
                if ((ptr = (Solmu *)malloc(sizeof(Solmu))) == NULL) {
                        perror("Varaus epa\n") ;
                        exit(1);
        }
        /*Solmun Alustus*/
        ptr->iluku = i ;
        ptr->pNext = NULL ;
        /*Uuden alkion lisays listaan*/
        if (pAlku == NULL) {
            pAlku = ptr;
            pLoppu = ptr;
        } else {
            pLoppu->pNext = ptr;
            pLoppu = ptr;
        }

    }

    /*Listan lapikaynti*/
    ptr = pAlku;
    while( ptr != NULL ) {
        printf( "%d \n", ptr->iluku );
        ptr = ptr->pNext;
    }
    /* Muistin vapautus */
    ptr = pAlku;
    while( ptr != NULL ) {
        pAlku = ptr->pNext ;
        free(ptr);
        ptr = pAlku;
    }


    printf( "Kiitos ohjelman k'yt;st'.\n" ) ;

    return 0 ;
}
#endif //VAR 1
#if VAR == 2
struct Node {

    int iluku ;
    struct Node *pNext ;
} ;

typedef struct Node Solmu ;
Solmu *solmuLisaa( Solmu *pA, int i ) {

    Solmu *ptr, *ptrUusi;

    /*muistin varaus*/
    if ((ptrUusi = (Solmu*)malloc(sizeof(Solmu))) == NULL) {
        perror("Varaus epa") ;
        exit(1);
    }
/*solman alustus*/
    ptrUusi->iluku = i ;
    ptrUusi->pNext = NULL ;

    /*Uuden alkion lisays listaan*/
    if(pA == NULL) {
        pA = ptrUusi;

    } else {
        ptr = pA;
        while( ptr->pNext != NULL ) {
            ptr = ptr->pNext;
        }
        ptr->pNext = ptrUusi;
    }
    return pA;
}
void tulosta( Solmu *pA ) {

    /*Listan lapikaynti*/
    Solmu *ptr = pA;
    while( ptr != NULL ) {
        printf( "%d \n", ptr->iluku );
        ptr = ptr->pNext;
    }

}

Solmu *tyhjenna( Solmu *pA ) {

    /* Muistin vapautus */
    Solmu *ptr = pA;
    while( ptr != NULL ) {
        pA = ptr->pNext ;
        free(ptr);
        ptr = pA;
    }
    return pA;
}

int main( int argc, char *argv[] ) {

    Solmu *pAlku = NULL ;
    int i ;
    /*Listan luominen */
    for( i=0; i<10; i++ ) {
        pAlku = solmuLisaa( pAlku, i ) ;
    }
    /*listan lapikaynti*/
    tulosta(pAlku) ;
    /*muistin vapauttaminen*/
    pAlku = tyhjenna(pAlku) ;

    printf( "Kiitos ohjelman k'yt;st'.\n" ) ;

    return 0 ;
}


#endif //VAR 2
