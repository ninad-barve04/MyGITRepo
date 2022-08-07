#include "avl.h"
#include "avl_rotations.h"
#include "avl_utilities.h"


/**
 * @brief Performs the required rotation about the imbalanced node
 * 
 * @param tree reference to the tree
 * @param imbalanced node at which imbalance is seen
 * @param newmonth new added node which caused the imbalance
 */
void performRotation(AVL *tree, avlnode *imbalanced, int newdata) {
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
            RLrotation_independent(tree, imbalanced);
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
void LLrotation(AVL *tree, avlnode *rotatenode) {
    avlnode *A = rotatenode;
    avlnode *B = A->left;

    if(rotatenode == *tree){
        *tree = B;
    }
    avlnode *T2 = B->right;
    avlnode *Ap = NULL;

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
    A->balance_factor = 0;
    B->balance_factor = 0;

    return;
}


/**
 * @brief Performs rotation when newnode is to the right's right of imbalance
 * 
 * @param tree 
 * @param rotatenode 
 */
void RRrotation(AVL *tree, avlnode *rotatenode) {
    avlnode *A = rotatenode;
    avlnode *B = A->right;

    if(rotatenode == *tree){
        *tree = B;
    }
    avlnode *T2 = B->left;
    avlnode *Ap = NULL;

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
    A->balance_factor = 0;
    B->balance_factor = 0;

    return;
}


/**
 * @brief Performs rotation when newnode is to the right's left of imbalance
 * 
 * @param tree 
 * @param rotatenode 
 */
void RLrotation(AVL *tree, avlnode *rotatenode) {
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
void LRrotation(AVL *tree, avlnode *rotatenode) {
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
void RLrotation_independent(AVL *tree, avlnode *rotatenode) {
    avlnode *A = rotatenode;
    avlnode *Ar = A->right;
    avlnode *Arl = Ar->left;

    if(rotatenode == *tree){
        *tree = Arl;
    }

    avlnode *Ap = NULL;
    if (A->parent != NULL) {
        Ap = A->parent;
        if (A == Ap->left) {
            Ap->left = Arl;
        } else if (A == Ap->right) {
            Ap->right = Arl;
        }
    }
    Arl->parent = Ap;

    if (Arl->left != NULL) {
        Arl->left->parent = A;
    }
    if (Arl->right != NULL) {
        Arl->right->parent = Ar;
    }

    Ar->left = Arl->right;
    A->right = Arl->left;
    Arl->left = A;
    Arl->right = Ar;
    A->parent = Arl;
    Ar->parent = Arl;

    A->balance_factor = 0;
    Ar->balance_factor = 0;
    Arl->balance_factor = 0;

    return;
}


void LRrotation_independent(AVL *tree, avlnode *rotatenode) {
    avlnode *A = rotatenode;
    avlnode *Al = A->left;
    avlnode *Alr = Al->right;

    if(rotatenode == *tree){
        *tree = Alr;
    }
    
    avlnode *Ap = NULL;
    if (A->parent != NULL) {
        Ap = A->parent;
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
    Al->right = Alr->left;
    A->left = Alr->right;
    Alr->left = Al;
    Alr->right = A;
    Al->parent = Alr;
    A->parent = Alr;

    A->balance_factor = 0;
    Al->balance_factor = 0;
    Alr->balance_factor = 0;

    return;
}

