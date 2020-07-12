#include <stdio.h>
#include <stdlib.h>
#include "hdrf.h"

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
