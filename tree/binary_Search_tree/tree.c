#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void init_BST(BST *bstree) {
    *bstree = NULL;
    return;
}


node * make_node(int data) {
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode)
        return NULL;

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


void insert_recursion(BST *tree, int dat) {
//    node *p = *tree;
    if (*tree == NULL) {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->data = dat;
        *tree = newnode;
        printf("Recursion done\n");
        return;
    }
    if (dat < (*tree)->data) {
        insert_recursion(&((*tree)->left), dat);
    } else {
        insert_recursion(&((*tree)->right), dat);
    }
    
}


void insert_node(BST *bstree, int dat) {
    node *newnode = (node *)malloc(sizeof(node));
    if (!newnode) return;
    newnode->data = dat;
    newnode->left = NULL;
    newnode->right = NULL;

    if (*bstree == NULL) {
        *bstree = newnode;
        return;
    } else {
        node *p = *bstree;
        node *q = NULL;


        while (p != NULL) {
            q = p;
            if (p->data > dat) {
                p = p->left;
            } else if (p->data < dat) {
                p = p->right;
            } else {
                return;
            }
        }
        if (dat < q->data) {
            q->left = newnode;
        } else {
            q->right = newnode;
        }
    }
}


void inorder_traverse(BST tree) {
    if (tree == NULL) 
        return;
    inorder_traverse(tree->left);
    printf("%d - ", tree->data);
    inorder_traverse(tree->right);
    return;
}


void preorder_traverse(BST tree) {
    if (tree == NULL) 
        return;
    printf("%d - ", tree->data);
    preorder_traverse(tree->left);
    preorder_traverse(tree->right);
}


void postorder_traverse(BST tree) {
    if (tree == NULL) 
        return;
    postorder_traverse(tree->left);
    postorder_traverse(tree->right);
    printf("%d - ", tree->data);
}

// count, verify, height/depth, level wise traversal, no of leaf and non-leaf
// nodes

int count_nodes(BST tree) {
    int count=0;
    if (tree == NULL) {
        return 0;
    }
    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}


int verify_BST(BST tree) {
    if (tree == NULL) return 1;

    if (tree->right->data > tree->data && tree->left->data < tree->data) {
        verify_BST(tree->left);
        verify_BST(tree->right);
        return 1;
    } else {
        return 0;
    }
}


void level_traversal(BST tree, int level) {
    if (tree == NULL) return;
    if (level == 1) {
        printf("%d - ", tree->data);
    } else if (level > 1) {
        level_traversal(tree->left, level - 1);
        level_traversal(tree->right, level - 1);
    }
}


int count_non_leaf_nodes(BST tree) {
    if (tree == NULL) return -1;

    return count_nodes(tree->left) + count_nodes(tree->right);

}


int search_node(BST tree, int element) {
    if (tree == NULL)
        return 0;

    node *p = tree;

    while (p != NULL) {
        if (p->data == element) {
            return 1;
        } else if (p->data > element) {
            p = p->left;
        } else if (p->data < element) {
            p = p->right;
        }
    }
    return 0;
}

/*Search make it to return pointer to found element
 * If not found, return NULL*/

/*Write is leaf function*/

int is_leaf(node *p) {
    if (p->left == NULL && p->right == NULL)
        return 1;
    else
        return 0;
}


void delete_node(BST *tree, int element) {
    if (*tree == NULL)
        return;

    node *p = *tree;
    node *q;
    while (p != NULL) {
        if (p->data == element) 
            break;
        q = p;
        if (p->data > element) {
            p = p->left;
        } else if (p->data < element) {
            p = p->right;
        }
    }

    if (p == NULL)
        return;

    //is p a leaf node 
    if (is_leaf(p)) {
        if (q->left == p) {
            q->left = NULL;
        } else {
            q->right = NULL;
        }
        free(p);    
        return;
    }

    // p->left == NULL. Node to be deleted has only 
    // right child

    if (p->left == NULL && p->right != NULL) {
        p->right = q;
        p->data = q->data;
    }
    return;
}
