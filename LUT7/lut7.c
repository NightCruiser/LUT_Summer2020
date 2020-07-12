#include <stdio.h>
#include <stdlib.h>
#include "hdrf.h"


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
