#include <stdio.h>
#include <stdlib.h>

#include "avl.h"
#include "avl_utilities.h"
#include "avl_rotations.h"


/**
 * @brief Initialize the AVl tree
 * 
 * @param tree 
 */
void initAVL(AVL *tree) {
    *tree = NULL;
    return;
}


/**
 * @brief Insert a newnode according to the AVL rules
 * 
 * @param tree reference of tree structure in main
 * @param newmonth name of the new month
 * @return int 1 if successful, else 0
 */
int insertNode(AVL *tree, int element) {
    
    printf("\nInserting Data = %d\n", element);
    // newnode creation
    avlnode *newnode = (avlnode *)malloc(sizeof(avlnode));
    if (newnode == NULL) {
        return 0;
    }
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = element;
    if (*tree == NULL) {
        newnode->parent = NULL;
        *tree = newnode;
        return 1;
    }
    avlnode *p = *tree;
    avlnode *q = NULL;
    // Binary search tree insertion of newnode
    while (p != NULL) {
        q = p;

        if (p->data == element) {
            return 0;
        } else if (element > p->data) {
            p = p->right;
        } else {
            p = p->left;
        }

    }

    // Set parent pointers
    newnode->parent = q;
    if (element > q->data) {
        q->right = newnode;
    } else {
        q->left = newnode;
    }
    
    // Adjust the balance factors for the whole path upwards from newnode
    adjustBalanceFactor(&newnode);
    
    // Find imbalanced node
    avlnode *imbalanced = findImbalance(newnode->parent);
    if (imbalanced == NULL) {
        return 1;
    }

    while (imbalanced != NULL) {
        performRotation(tree, imbalanced, element);
        adjustBalanceFactor(&newnode);
        imbalanced = findImbalance(imbalanced);
    }

    return 1;
}


/**
 * @brief Remove the node from the tree while maintaining its AVL nature
 * 
 * @param tree reference of the tree initialized in main
 * @param month name of the month to be removed
 * @return int 1 if successful, else 0
 */
int removeNode(AVL *tree, int element) {
    
    printf("Removing %d\n", element);
    // Tree does not exist
    if (*tree == NULL) {
        return 0;
    }
    avlnode *p = searchNode(*tree, element);
    // Node not found
    if (p == NULL) {
        return 0;
    }
    avlnode *parentnode = p->parent;
    if (p->left == NULL && p->right == NULL) {
        // check if avlnode is a root node or a leaf node
        // root node	
        if (p == *tree) {
            *tree = NULL;
            free(p);
        }

        // leaf node (no left/right child)
        avlnode *temp = p->parent;
        if( temp->left == p){
            temp->left = NULL;
        }
        else if( p->parent->right == p){
            p->parent->right = NULL;
        }
        free(p);
        p = NULL;
        
    }
    else if(p->left == NULL && p->right != NULL) {
        // only has right child
        avlnode *temp = p->right;
        if (p->parent->right == p) {
            p->parent->right = temp;
        }
        else if (p->parent->left == p) {
            p->parent->left = temp;
        }
        temp->parent = p->parent;
        
        
        free (p);
        p = NULL;
    }
    else if(p->left != NULL && p->right == NULL) {   
        // only has left child
        avlnode *temp = p->left;
        if (p->parent->right == p) {
            p->parent->right = temp;
        }
        else if (p->parent->left == p) {
            p->parent->left = temp;
        }
        temp->parent = p->parent;
        free(p);
        p = NULL;
    } else if (p->left != NULL && p->right != NULL) { 
        // avlnode has both child
        avlnode *successor = inorderSuccessor(p);

        // node to be deleted is root of whole tree. Change the original root to
        // point it to new successor
        if (p == *tree) {
            *tree = successor;
        }

        avlnode *q = successor->right;
        
        // separate left branch of node to be deleted and set it to sucessor
        successor->left = p->left;
        p->left->parent = successor;
        p->left = NULL;

        // change left and/or right pointers of p->parent to set it to successor
        if (p->parent != NULL && p->parent->right == p) {
            p->parent->right = successor;
        }
        else if (p->parent != NULL && p->parent->left == p) {
            p->parent->left = successor;
        }

        // successor's parent will never have a left node or else, the successor
        // will be located in that subtree
        successor->parent->left = NULL;
        // set parent of successor same as parent of node to be deleted 
        successor->parent = p->parent;
        
        if (q != NULL) {
            if (p->right != successor) {
                q->right = p->right;
                q->parent = successor;
            }
                
        } else {
            if (p->right == successor) {
                p->right->parent = p->parent;
                p->right = NULL;
            } else {
                successor->right = p->right;
                p->right->parent = successor;
                p->right = NULL;
            }
        }

    }

    adjustBalanceFactor(&parentnode);
    avlnode *imbalanced = findImbalance(parentnode);
    if (imbalanced == NULL) {
        return 1;
    }
    //printf("Imbalanced at data = %d\n", imbalanced->month);
    while (imbalanced != NULL) {
        performRotation(tree, imbalanced, element);
        adjustBalanceFactor(&parentnode);
        imbalanced = findImbalance(imbalanced);
    }

    return 1;
}


/**
 * @brief Traverse the tree as per given direction
 * 
 * @param tree 
 * @param type 1 = inorder; 2 = preorder and 3 = postorder
 */
void traverse(AVL tree, int type) {
    if (type == 1) {
        inorderTraversal(tree);
    } else if (type == 2) {
        preorderTraversal(tree);
    } else if (type == 3) {
        postorderTraversal(tree);
    }
}

/**
 * @brief Traversals 
 */
void inorderTraversal(AVL tree) {
    if (tree == NULL) {
        return;
    }
    inorderTraversal(tree->left);
    if (tree->parent != NULL) {
        printf("(%d)\t<==\t[%d]\n", tree->data, tree->parent->data);
    } else {
        int x = 0;
        printf("(%d)\t<==\t[%d] \n", tree->data, x);
    }
    inorderTraversal(tree->right);
}

void preorderTraversal(AVL tree) {
    if (tree == NULL) {
        return;
    }
    
    if (tree->parent != NULL) {
        printf("(%d)\t<==\t[%d]\n", tree->data, tree->parent->data);
    } else {
        int x = 0;
        printf("(%d)\t<==\t[%d] \n", tree->data, x);
    }
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);

}

void postorderTraversal(AVL tree) {
    if (tree == NULL) {
        return;
    }
    
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    if (tree->parent != NULL) {
        printf("(%d)\t<==\t[%d]\n", tree->data, tree->parent->data);
    } else {
        int x = 0;
        printf("(%d)\t<==\t[%d] \n", tree->data, x);
    }
    
}


/**
 * @brief Destroys and frees every node of the tree
 * 
 * @param tree 
 */
void destroyTree(AVL *tree) {
    if (*tree == NULL) {
        return;
    }
    destroyTree(&((*tree)->left));
    destroyTree(&((*tree)->right));
    free(*tree);
    *tree = NULL;
}
