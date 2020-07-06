#include <stdio.h>
#define LEN 30

void strkopiointi( char *str1, char *str2, size_t nPituus ) ;

int main( int argc, char *argv[] ) {

    char merkkijono1[LEN] ;
    char merkkijono2[LEN] ;
    char *pArr = merkkijono1 ;
    size_t nPituus = 0 ;
    size_t i = 0 ;

    for( i = 0 ; i < LEN ; i++ ) {

        merkkijono1[i] = 0 ;
        merkkijono2[i] = 0 ;
    }
    
    printf( "Anna ensimmäinen merkkijono: " ) ;
    fgets( merkkijono1, LEN, stdin ) ;

    while( *pArr != '\n' ) nPituus++, pArr++ ;
    *pArr = '\0' ;

    strkopiointi( merkkijono1, merkkijono2, nPituus ) ;

    printf( "Merkkijono 1 on '%s'.\nMerkkijono 2 on '%s'.\n", merkkijono1, merkkijono2 ) ;

    return 0 ;
}

void strkopiointi( char *str1, char *str2, size_t nPituus ) {

    while( *str1 != 0 ) {

        *str2 = *str1 ;
        str1++ ;
        str2++ ;
    }
}
