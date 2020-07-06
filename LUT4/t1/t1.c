#include <stdio.h>
#include <string.h>
#define KIRNIMLEN 30

struct kirja {

    char nimi[KIRNIMLEN] ;
    int painovuosi ;
    int hyllypaikka ;
} ;

typedef struct kirja kir ;

int main( int argc, char *argv[] ) {

    kir kirja1 ;
    kir *pKir = &kirja1 ;
    size_t i = 0 ;

    printf( "Anna kirjan nimi: " ) ;
    fgets( pKir->nimi, KIRNIMLEN, stdin ) ;

    while( pKir->nimi[i] != '\n' ) i++ ;
    pKir->nimi[i] = '\0' ;

    printf( "Anna kirjan painovuosi: " ) ;
    scanf( " %d", &pKir->painovuosi ) ;

    printf( "Anna kirjan hyllypaikka: " ) ;
    scanf( " %d", &pKir->hyllypaikka ) ;

    printf( "Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\n", pKir->nimi, pKir->painovuosi, pKir->hyllypaikka ) ;

    return 0 ;
}
