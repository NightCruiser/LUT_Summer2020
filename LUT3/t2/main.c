#include <stdio.h>
#include <stdlib.h>
#define LEN 50
#define VALDEFAULT 3

int tallentaa( char *name, FILE **file ) ;
int tulostaa( FILE **file ) ;

int main(int argc, char *argv[]) {

	FILE *pFile ;
	char nimi[LEN] ;
	int valinta = VALDEFAULT ;

	printf( "Ohjelma tallentaa nimiä tiedostoon.\n\n" ) ;
	do {
        int t = 0 ;
		printf( "1) Tallenna uusi nimi\n"
		    	"2) Tulosta nimet\n"
				"0) Lopeta\n"
				"Valitse: " ) ;
		if( scanf( " %d", &valinta ) != 1 ) {
            printf( "Invalid Value\n" );
            valinta = VALDEFAULT ;
        }

        while( t != '\n' )  t = getchar() ;

		if( valinta == 1 ) {
			int chck = 0 ;
			chck = tallentaa( nimi, &pFile ) ;
			chck == 0 ? printf( "Nimi on tallennettu tiedostoon.\n\n" )
					  : fprintf( stderr, "Tallennus epäonnistui" ) ;
			fclose( pFile ) ;
		}

		else if( valinta == 2 ) {
			int chck = 0 ;
			chck = tulostaa( &pFile ) ;
			if( chck != 0 ) fprintf( stderr, "epäonnistui" ) ;
			fclose( pFile ) ;
		}

		else if( valinta > 2 || valinta < 0 ) {
			fprintf(stderr, "Invalid Value\n") ;
		}
		else{
			printf( "\n" ) ;
		}

	} while( valinta != 0 ) ;
	return 0 ;
}

int tallentaa( char *name, FILE **file ) {

    int t = 0 ;

	if( (*file = fopen( "nimet.txt", "at") ) == NULL ) {
		perror( "nimet.txt" ) ;
		exit ( -1 ) ;
	}
    printf("\nAnna tallennettava nimi: " ) ;
    scanf( "%50s", name ) ;
    while( t != '\n' )  t = getchar() ;
	fprintf( *file, "%s\n", name ) ;

	return 0 ;
}

int tulostaa( FILE **file ) {

	int character = 0 ;

	if( (*file = fopen( "nimet.txt", "rt") ) == NULL ) {
		perror( "nimet.txt" ) ;
		exit ( -1 ) ;
    }
    printf( "\nTiedostossa olevat nimet:\n" ) ;
	while( (character = fgetc( *file ) ) != EOF ) putchar( character ) ;
	printf( "\n" ) ;

	return 0 ;
}
