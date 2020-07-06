#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tarkistaSyote(char *arg) ;
int* varaaMuisti( int size ) ;
void taytaTaulukko(int *pArr, int size) ;
void tulostaTaulukko(int *pArr, int size) ;
void vapautaMuisti(int *pArr) ;

int main( int argc, char *argv[] ) {

    int inputNumber = 0 ;
    int *pArr = NULL ;

    if( argc < 2 ) {

        fprintf( stderr, "Et antanut taulukon kokoa.\n" ) ;
        return 0 ;
    }

    if( ( inputNumber = tarkistaSyote( argv[1] ) ) == 0  ) {

        fprintf( stderr, "Parametri ei ollut positiivinen kokonaisluku.\n" ) ;
        return 0 ;
    }

    pArr = varaaMuisti( inputNumber ) ;

    taytaTaulukko( pArr, inputNumber ) ;
    tulostaTaulukko( pArr, inputNumber ) ;

    vapautaMuisti( pArr ) ;

        return 0 ;
}

int tarkistaSyote( char *arg ) {

    int number = 0 ;
    int numLength = 0 ;
    int loopNumber = 0 ;

    loopNumber = atoi( arg ) ;
    number = loopNumber ;

    while( loopNumber > 0 ) {

        loopNumber /= 10 ;
        numLength++ ;
    }

    if( strlen( arg ) > numLength || number < 1) {

        return 0 ;
    }
        return number ;
}

int* varaaMuisti( int size ) {

    int *pInt = NULL ;

    if( ! (pInt = (int *)malloc( size * sizeof( int ) ) ) ) {

        perror( "Muistin varaus epäonnistui" ) ;
        exit(-1) ;
    }
    return pInt ;
}

void taytaTaulukko(int *pArr, int size) {

    int i = 0 ;

    printf( "Taulukossa on tilaa %d alkiolle.\n", size ) ;

    while( i < size ) {

        printf( "Anna %d. luku: ", i + 1 ) ;
        scanf( " %d", &pArr[i] ) ;
        i++ ;
    }
}

void tulostaTaulukko(int *pArr, int size) {

    int i = 0 ;

    printf( "Taulukossa on luvut: " ) ;

    while( i < size ) {

        printf( "%d ", pArr[i] ) ;
        i++ ;
    }
    printf( "\n" ) ;
}

void vapautaMuisti(int *pArr) {

    free( pArr ) ;
}
