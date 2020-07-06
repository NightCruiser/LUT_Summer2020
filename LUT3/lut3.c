#include <stdio.h>
#include <stdlib.h>
#define VAR 5
#define LEN 80
#define LKM 10
#define MAX(x, y) ( x > y ? x : y)
#define square(x) (x)*(x)

void Valikko() ;
int Max( int x, int y ) ;
int summa( int x, int y, int *z ) ;
void vaihda( int *x, int *y ) ;

int main( int argc, char *argv[] ) {
#if VAR == 1
/*******************************************************************/
/*Tiedoston kirjoittaminen*/
    FILE * tiedosto ;
    char rivi[LEN] ;
    int i = 0 ;

    /*tiedosto = fopen( "tiedostokirjoita.txt", "w" ) ;*/
    if((tiedosto = fopen( "tiedostokirjoita.txt", "wt" )) == NULL ) {
        perror( "tiedostokirjoita" ) ;
        exit(-1) ;
    }

    for( i = 0 ; i < LKM ; i++ )
        fwrite( &i, sizeof(i), 1, tiedosto ) ;
    /*fprintf( tiedosto, "First rivi. \n" ) ;
    fprintf( tiedosto, "Second rivi. \n" ) ;*/
    fclose( tiedosto ) ;


/*******************************************************************/
#endif
#if VAR == 2
/*******************************************************************/
/*Tiedoston Lukeminen*/
    FILE * tiedosto ;
    char rivi[LEN] ;


    if((tiedosto = fopen( "tiedostokirjoita.txt", "r" )) == NULL ) {
        perror( "tiedostokirjoita" ) ;
        exit(-1) ;
    }






    while( fgets( rivi, LEN, tiedosto ) != NULL )
        fprintf(stdout, "%s", rivi) ;
    fclose( tiedosto ) ;


/*******************************************************************/
#endif
#if VAR == 3
/*******************************************************************/
/*Binaaritiedosto*/
    FILE * tiedosto ;
    int i ;
    int luku ;

    if((tiedosto = fopen( "tiedostokirjoita.bin", "wb" )) == NULL ) {
        perror( "tiedostokirjoita" ) ;
        exit(-1) ;
    }
    for( i = 0 ; i < LKM ; i++ )
        printf( "Numero on %d.\n", i ) ;
    for( i = 0 ; i < LKM ; i++ )
        fwrite( &i, sizeof(i), 1, tiedosto ) ;

    fclose( tiedosto ) ;

    if((tiedosto = fopen( "tiedostokirjoita.bin", "r" )) == NULL ) {
        perror( "tiedostokirjoita" ) ;
        exit(-1) ;
    }

    for( i = 0 ; i < LKM ; i++ ) {
        fread( &luku, sizeof(luku), 1, tiedosto ) ;
        printf( "%d\n", luku ) ;
    }

    fclose( tiedosto ) ;
/*******************************************************************/
#endif
#if VAR == 4
/*******************************************************************/
/*Funktioita*/
    /*Funktio*/
    Valikko() ;
    int eka, toka, tulos ;
    eka = 6 ;
    toka = 4 ;
    tulos = Max(eka, toka) ;
    printf( "FUNKTIO: Suurempi on %d.\n", tulos ) ;

    /*Parametrit*/
    int nLuku1 = 2, nLuku2 = 6, nLuku3 = 3, nLukuTulos ;
    printf("Ennen funktiokutsua: nLuku1 = %d, nLuku2 = %d, nLuku3 = %d.\n",
            nLuku1, nLuku2, nLuku3 ) ;
    nLukuTulos = summa( nLuku1, nLuku2, &nLuku3 ) ;
    printf("Jalkeen funktiokutsun: summa = %d.\n",nLukuTulos ) ;
    printf("Jalkeen funktiokutsun: nLuku1 = %d, nLuku2 = %d, nLuku3 = %d.\n",
            nLuku1, nLuku2, nLuku3 ) ;

    /*vaihda-aliohjelma*/
    nLuku1 = 1 ;
    nLuku2 = 2 ;
    printf("Ennen funktiokutsua: nLuku1 = %d, nLuku2 = %d.\n",
            nLuku1, nLuku2 ) ;
            vaihda( &nLuku1, &nLuku2 ) ;
    printf("Jalkeen funktiokutsun: nLuku1 = %d, nLuku2 = %d.\n",
            nLuku1, nLuku2 ) ;

    /*Makro*/
    float x = 1.1f ;
    float y = 5.5f ;
    float fTulos = 0.0f ;

    fTulos = MAX(x, y) ;
    printf( "Suurempi on: %.2f.\n", fTulos ) ;

    /*Riskeja*/
    printf( "Nelio on %d.\n", square(3) ) ;
    printf( "Nelio on %d.\n", square(3 + 1) ) ;


/*******************************************************************/
#endif
#if VAR == 5
/*******************************************************************/
/*Kirjastot ja RAND*/

    int i = 0 ;

    for( i = 0 ; i < 10 ; i++ )
        printf( "Satunnaisluku '%d'\n", random() ) ;


/*******************************************************************/
#endif
    return 0 ;

}
#if VAR == 4

int Max( int x, int y ) {

    return ( x > y ? x : y ) ;

}

void Valikko() {

        printf( "1) Valinta  1\n" ) ;
        printf( "2) Valinta  2\n" ) ;
        printf( "0) Valinta  0\n" ) ;
    }

int summa( int x, int y, int *z ) {

    int tulos = 0 ;
    x = x * 2 ;
    printf("Funktiossa: x = %d, y = %d, z = %d.\n",
            x, y, *z ) ;
    tulos = x + y ;
    *z = y * y ;
    printf("Funktiossa: x = %d, y = %d, z = %d, tulos = %d.\n",
            x, y, *z, tulos ) ;


    return tulos ;
}

void vaihda( int *x, int *y ) {

    printf("Alussa: x = %d, y = %d.\n", *x, *y ) ;
    int temp = *x ;
    *x = *y ;
    *y = temp ;

    printf("Lopussa: x = %d, y = %d.\n", *x, *y ) ;



}
#endif
