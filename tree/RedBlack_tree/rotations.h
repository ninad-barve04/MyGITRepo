#ifndef AVL_ROTAT_H
#define AVL_ROTAT_H (1)

#include "red_black.h"

void performRotation(AVL *tree, avlnode *imbalanced, int newdata);
void LLrotation(AVL *tree, avlnode *rotatenode);
void RRrotation(AVL *tree, avlnode *rotatenode);
void RLrotation(AVL *tree, avlnode *rotatenode);
void LRrotation(AVL *tree, avlnode *rotatenode);
void RLrotation_independent(AVL *tree, avlnode *rotatenode);
void LRrotation_independent(AVL *tree, avlnode *rotatenode);

#endif