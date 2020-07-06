#include <stdio.h>
#include <stdlib.h>

enum ASCIINUMS { NOLLA = 48, YSI = 57 } ;

int nelio( int x ) ;

int main(int argc, char *argv[] ) {

    argc == 1 || *argv[1] > YSI || *argv[1] < NOLLA ? printf( "Et antanut lukua!\n" )
             :
             (printf("Luku on %d.\n", atoi(argv[1]) ),
             printf( "Luvun neliö on %d.\n",
                     atoi(argv[1]) == 0 ? 0 : nelio(atoi(argv[1])) )  );

    return 0 ;
}

int nelio( int x ) {

    x *= x ;
    return x ;
}
