#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"

void init_BST(BST *bstree) {
    *bstree = NULL;
    return;
}


treenode * make_node(int data) {
    treenode *newnode = (treenode *)malloc(sizeof(treenode));
    if (!newnode)
        return NULL;

    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}


/**
 * @brief Recursive insert in tree
 * 
 * @param tree 
 * @param dat 
 * 
 * @return node* 
 */
treenode * insert_recursion(BST *tree, int dat) {

    if (*tree == NULL) {
        treenode *newnode = (treenode *)malloc(sizeof(treenode));
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->data = dat;
        *tree = newnode;
        printf("Recursion done\n");
        return newnode;
    }
    if (dat < (*tree)->data) {
        treenode *left_child = insert_recursion(&((*tree)->left), dat);
        (*tree)->left = left_child;
        left_child->parent = (*tree);
    } else {
        treenode *right_child = insert_recursion(&((*tree)->right), dat);
        (*tree)->right = right_child;
        right_child->parent = (*tree);
    }
    
}

/**
 * @brief Iterative insertion in tree
 * 
 * @param bstree 
 * @param dat 
 */
void insert_node(BST *bstree, int dat) {
    treenode *newnode = (treenode *)malloc(sizeof(treenode));
    if (!newnode) return;
    newnode->data = dat;
    newnode->left = NULL;
    newnode->right = NULL;

    if (*bstree == NULL) {
        *bstree = newnode;
        return;
    } else {
        treenode *p = *bstree;
        treenode *q = NULL;


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
        newnode->parent = q;
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

/*Non recursive post order*/
void postorder(BST tree) {
    if (tree == NULL) 
        return;
    
    treenode *p = tree;
    treenode *q = NULL;
  

    Stack datastk;
    initStack(&datastk);

    while( p!= NULL || !isEmpty(datastk)){
    
        if (p->right) {
            push(&datastk, p->right);
        }
        
        push(&datastk, p);

        p = p->left;
         
        p = pop(&datastk);
        
    
        if (p) {
            if (p->right && p->right == peek(datastk)) {
                treenode *pop_right = pop(&datastk);

                push(&datastk, p);
                p = p->right;
            } else {
                printf("%d - %s\n", p->data);
                p = NULL;
            }
        }
        
    } while (!isEmpty(datastk));

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

    treenode *p = tree;

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

int is_leaf(treenode *p) {
    if (p->left == NULL && p->right == NULL)
        return 1;
    else
        return 0;
}

/**
 * @brief remove node from a tree
 * 
 * @param tree 
 * @param element 
 * @return 0/1 if node deletion succeedes/fails
 */
int removeNode(BST *tree, int misno) {
    treenode *p = search(*tree, misno);

    // Tree does not exist
    if (p == NULL) {
        return 0;
    }

    
    if (p->left == NULL && p->right == NULL) {
        // check if node is a root node or a leaf node
		// root node	
		if (p == *tree) {
			*tree = NULL;
			free(p);
			return 1;
		}

        // leaf node (no left/right child)
        treenode *temp = p->parent;
        if( p->parent->left == p){
            p->parent->left = NULL;
        }
        else if( p->parent->right == p){
            p->parent->right = NULL;
        }
        free(p);
        p = NULL;
		return 1;
    
    }
    else if(p->left == NULL && p->right != NULL) {
        // only has right child
        treenode *temp = p->right;
        if (p->parent->right == p) {
            p->parent->right = temp;
        }
        else if (p->parent->left == p) {
            p->parent->left = temp;
        }
        temp->parent = p->parent;
        
        
        free (p);
        p = NULL;
        return 1;
    }
    else if(p->left != NULL && p->right == NULL) {   
        // only has left child
        treenode *temp = p->left;
        if (p->parent->right == p) {
            p->parent->right = temp;
        }
        else if (p->parent->left == p) {
            p->parent->left = temp;
        }
        temp->parent = p->parent;
        free(p);
        p = NULL;
        return 1;
    } else if (p->left != NULL && p->right != NULL) { 
        // node has both child
        treenode *successor = inorderSuccessor(p);

        // node to be deleted is root of whole tree. Change the original root to
        // point it to new successor
        if (p == *tree) {
            *tree = successor;
        }

        treenode *q = successor->right;
        
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
        /*
        if (p->right == successor) {
            p->right->parent = p->parent;
            p->right = NULL;
        } else {
            if (q != NULL) {
                q->right = p->right;
                q->parent = successor;
            } else {
                successor->right = p->right;
                p->right->parent = successor;
                p->right = NULL;
            }
        }
        */

        return 1;
    }

}


int inorder_count_before_data(BST tree, int data) {
    int count = 0;
    if (tree == NULL) 
        return -1;
    inorder_traverse(tree->left);
    if (tree->data != data) {
        count++;
    }
    inorder_traverse(tree->right);
    return count;
}
