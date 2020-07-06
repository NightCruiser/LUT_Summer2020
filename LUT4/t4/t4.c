#include <stdio.h>
#define LEN 50
typedef struct tunnus {

    char nimi[LEN] ;
    char salasana[LEN] ;
    unsigned id ;
} tun ;

int tlisaa( tun *tun, unsigned nID ) ;
int ttulostaa( tun *tun, unsigned nID ) ;

int main( int argc, char *argv[] ) {

    tun tunnukset[LEN] ;
    char valinta = 0 ;
    unsigned id = 0 ;

    printf( "Käyttäjätunnusten hallinta.\n" ) ;

    do {
        char pois = 0 ;

        printf( "Valitse alla olevasta valikosta haluamasi toiminto:\n"
                "1) Lisää uusi tunnus\n"
                "2) Tulosta tunnukset\n"
                "0) Lopeta\n"
                "Valintasi: " ) ;

        valinta = getchar() ;
        while(pois != '\n') pois = getchar() ;

        switch( valinta ) {


            case '1' :
                if( id <=LEN ) {

                    tlisaa( &tunnukset[id], id ) ;
                    id++ ;
                } else {

                    fprintf( stderr, "ei ole tilaa" ) ;
                }
                break ;
            case '2' :
                printf( "\nListalla olevat tunnukset:\n" ) ;
                ttulostaa( tunnukset, id ) ;
                break ;
            case '0' :
                printf( "\n" ) ;
                break ;
            default :
                fprintf(stderr, "Tuntematon valinta!\n" );
                break ;
        }


    } while( valinta != '0' ) ;


    return 0 ;
}


int tlisaa( tun *tun, unsigned nID ) {

    tun->id = nID ;

    printf( "\nAnna käyttäjätunnus: " ) ;
    scanf( "%s", tun->nimi ) ;
    getchar() ;

    printf( "Anna salasana: " ) ;
    scanf( "%50s", tun->salasana ) ;
    getchar() ;

    printf( "Tunnus '%s' lisättiin listaan.\n\n", tun->nimi ) ;

    return 0 ;
}

int ttulostaa( tun *tun, unsigned nID ) {

    unsigned i = 0 ;

    for( i = 0 ; i < nID ; i++, tun++) {

        printf( "%d. tunnus '%s', salasana '%s', ID '%d'.\n",
                i + 1, tun->nimi, tun->salasana, tun->id ) ;
    }
    printf( "\n" ) ;
    return 0 ;
}
