#include <stdio.h>
#include <stdlib.h>

int fibonacci( int x ) ;

int main( int argc, char *argv[] ) {

    int luku = 0 ;

    printf( "Anna luku, jolle lasketaan Fibonaccin luku: " ) ;
    scanf( " %d", &luku ) ;
    getchar() ;

    printf( "Luvun %d Fibonaccin luku on %d.\n", luku, fibonacci( luku ) ) ;

    return 0 ;
}

int fibonacci( int x ) {

    if( x < 1 ) {

		fprintf( stderr, "Invalid Input\n" ) ;
		exit(-1) ;
	}
    if ( x == 1 || x == 2 ) {

        return 1;
    } else {

        return fibonacci( x - 1 ) + fibonacci( x - 2 ) ;
    }

}
