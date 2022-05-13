#ifndef AVL_H
#define AVL_H (1)
#include <stdio.h>


#define MAX(a, b) ((a > b) ?  a:  b)


typedef struct avlnode {
    int data;
    struct avlnode * left;
    struct avlnode * right;
    struct avlnode * parent;
    int balance_factor;
} avlnode;

typedef avlnode* AVL;


void initAVL(AVL *tree);
int insertNode(AVL *tree, int element);
int removeNode(AVL *tree, int element);
void traverse(AVL tree, int type);
void destroyTree(AVL *tree);

void inorderTraversal(AVL tree);
void preorderTraversal(AVL tree);
void postorderTraversal(AVL tree);

#endif