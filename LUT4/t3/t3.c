#include <stdio.h>
#include <stdlib.h>

#define PLUS 0x2B
#define MINUS 0x2D
#define MULT 0x78
#define DIV 0x2F

int main( int argc, char *argv[] ) {

     if( argc < 3 ) {

        fprintf(stderr, "Et antanut syötteitä.\n") ;
        return 0 ;
    }

    switch( *argv[2] ) {

        case PLUS :
            printf( "%s + %s = %.2f\n", argv[1], argv[3], atof( argv[1] ) + atof( argv[3] ) ) ;
            break ;

        case MINUS :
            printf( "%s - %s = %.2f\n", argv[1], argv[3], atof( argv[1] ) - atof( argv[3] ) ) ;
            break ;

        case MULT :
            printf( "%s x %s = %.2f\n", argv[1], argv[3], atof( argv[1] ) * atof( argv[3] ) ) ;
            break ;

        case DIV :
            printf( "%s / %s = %.2f\n", argv[1], argv[3], atof( argv[1] ) / atof( argv[3] ) ) ;
            break ;
        default :
            fprintf(stderr, "Virheellinen syöte.\n") ;
    }

    return 0 ;
}
