#include <stdio.h>
#include <stdlib.h>

void tulostaa( const int *pArr, int size ) ;
int *muuta( int *pArr, int oldSize, int newSize ) ;

int main( int argc, char *argv[] ) {

    int valinta = 0 ;
    int *pArray = NULL ;
    int taulukonKoko = 0 ;
    int previousKoko = 0 ;


    do {
        printf( "1) Tulosta taulukon alkiot\n"
                "2) Muuta taulukon kokoa\n"
                "0) Lopeta\n"
                "Anna valintasi: " ) ;
        scanf( " %d", &valinta ) ;
        getchar() ;
        switch( valinta ) {

            case 1 :
                tulostaa( pArray, taulukonKoko ) ;
                break ;
            case 2 :
                previousKoko = taulukonKoko ;
                printf( "Anna taulukon uusi koko: " ) ;
                scanf( " %d", &taulukonKoko ) ;

                if( taulukonKoko < 0 ) {

                    fprintf( stderr, "Taulukon koko ei voi olla negatiivinen.\n" ) ;
                    taulukonKoko = previousKoko ;
                    break ;
                }

                pArray = muuta( pArray, sizeof(int) * previousKoko, sizeof(int) * taulukonKoko ) ;
                break ;
            case 0 :
                printf( "Kiitos ohjelman käytöstä.\n" ) ;
                break ;
            default :
                printf( "Tuntematon valinta, yritä uudestaan.\n" ) ;
        }

    } while( valinta != 0 ) ;

    free( pArray ) ;
    return 0 ;
}

void tulostaa( const int *pArr, int size ) {

    if( size == 0 ) {

        printf( "Taulukko on tyhjä.\n" ) ;
        return ;
    }

    printf( "Taulukon alkiot ovat: " ) ;
    while( size > 0 ) {

        printf( "%d ", *pArr ) ;
        pArr++ ;
        size-- ;
    }
    printf( "\n" ) ;
}

int *muuta( int *pArr, int oldSize, int newSize ) {

    int difference = oldSize - newSize  ;
    int i = 0 ;

    if( pArr == NULL ){

        if( ! (pArr = ( int * )malloc( newSize ) ) ) {

            perror( "Muistin varaus epäonnistui\n" ) ;
            exit( -1 ) ;
        }

        while( i < newSize / sizeof(int) ) {

            pArr[i] = i ;
            i++ ;
        }

        return pArr;
    }

    if( difference == 0 ) {

        return pArr;
    }

    if( difference > 0 ) {

        if( ! ( pArr = (int *)realloc( ( void * ) pArr, newSize ) ) ) {

            perror( "Muistin varaus epäonnistui\n" ) ;
            exit( -1 ) ;
        }

        return pArr;
    }

    pArr = (int *)realloc( ( void * ) pArr, newSize ) ; 



    i = oldSize / sizeof( int ) ;
    newSize = newSize / sizeof( int ) ;
    while( i <  newSize ) {

        pArr[i] = i ;
        i++ ;
    }

    return pArr ;
}
