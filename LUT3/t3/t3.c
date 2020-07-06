#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compjavaihta( float *num1, float *num2, short valinta ) ;
void merrkijonocomp( char *merkkijono1, char *merkkijono2 ) ;

int main( int argc, char *argv[] ) {

    float a = 0.0f ;
    float b = 0.0f ;
    char merkkijono1[25] ;
    char merkkijono2[25] ;

    printf( "Anna kaksi kokonaislukua:\n" ) ;
    compjavaihta( &a, &b, 1 ) ;

    printf( "Anna kaksi desimaalilukua:\n" ) ;
    compjavaihta( &a, &b, 2 ) ;

    printf( "Anna kaksi nimeä:\n" ) ;
    merrkijonocomp( merkkijono1, merkkijono2 ) ;

    return 0 ;
}

void compjavaihta( float *num1, float *num2, short valinta ) {

        float tmp = 0.0f ;

        if( valinta < 1 || valinta > 2 ) exit (-1) ;
        printf( "Luku 1: " ) ;
        scanf( " %f", num1 ) ;
        getchar() ;
        printf( "Luku 2: " ) ;
        scanf( " %f", num2 ) ;
        getchar() ;

        if( *num1 < *num2 ) {
            tmp = *num1 ;
            *num1 = *num2 ;
            *num2 = tmp ;
        }
        switch( valinta ) {

            case 1 :
                if ( *num1 == *num2 ) {

                    printf( "Luvut %d ja %d ovat yhtä suuria.\n", (int)*num1, (int)*num2 ) ;
                } else {

                    printf( "Luku %d on suurempi ja %d pienempi.\n", (int)*num1, (int)*num2 ) ;
                }
                break ;
            case 2 :

                if ( *num1 == *num2 ) {

                    printf( "Luvut %5.2f ja %5.2f ovat yhtä suuria.\n", *num1, *num2 ) ;
                } else {

                    printf( "Luku %5.2f on suurempi ja %5.2f pienempi.\n", *num1, *num2 ) ;
                }
                break ;
        }
}

void merrkijonocomp( char *merkkijono1, char *merkkijono2 ) {

    printf( "Nimi 1: " ) ;
    scanf( "%s", merkkijono1 ) ;
    getchar();
    printf( "Nimi 2: " ) ;
    scanf( "%s", merkkijono2 ) ;
    getchar();

    if( strcmp( merkkijono1, merkkijono2 ) < 0 ) {

        printf( "Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", merkkijono2, merkkijono1 ) ;
    } else if( strcmp( merkkijono1, merkkijono2 ) > 0 ) {

        printf( "Merkkijonona '%s' on suurempi ja '%s' pienempi.\n", merkkijono1, merkkijono2 ) ;
    } else {

        printf( "Merkkijonona '%s' ja '%s' ovat yhtä suuria.\n", merkkijono1, merkkijono2 ) ;
    }
}
