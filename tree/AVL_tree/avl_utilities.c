#include <string.h>
#include <stdlib.h>

#include "avl.h"
#include "avl_utilities.h"


/**
 * @brief Finds the height of the subtree
 * 
 * @param tree 
 * @return int 
 */
int findHeight(AVL tree) {
    if (tree == NULL) {
        return -1;
    }
    int height = 1+MAX(findHeight(tree->left), findHeight(tree->right));
    // printf("Height = %d\tNode = %d\n", height, tree->data);
    return height;
}


/**
 * @brief Calculated the balance factor
 *        BF = height of left subtree - height of right subtree
 * 
 * @param node 
 * @return int 
 */
int balanceFactor(avlnode *node) {
    // printf("%p, %p, %p\n", node, node->left, node->right);
    int hl = findHeight(node->left);
    //printf("HL %d\t", hl);
    int hr = findHeight(node->right);
    //printf("HR %d\t%d\n", hr, node->month);
    return hl - hr;
}


/**
 * @brief Checks if the balance factor of passed node is out of range
 * 
 * @param node 
 * @return int 1 if not balanced, else 0
 */
int isNotBalanced(avlnode *node) {
    printf("\tChecking isNotBalanced()\n\telement = %d\tbf = %d\n", node->data, node->balance_factor);
    if (node->balance_factor > 1 || node->balance_factor < -1) {
        return 1;
    }
    return 0;
}


/**
 * @brief Finds the node at which imbalance is present in ancestor of newnode
 * 
 * @param leafnode 
 * @return avlnode* pointer to the imbalanced node
 */
avlnode * findImbalance(avlnode *leafnode) {
    avlnode *p = leafnode;

    while (p != NULL) {
        if (isNotBalanced(p) == 1) {
            printf("\tImbalance at %d\n", p->data);
            return p;
        }
        p = p->parent;
    }

    
    return p;
}


/**
 * @brief Reassigns the balance factors to the parent line of passed node
 * 
 * @param node 
 */
void adjustBalanceFactor(avlnode **node) {
    if (*node == NULL) {
        return;
    }
    
    (*node)->balance_factor = balanceFactor(*node);
    //printf("%d\t%d\n", (*node)->month, (*node)->balance_factor);
    adjustBalanceFactor(&((*node)->parent));
}


/**
 * @brief Searches the tree for passed node
 * 
 * @param tree 
 * @param month 
 * @return avlnode* pointer to the node if found, else NULL
 */
avlnode *searchNode(AVL tree, int element) {
    if (tree == NULL)
        return 0;

    avlnode *p = tree;

    while (p != NULL) {
        if (p->data == element) {
            return p;
        } else if (p->data > element) {
            p = p->left;
        } else if (p->data < element) {
            p = p->right;
        }
    }
    return NULL;
}


/**
 * @brief Finds the next largest number to the current node in the tree
 *        successor = leftmost child of tree->right
 * 
 * @param tree 
 * @return avlnode* 
 */
avlnode *inorderSuccessor(AVL tree) {
    avlnode *p = tree;

    p = p->right;
    while (p != NULL && p->left != NULL) {
        p = p->left;
    }
    //printf("%d - \n",  p->right->MIS);
    return p;
}

