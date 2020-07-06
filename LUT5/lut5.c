#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************/
#if 0
/*Muistunk'sittely*/
int main( int argc, char *argv[] ) {

    int iLuku = 2 ;
    int *pLuku ;

    pLuku  = &iLuku ;
    printf( "*pLuku on '%d' ja iLuku on '%d'.\n", *pLuku, iLuku ) ;

    /*muistin varaaminen*/
    pLuku = (int *)malloc(sizeof(int)) ;
    if( !pLuku ) {
        perror( "Muistin varaus ep'" ) ;
        exit(-1) ;
    } else {
        *pLuku = 6 ;
        printf( "*pLuku on '%d' ja iLuku on '%d'.\n", *pLuku, iLuku ) ;
        free( pLuku ) ;
        pLuku = NULL ;
    }

    return 0 ;
}
#endif //1
/******************************************************************************/
#if 0
/* Tietityyppi */
struct HENKILO {
    char nimi[30] ;
    int ika ;
} ;

typedef struct HENKILO Henkilo ;

int main( int argc, char *argv[] ) {

    Henkilo *pHlo ;


    if( !( pHlo = (Henkilo *)malloc(sizeof(Henkilo)) ) ) {
        perror( "Muistin varaus ep'" ) ;
        exit(-1) ;
    }

    strcpy( pHlo->nimi, "Ville" ) ;
    pHlo->ika = 30 ;
    printf( "Nimi on '%s' ja ika on '%d'.\n", pHlo->nimi, pHlo->ika ) ;
    free( pHlo ) ;
    printf( "Kiitos ohjelman kaytosta!\n" ) ;

    return 0 ;
}
#endif //2
/******************************************************************************/
#if 0
/*Osote ja osoitin, union, enum, tavittava muistin maara*/

int main( int argc, char *argv[] ) {

    int *pLuku ;
    int i ;
    pLuku = &i ;
    printf( "Int'n koko on %ld ja osoitin int'iin on %ld, osoittimen arvo on %p.\n", sizeof(int), sizeof(pLuku), (void *)pLuku ) ;
/******************************************************************************/
    union luku_t {
        int kokonaisluku ;
        double liukuluku ;
    } yhdiste ;
    yhdiste.kokonaisluku = 4 ;
    printf( "Koot: int = %ld, double = %ld, union = %ld.\n",
            sizeof(int), sizeof(double), sizeof(yhdiste) ) ;
    printf( "Arvot : %d, liukuluku = %lf\n", yhdiste.kokonaisluku, yhdiste.liukuluku ) ;

    yhdiste.liukuluku = 89765.89765 ;
    printf( "Arvot : %d, liukuluku = %lf\n", yhdiste.kokonaisluku, yhdiste.liukuluku ) ;

    yhdiste.kokonaisluku = 7777777 ;
    printf( "Arvot : %d, liukuluku = %lf\n", yhdiste.kokonaisluku, yhdiste.liukuluku ) ;

   // printf( "Kokonaisluvun osoite : %p, Liukuluvun osoite : %p.\n",
   //         (void *)&yhdiste.kokonaisluku, (void *)&yhdiste.liukuluku ) ;
 /******************************************************************************/
    enum tosi { EI = 5, KYLLA } ;
    printf( "%d, %d\n", EI, KYLLA ) ;


    return 0 ;
}
#endif //3
/******************************************************************************/
#if 1
/* Merkkijonofunktioita - osoite ja osoitin */
int strpituus( char *s ) {
    int i = 0 ;
    while(*s != '\0') {

        i++ ;
        s++ ;
    }
    return i ;
}

char *strKopioi( char *pS1, char *pS2 ) {

    char *pS = pS1 ;
   /* while( *pS2 != '\0' ) {

        *pS1 = *pS2 ;
        pS1++ ;
        pS2++ ;
    }
    *pS1 = '\0' ;
    */
    while( *pS1++ = *pS2++ ) ;
    return pS ;
}
/*char *strkopioiN( char *pS1, char *pS2, int lkm ) {
    ...
    while( ( *pS2 != '\0' ) && ( i < lkm ) ) {}
    ...
}*/
int main( int argc, char *argv[] ) {

    char s1[30] = "Moikka kaikille" ;
    char s2[30] ;

    printf( "Merkkijonon '%s' pituus on %d merkki' / strpituus().\n", s1, strpituus(s1) ) ;
    printf( "Merkkijonon '%s' pituus on %ld merkki' / strlen().\n", s1, strlen(s1) ) ;

    strcpy( s2, s1 ) ;
    printf( "s1 = '%s', s2 = '%s' / strcpy().\n", s1, s2 ) ;
    strKopioi( s2, s1 ) ;
    printf( "s1 = '%s', s2 = '%s' / strkopioi().\n", s1, s2 ) ;

    return 0 ;
}
#endif //4
