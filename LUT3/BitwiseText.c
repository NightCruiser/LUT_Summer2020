#include <stdio.h>

int main( int argc, char *argv[] ) {

    int x = 17 & 0xFF;
    printf( "X = %#0xd", x ) ;
    printf( "X = %d", x ) ;

    return 0 ;
}
