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
    //printf("Height = %d\tNode = %d\n", height, tree->month);
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


/**
 * @brief Get the Lower Case string of passed string
 * 
 * @param s 
 * @return char* 
 */
char * getUpperCase(char *s) {
    int len = strlen(s);
    char *temp = (char*)malloc( sizeof(char)*len);
    int i = 0;
    char c = s[i];
    while (c != '\0') {
        if (c >= 'a' && c <= 'z') {
            c = c - 32;
        }
        temp[i] = c;
        i++;
        c = s[i];
    }
    
    return temp;
}


/**
 * @brief Get the Month Number correnponding to passed monthname
 * 
 * @param monthname 
 * @return int 
 */
int getMonthNumber(char *monthname) {
    monthname = getUpperCase(monthname);
    if (strcmp(monthname, "APRIL") == 0) {
        return 1;
    } else if (strcmp(monthname, "AUGUST") == 0) {
        return 2;
    } else if (strcmp(monthname, "DECEMBER") == 0) {
        return 3;
    } else if (strcmp(monthname, "FEBRUARY") == 0) {
        return 4;
    } else if (strcmp(monthname, "JANUARY") == 0) {
        return 5;
    } else if (strcmp(monthname, "JULY") == 0) {
        return 6;
    } else if (strcmp(monthname, "JUNE") == 0) {
        return 7;
    } else if (strcmp(monthname, "MARCH") == 0) {
        return 8;
    } else if (strcmp(monthname, "MAY") == 0) {
        return 9;
    } else if (strcmp(monthname, "NOVEMBER") == 0) {
        return 10;
    } else if (strcmp(monthname, "OCTOBER") == 0) {
        return 11;
    } else if (strcmp(monthname, "SEPTEMBER") == 0) {
        return 12;
    }
}


