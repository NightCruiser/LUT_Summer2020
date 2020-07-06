#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HLOLIM

struct Henkilo {

    char nimi[30] ;
    int ika ;
} ;

typedef struct Henkilo _hlo ;

void taytaStructHenkilo( _hlo *pStruct, char *str ) ;
_hlo *varaaMuisti(int size) ;
/*void kopioikaikki( void *ptrMista, void *ptrMihin, int size ) ;*/
_Bool kopioiJaVerrtailuHloStruct( _hlo *pMihin, _hlo *pMista ) ;
_Bool vertailu( _hlo *pStruct1, _hlo *pStruct2 ) ;

int main( int argc, char *argv[] ) {

    _hlo hlo1 ;
    _hlo hlo2 ;
    _hlo *pHlo3 ;

    taytaStructHenkilo( &hlo1, "ensimmäisen" ) ;
    taytaStructHenkilo( &hlo2, "toisen" ) ;

    vertailu( &hlo1, &hlo2 ) ?
                             printf( "Annetut tiedot ovat samoja.\n" )
                             :
                             printf( "Annetut tiedot eivät ole samoja.\n" ) ;

    pHlo3 = varaaMuisti( sizeof( _hlo ) ) ;

    /*kopioikaikki( &hlo1, pHlo3, sizeof( _hlo ) ) ;*/
    kopioiJaVerrtailuHloStruct( pHlo3, &hlo1 ) ?
                                    printf( "Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n" )
                                    :
                                    printf( "Kopioinnin jälkeen tietueiden tiedot eivät ole samoja.\n" ) ;

    &hlo1 == pHlo3 ?
                  printf( "Kopioinnin jälkeen tietueiden osoitteet ovat samoja.\n" )
                  :
                  printf( "Kopioinnin jälkeen tietueiden osoitteet eivät ole samoja.\n" ) ;

    printf( "Kiitos ohjelman käytöstä.\n" ) ;

    free( pHlo3 ) ;

    return 0 ;
}

void taytaStructHenkilo( _hlo *pStruct, char *str ) {

    printf( "Anna %s henkilön etunimi: ", str ) ;
    scanf( "%s", pStruct->nimi ) ;
    getchar() ;
    printf( "Anna %s henkilön ikä: ", str ) ;
    scanf( " %d", &pStruct->ika ) ;
    getchar() ;

}

_Bool kopioiJaVerrtailuHloStruct( _hlo *pMihin, _hlo *pMista ) {

    _Bool result = 0 ;

    strcpy( pMihin->nimi, pMista->nimi )
    &&
    ( strcmp( pMihin->nimi, pMista->nimi ) ) == 0
    &&
    (pMihin->ika = pMista->ika)
    &&
    pMihin->ika == pMista->ika
    &&
    (result = 1) || (result = 0) ;

    return result ;

}

_hlo *varaaMuisti(int size) {

    _hlo *ptr = NULL ;
    if( ! ( ptr = (_hlo*)malloc(size) ) ) {

        perror( "Muistin varaus epäonnistui" ) ;
        exit(-1) ;
    }
    return ptr ;
}



_Bool vertailu( _hlo *pStruct1, _hlo *pStruct2 ) {

    if( ( strcmp( pStruct1->nimi, pStruct2->nimi ) ) == 0 && pStruct1->ika == pStruct2->ika ) {

        return 1 ;
    } else {

        return 0 ;
    }

}

/*void kopioikaikki( void *ptrMista, void *ptrMihin, int size ) {

    int i = 0 ;
    char *bytePtr1 = (char *)ptrMista ;
    char *bytePtr2 = (char *)ptrMihin ;

    while( i < size ) {

        *bytePtr2 = *bytePtr1 ;
        bytePtr1++;
        bytePtr2++ ;
        i++ ;
    }
}
*/
