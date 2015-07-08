#ifndef A_VEC__
#define A_VEC__

typedef struct A_VEC_ {
    char * chars;
    int * nums;
    int currSize;
    int currOccupied;
} A_VEC;

int a_vec_init ( A_VEC * target );

int a_vec_insert ( A_VEC * target, char key );

void a_vec_print ( A_VEC * target );

void a_vec_pop ( A_VEC * target, char * c, int * i );

#endif
