#ifndef H_TREE__
#define H_TREE__

typedef struct H_Tree_ {
    char value;
    int frequency;
    struct H_Tree_ * left;
    struct H_Tree_ * right;
} H_Tree;

#endif

