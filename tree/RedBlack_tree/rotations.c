#include <stdio.h>

#include "red_black.h"
#include "rotations.h"


/**
 * @brief Performs the required rotation about the imbalanced node
 * 
 * @param tree reference to the tree
 * @param imbalanced node at which imbalance is seen
 * @param newmonth new added node which caused the imbalance
 */
void performRotation(RBtree *tree, rbnode *imbalanced, int newdata) {
    // 1: LL
    // 2: LR
    // 3: RR
    // 4: RL

    if (newdata < imbalanced->data) {
        // Left
        if (newdata < imbalanced->left->data) {
            // Left-Left
            printf("\tLL rotation\n\n");
            LLrotation(tree, imbalanced);
            return;
        } else {
            // Left-Right
            printf("\tLR rotation\n\n");
            LRrotation_independent(tree, imbalanced);
            return;
        }
    } else {
        // Right
        if (newdata > imbalanced->right->data) {
            // Right-Right
            printf("\tRR rotation\n\n");
            RRrotation(tree, imbalanced);
            return;
        } else {
            // Right-Left
            printf("\tRL rotation\n\n");
            RLrotation(tree, imbalanced);
            return;
        }
    }
}


/**
 * @brief Performs rotation when newnode is to the left's left of imbalance
 * 
 * @param tree 
 * @param rotatenode 
 */
void LLrotation(RBtree *tree, rbnode *rotatenode) {
    rbnode *A = rotatenode;
    rbnode *B = A->left;

    if(rotatenode == *tree){
        *tree = B;
    }
    rbnode *T2 = B->right;
    rbnode *Ap = NULL;

    if (A->parent != NULL) {
        Ap = A->parent;

        if (A == Ap->right) {
            Ap->right = B;
        } else if (A == Ap->left) {
            Ap->left = B;
        }
    }
    // Actual shifting and rotation takes place here now
    B->parent = Ap;
    
    B->right = A;
    A->parent = B;
    A->left = T2;
    if (T2 != NULL) {
        T2->parent = A;
    }
    // After rotation, balance factor of the two main nodes becomes zero

    return;
}


/**
 * @brief Performs rotation when newnode is to the right's right of imbalance
 * 
 * @param tree 
 * @param rotatenode 
 */
void RRrotation(RBtree *tree, rbnode *rotatenode) {
    rbnode *A = rotatenode;
    rbnode *B = A->right;

    if(rotatenode == *tree){
        *tree = B;
    }
    rbnode *T2 = B->left;
    rbnode *Ap = NULL;

    if (A->parent != NULL) {
        Ap = A->parent;

        if (A == Ap->right) {
            Ap->right = B;
        } else if (A == Ap->left) {
            Ap->left = B;
        }
    }
    // Actual shifting and rotation takes place here now
    B->parent = Ap;
    
    B->left = A;
    A->parent = B;
    A->right = T2;
    if (T2 != NULL) {
        T2->parent = A;
    }
    // After rotation, balance factor of the two main nodes becomes zero

    return;
}


/**
 * @brief Performs rotation when newnode is to the right's left of imbalance
 * 
 * @param tree 
 * @param rotatenode 
 */
void RLrotation(RBtree *tree, rbnode *rotatenode) {
    LLrotation(tree, rotatenode->right);
    RRrotation(tree, rotatenode);
    return;
}


/**
 * @brief Performs rotation when newnode is to the left's right of imbalance
 * 
 * @param tree 
 * @param rotatenode 
 */
void LRrotation(RBtree *tree, rbnode *rotatenode) {
    RRrotation(tree, rotatenode->left);
    LLrotation(tree, rotatenode);
    return;
}

/**
 * @brief Performs rotation when newnode is to the right's left of imbalance
 * 
 * @param tree 
 * @param rotatenode 
 */
void RLrotation_independent(RBtree *tree, rbnode *rotatenode) {
    rbnode *A = rotatenode;
    rbnode *Ar = A->right;
    rbnode *Arl = Ar->left;

    if(rotatenode == *tree){
        *tree = Arl;
    }
    
    A->right = Arl;
    Ar->left = Arl->right;
    if (Arl->right != NULL) {
        Arl->right->parent = Ar;
    }
    Arl->right = Ar;
    Ar->parent = Arl;
    Arl->parent = A;

    rbnode *Ap = NULL;
    if (A->parent != NULL) {
        Ap = A->parent;
        if (A == Ap->left) {
            Ap->left = Arl;
        } else if (A == Ap->right) {
            Ap->right = Arl;
        }
    }
    Arl->parent = Ap;
    A->parent = Arl;
    A->right = Arl->left;
    Arl->left = A;


    return;
}


void LRrotation_independent(RBtree *tree, rbnode *rotatenode) {
    rbnode *A = rotatenode;
    rbnode *Al = A->left;
    rbnode *Alr = Al->right;

    if(rotatenode == *tree){
        *tree = Alr;
    }
    
    rbnode *Ap = NULL;
    if (A->parent != NULL) {
        Ap - A->parent;
        if (A == Ap->left) {
            Ap->left = Alr;
        } else if (A == Ap->right) {
            Ap->right = Alr;
        }
    }
    Alr->parent = Ap;

    if (Alr->left != NULL) {
        Alr->left->parent = Al;
    }
    if (Alr->right != NULL) {
        Alr->right->parent = A;
    }

    Alr->left = Al;
    Alr->right = A;
    Al->parent = Alr;
    A->parent = Alr;

    return;
}

