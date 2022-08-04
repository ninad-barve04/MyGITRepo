#include <stdio.h>
#include <stdlib.h>

#include "red_black.h"


void recolor(rbnode *node) {
    if (node->color == RED) {
        node->color = BLACK;
    } else if (node->color == BLACK) {
        node->color = RED;        
    }
    return;
}


rbnode *get_uncle(RBtree *tree, rbnode *curr_node) {
    rbnode *unclenode = NULL;
    if (curr_node->parent->parent != NULL) {
        rbnode *parent_node = curr_node->parent;
        rbnode *grandparent = parent_node->parent;
        if (parent_node == grandparent->right) {
            unclenode = grandparent->left;
        } else if (parent_node == grandparent->left) {
            unclenode = grandparent->right;
        }
    }
    return unclenode;
}