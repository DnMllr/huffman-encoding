#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "a_vec.h"

int import_file ( char * path, FILE ** f, long int * size )
{

    if ( ( *f = fopen( path, "rb" ) ) == NULL )
    {

        fprintf( stderr, "unable to open file: %s\n", path );
        return -1;

    }

    fseek( *f, 0, SEEK_END );

    *size = ftell( *f );

    fseek( *f, 0, SEEK_SET );

    return 0;

}

int check_arguments ( int argc, char ** argv )
{

    if ( argc == 1 )
    {

        fprintf( stderr, "encoder needs to be supplied at least one file\n" );
        return -1;

    }

    return 0;

}

int encode ( char * path )
{

    A_VEC flat;
    FILE * file;
    long int file_size;

    import_file( path, &file, &file_size );

    a_vec_init( &flat );

    char c = '\0';
    
    while ( ( c = fgetc( file ) ) != EOF )
        if ( a_vec_insert( &flat, c ) )
        {

            fprintf( stderr, "failed to insert char: %c into\n", c);
            a_vec_print( &flat );
            return -1;

        }

    printf( "successfully encoded %s\n", path );

    return 0;

}

int main ( int argc, char ** argv )
{

    check_arguments( argc, argv );

    for ( int i = 1 ; i < argc ; i++ )
        if ( encode( argv[ i ] ) )
        {

            fprintf( stderr, "error encoding: %s\n", argv[ i ] );
            return -1;

        }

    return 0;

}

