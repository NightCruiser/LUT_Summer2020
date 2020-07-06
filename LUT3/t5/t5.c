#include <stdio.h>
#include <stdlib.h>
#define LEN 20

int tiedostonKirjoittaa( FILE **file ) ;
void tiedostonLukea( FILE **file ) ;

int main( int argc, char *argv[] ) {

    FILE *file ;

    if( ( file = fopen( "luvut.bin", "w+b" ) ) == NULL ) {

        perror( "luvut.bin" ) ;
        exit(-1) ;
    }

    if( tiedostonKirjoittaa( &file ) == 0 ) {

        printf( "Lukujen tallennus onnistui.\n" ) ;
    }

    printf( "Tiedostossa on seuraavat luvut:\n" ) ;
    tiedostonLukea( &file ) ;

    fclose(file) ;

    return 0 ;
}

int tiedostonKirjoittaa( FILE **file ) {

    int i = 0 ;

    srand(1) ;

    for( i = 0 ; i < LEN ; i++ ) {

        fprintf( *file, "%d ", rand() % 1000 );
    }

    return 0 ;
}

void tiedostonLukea( FILE **file ) {

    int character = 0 ;

    fseek( *file, 0, SEEK_SET ) ;
    while( ( character = fgetc( *file ) ) != EOF ) putchar( character ) ;
    printf( "\n" ) ;

}
