#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

    int rByte = 0 ;
    FILE *myFile = fopen( "/home/nightcruiser/OhjVideo3.c", "rt" ) ;

    if( !myFile ){

        perror( "/home/nightcruiser/OhjVideo3.c" ) ;
        exit(-1) ;
    }

    while( ( rByte = fgetc( myFile ) ) != EOF ) {

        if( rByte == '/' && fgetc( myFile ) == '*' ) {

            while( fgetc( myFile ) != '*' || fgetc( myFile ) != '/' ) {
                ;
            }

        } else if( rByte == '/' && !fseek( myFile, -1, SEEK_CUR ) && fgetc( myFile )  == '/' ) {

            while( fgetc( myFile ) != '\n' ) {
                ;
            }


        } else if( rByte == '"' ) {

            do {
                putchar( rByte ) ;
                rByte = fgetc( myFile ) ;

            } while( rByte != '"' ) ;



        } else {

            putchar( rByte ) ;

        }

    }

    fclose( myFile ) ;

    return 0 ;
}
