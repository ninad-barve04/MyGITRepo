#include <stdio.h>
#include <stdlib.h>

#include "red_black.h"
#include "red_black_utils.h"


void init_RBtree(RBtree *tree) {
    tree = NULL;
    return;
}


void insert_RBtree(RBtree *tree, int value) {
    rbnode *newnode = (rbnode *)malloc(sizeof(rbnode));
    newnode->color = RED;
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;

    if (*tree == NULL) {
        newnode->color = BLACK;
        *tree = newnode;
        return;
    } else {
        rbnode *p = *tree;
        rbnode *q = NULL;

        while (p != NULL) {
            q = p;
            if (newnode->data > p->data) {
                p = p->right;
            } else if (newnode->data < p->data) {
                p = p->left;
            } else {
                return;
            }
        }
        if (newnode->data > q->data) {
            q->right = newnode;
        } else {
            q->left = newnode;
        }
        newnode->parent = q;
    }
    // Normal BST insertion done
    // Now recoloring/reordering

    if (newnode->parent->color == BLACK) {
        return;
    }

    rbnode *unclenode = get_uncle(tree, newnode);
    if (unclenode != NULL && unclenode->color == RED) {
        recolor(newnode->parent);
        recolor(unclenode);
        if (newnode->parent->parent != (*tree)) {
            recolor(newnode->parent->parent);
        }
    } else if (unclenode->color == BLACK || unclenode == NULL) {
        
    }

}
