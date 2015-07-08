#include <stdlib.h>
#include <assert.h>
#include "a_vec.h"
#include "h_tree.h"

typedef struct Tree_Queue_ {
    H_Tree * tree;
    struct Tree_Queue_ * next;
} Tree_Queue;

int t_q_len ( Tree_Queue * head )
{

    int res = 0;

    while ( head->next )
    {

        res++;
        head = head->next;

    }

    return res;

}

void q_insert ( Tree_Queue * queue, H_Tree * tree )
{

    if ( queue->tree == NULL )
    {
        
        queue->tree = tree;
        return;

    }
    
    Tree_Queue * current_q = queue;

    while ( current_q->tree->frequency < tree->frequency )
        if ( current_q->next )
            current_q = current_q->next;

    if ( current_q->next )
    {

        assert( current_q->tree->frequency >= tree->frequency );

        Tree_Queue * temp = ( Tree_Queue * )malloc( sizeof( Tree_Queue ) );
        temp->tree = tree;
        temp->next = current_q->next;
        current_q->next = temp;

    }
    else
    {


        assert( current_q->next == NULL );
        current_q->next = ( Tree_Queue * )malloc( sizeof( Tree_Queue ) );
        current_q->next->tree = tree; 

    }


}

void q_destroy ( Tree_Queue * queue )
{

    if ( queue->next ) q_destroy( queue->next );
    free( queue );

}

H_Tree * h_tree_from_a_vec ( A_VEC * input )
{

    Tree_Queue queue;
    int i = input->currOccupied;
    int a_vec_freq;
    int queue_freq;

    

}


