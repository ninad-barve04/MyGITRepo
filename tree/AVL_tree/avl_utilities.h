#ifndef AVL_UTILS_H
#define AVL_UTILS_H (1)

#include "avl.h"

int findHeight(AVL tree);
int balanceFactor(avlnode *node);
int isNotBalanced(avlnode *node);
avlnode * findImbalance(avlnode *leafnode);
void adjustBalanceFactor(avlnode **node);
avlnode *searchNode(AVL tree, int element);
avlnode *inorderSuccessor(AVL tree);
char * getUpperCase(char *s);
int getMonthNumber(char *monthname);

#endif