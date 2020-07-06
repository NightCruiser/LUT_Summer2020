#include <stdio.h>
#define RIVI 2
#define SARAKE 2

void mtulostaa( const int *m, int sR, int sS, char *nimi ) ;

int main( int argc, char *argv[] ) {

    int m1[RIVI][SARAKE] ;
    int m2[RIVI][SARAKE] ;
    int mSum[RIVI][SARAKE] ;
    int i = 0 ;

    printf( "Anna arvot yhteenlaskettaville matriiseille:\n"
            "Matriisin 1 alkiot:\n" ) ;
    for( i = 0 ; i < RIVI ; i++ ) {
        int j = 0 ;
            for( j = 0 ; j < SARAKE ; j++ ) {

                printf( "Rivi %d alkio %d: ", i + 1, j + 1 ) ;
                scanf( " %d", &m1[i][j] ) ;
                mSum[i][j] = m1[i][j] ;
            }
    }

    mtulostaa( (int *)m1, RIVI, SARAKE, "Matriisi 1" ) ;

    printf( "Matriisin 2 alkiot:\n" ) ;
    for( i = 0 ; i < RIVI ; i++ ) {
        int j = 0 ;
            for( j = 0 ; j < SARAKE ; j++ ) {

                printf( "Rivi %d alkio %d: ", i + 1, j + 1 ) ;
                scanf( " %d", &m2[i][j] ) ;
                mSum[i][j] += m2[i][j] ;
            }
    }

    mtulostaa( (int *)m2, RIVI, SARAKE, "Matriisi 2" ) ;
    mtulostaa( (int *)mSum, RIVI, SARAKE, "Summamatriisi" ) ;
    return 0 ;
}

void mtulostaa( const int *m, int sR, int sS, char *nimi ) {

    int i = 0 ;
    printf( "\n%s:\n", nimi ) ;
    for( i = 0 ; i < sR ; i++ ) {
        int j = 0 ;
        for( j = 0 ; j < sS ; j++ ) {
            printf( "%4d ", *( m + i*sS + j ) ) ;
        }
        printf( "\n" ) ;
    }
    printf( "\n" ) ;
}
/*
for( i = 0 ; i < sR ; i++ ) {
    int j = 0 ;
    for( j = 0 ; j < sS ; j++ ) {

        printf( "%4d", *( m + i * sS + j) ) ;
    }
    printf( "\n" ) ;
}
*/
/*
    printf( "Matriisin 1 alkiot:\n" ) ;
    printf( "Rivi 1 alkio 1: " ) ;
    scanf( " %d", &m1[0][0] ) ;
    mSum[0][0] = m1[0][0] ;
    printf( "Rivi 1 alkio 2: " ) ;
    scanf( " %d", &m1[0][1] ) ;
    mSum[0][1] = m1[0][1] ;
    printf( "Rivi 2 alkio 1: " ) ;
    scanf( " %d", &m1[1][0] ) ;
    mSum[1][0] = m1[1][0] ;
    printf( "Rivi 2 alkio 2: " ) ;
    scanf( " %d", &m1[1][1] ) ;
    mSum[1][1] = m1[1][1] ;

    printf( "Matriisin 2 alkiot:\n" ) ;
    printf( "Rivi 1 alkio 1: " ) ;
    scanf( " %d", &m2[0][0] ) ;
    mSum[0][0] += m2[0][0] ;
    printf( "Rivi 1 alkio 2: " ) ;
    scanf( " %d", &m2[0][1] ) ;
    mSum[0][1] += m2[0][1] ;
    printf( "Rivi 2 alkio 1: " ) ;
    scanf( " %d", &m2[1][0] ) ;
    mSum[1][0] += m2[1][0] ;
    printf( "Rivi 2 alkio 2: " ) ;
    scanf( " %d", &m2[1][1] ) ;
    mSum[1][1] += m2[1][1] ;
*/
