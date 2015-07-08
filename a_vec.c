#include <stdio.h>
#include <stdlib.h>
#include "a_vec.h"

#define MEM_ERROR()                                     \
    {                                                   \
                                                        \
        fprintf( stderr, "memory allocation error" );   \
        return -1;                                      \
                                                        \
    }


void swap_int ( int * a, int * b )
{

    int temp = *a;
    *a = *b;
    *b = temp;

}

void swap_char ( char * a, char * b )
{

    char temp = *a;
    *a = *b;
    *b = temp;

}

int a_vec_init ( A_VEC * target )
{

    target->currSize = 4;
    target->currOccupied = 0;
    target->nums = ( int * )calloc( 4, sizeof( int ) );
    target->chars = ( char * )calloc( 4, sizeof( char ) );

    if ( (target->nums == NULL) || (target->chars == NULL) ) MEM_ERROR();

    return 0;

}

int a_vec_realloc ( A_VEC * target )
{

    target->currSize *= 2;
    int * temp = ( int * )realloc( target->nums, target->currSize * sizeof( int ) );
    if ( temp != NULL ) target->nums = temp;
    else MEM_ERROR();

    char * temp_c = ( char * )realloc( target->chars, target->currSize * sizeof( char ) );
    if ( temp_c != NULL ) target->chars = temp_c;
    else MEM_ERROR();

    return 0;

}

int a_vec_insert ( A_VEC * target, char key )
{

    int length = target->currOccupied;
    char * chars = target->chars;
    int * nums = target->nums;
    int i;
    int newFreq;
    int currMin = nums[ 0 ];
    int currMinPos = 0;

    for ( i = 0 ; i < length ; i++ )
    {

        if ( nums[ i ] < currMin )
        {

            currMin = nums[ i ];
            currMinPos = i;

        }

        if ( chars[ i ] == key )
        {

            newFreq = ++nums[ i ];
            swap_int( nums + i, nums + currMinPos );
            swap_char( chars + i, chars + currMinPos );
            return 0;
            
        }

    }

    if ( i == target->currSize ) a_vec_realloc( target );

    target->chars[ i ] = key;
    target->nums[ i ] = 1;
    target->currOccupied++;

    return 0;

}

void a_vec_print ( A_VEC * target )
{

    printf( "A_VEC at location: %p\n", target );
    printf( "of length: %d\n", target->currOccupied );
    printf( "and size: %d\n", target->currSize );
    printf( "---------------------\n" );
    printf( "| chars | frequency |\n" );
    printf( "---------------------\n" );

    for ( int i = 0 ; i < target->currOccupied ; i++ )
        printf( "| %c    | %d        |\n", target->chars[ i ], target->nums[ i ] );

    printf("---------------------\n" );

}

