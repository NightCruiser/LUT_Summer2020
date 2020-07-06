/**
 *VAR 1 = REKURSIO
 *VAR 2 = Taulukot
 *Var 3 = Komontoriviparametri
 *Var 4 = Struct, rakenteiden tietorakenne
 *VAR 5 = Binaaritiedoston kirjoittaminen
*/

#include <stdio.h>
#include <stdlib.h>
#define VAR 5

#if VAR == 1
/*REKURSIO*/
int kertoma( int x ) {

    if( x == 1 )
        return 1 ;
    else
        return ( x * kertoma( x - 1 ) ) ;

}
int main( int argc, char *argv[] ) {

    int luku = 6 ;

    printf( "Luku on %d, ja sen kertoma on %d.\n", luku, kertoma(luku) ) ;
    printf( "Kiitos ohjelman k'yt;st'.\n" ) ;

    return 0 ;
}
#endif // VAR 1
#if VAR == 2
/*Taulukot*/
#define KOKO 10
int main( int argc, char *argv[] ) {
#if 0
    int i = 0 ;
    for( i = 0 ; i < 256 ; i++ ) {

        printf( "%d - %c - %x - %o\n", i, i, i, i ) ;

    }
#endif //VAR2.1

    int i = 0 ;
    int taulukko[KOKO] ;
    int taulukko2[] = {6, 3, 2} ;

    for( i = 0 ; i < KOKO ; i++ ) {

        taulukko[i] = i ;
    }
    for( i = 0 ; i < KOKO ; i++ ) {

        printf( "%d ", taulukko[i] ) ;

    }
    printf( "\n" ) ;
    for( i = 0 ; i < 3 ; i++ ) {

        printf( "%d ", taulukko2[i] ) ;

    }
    printf( "\n" ) ;

    /*matriisi DEFINE EI NORMALISTI KESKELL" koodia!!!*/
#define rivi 2
#define sarake 2

    int j ;
    int matriisi[rivi][sarake] = { { 1, 2 }, { 3, 4 } };
    for( i = 0 ; i < rivi ; i++ ) {

        for( j = 0 ; j < sarake ; j++ ) {

            printf( "%d ", matriisi[i][j] ) ;
        }
        printf( "\n" ) ;
    }
    printf( "\n" ) ;

    printf( "Kiitos ohjelman k'yt;st'.\n" ) ;

    return 0 ;
}
#endif // VAR == 2
#if VAR == 3
/*Komontoriviparametri*/
int main( int argc, char *argv[] ) {

    int i = 0 ;
    for( i = 0 ; i < argc ; i++ ) {

        printf( "argv[%d] = '%s'\n", i, argv[i] ) ;
    }

    char teksti[] = "444" ;
    int luku = atoi(teksti) ;
    printf( "'%s' == '%d' -> 2*luku = %d\n", teksti, luku, 2 * luku ) ;
    printf( "\n" ) ;

    printf( "Kiitos ohjelman k'yt;st'.\n" ) ;

    return 0 ;
}
#endif // VAR == 3
#if VAR == 5
#include <string.h>
/*Struct, rakenteiden tietorakenne*/
int main( int argc, char *argv[] ) {

    struct henkilo {

        char nimi[30] ;
        int ika ;
    } ;
    struct henkilo muuttuja ;

    muuttuja.ika = 56 ;
    strcpy( muuttuja.nimi, "Ville" ) ;

    printf( "Ika on %d, nimi in %s.\n", muuttuja.ika, muuttuja.nimi ) ;

    typedef struct henkilo Henkilo ;

    Henkilo hlo ;

    hlo.ika = 16 ;
    strcpy( hlo.nimi, "Seija" ) ;

    Henkilo *pHlo = &hlo ;

    printf( "Ika on %d, nimi in %s.\n", pHlo->ika, pHlo->nimi ) ;

#if 0
#define LKM 3
    Henkilo hlot[LKM] ;
    for ( i = 0 ; i < LKM ; i++ ) {

        ...
    }
#endif // VAR 4.2
    printf( "Kiitos ohjelman k'yt;st'.\n" ) ;

   // return 0 ;
//}
#endif // VAR == 4
#if VAR == 5
/*Binaaritiedoston kirjoittaminen*/
//int main( int argc, char *argv[] ) {

    FILE *tiedosto ;
    printf( "Nyt kirjoitetaan binaaritiedosto.\n" ) ;
    if( ( tiedosto = fopen( "Hlo.bin", "wb" ) ) == NULL ) {

        perror( "Hlo.bin" ) ;
        exit (-1) ;
    }
    fwrite( pHlo, sizeof( *pHlo ), 1, tiedosto ) ;
    fclose( tiedosto ) ;

    printf( "Kiitos ohjelman k'yt;st'.\n" ) ;

    return 0 ;
    }

#endif // VAR == 5
