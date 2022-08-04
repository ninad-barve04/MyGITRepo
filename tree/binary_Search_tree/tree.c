#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.h"


/**
 * @brief Initialization of a Binary Search Tree
 * 
 * @param bstree 
 */
void init_BST(BST *bstree) {
    *bstree = NULL;
    return;
}


/**
 * @brief Create a node with passed data
 * 
 * @param data Data to keep in node
 * @return treenode* Created node
 */
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
        /*
         * This means that the newnode will be the root of the tree 
         */
        treenode *newnode = (treenode *)malloc(sizeof(treenode));
        if (!newnode) return; // Check if malloc is successful
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->data = dat;
        *tree = newnode;
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

    return (*tree);
    
}

/**
 * @brief Iterative insertion in tree
 * 
 * @param bstree 
 * @param dat 
 */
void insert_node(BST *bstree, int dat) {
    treenode *newnode = (treenode *)malloc(sizeof(treenode));
    if (!newnode) return; // Check if the malloc is successful
    newnode->data = dat;
    newnode->left = NULL;
    newnode->right = NULL;

    if (*bstree == NULL) {
        *bstree = newnode;
        return;
    } else {
        treenode *p = *bstree;
        treenode *q = NULL;

        /*
         * Traverse the tree following BST rules till the pointer has reached 
         * NULL, i.e. The child of a leaf node
         */
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



/**
 * @brief Recursive inorder traversal and display
 * 
 * @param tree 
 */
void inorder_traverse_recursive(BST tree) {
    if (tree == NULL) 
        return;
    inorder_traverse_recursive(tree->left);
    printf("%d - ", tree->data);
    inorder_traverse_recursive(tree->right);
    return;
}

/**
 * @brief Recursive preorder traversal and display
 * 
 * @param tree 
 */
void preorder_traverse_recursive(BST tree) {
    if (tree == NULL) 
        return;
    printf("%d - ", tree->data);
    preorder_traverse_recursive(tree->left);
    preorder_traverse_recursive(tree->right);
}

/**
 * @brief Recursive postorder traversal and display
 * 
 * @param tree 
 */
void postorder_traverse_recursive(BST tree) {
    if (tree == NULL) 
        return;
    postorder_traverse_recursive(tree->left);
    postorder_traverse_recursive(tree->right);
    printf("%d - ", tree->data);
}


/*
 * To convert any recursive code to an iterative code, we always need a stack
 */

/**
 * @brief Iterative inorder traversal and display
 * @param tree 
 */
void inorder_traverse_iterative(BST tree) {
    if (tree == NULL) {
        return;
    }

    Stack stk;
    initStack(&stk);

    treenode *current = tree;
    treenode *popped = NULL;
    while (current != NULL || !isEmpty(stk)) {
          
        if (current != NULL){   
            push(&stk, current);
            //printf("%d\n", current->data);   
            current = current->left;
        }

        if (current == NULL && !isEmpty(stk)) {
            popped = pop(&stk);
            printf("%d - ", popped->data);
            current = popped->right;
        }

    }

    printf("End of tree\n");
    return;
}


/**
 * @brief Iterative preorder traversal and display
 * 
 * @param tree 
 */
void preorder_traverse_iterative(BST tree) {
    if (tree == NULL)
        return;

    Stack stack;
    initStack(&stack);

    treenode *root = tree;
    treenode *popped = NULL;

    push(&stack, root);

    while (!isEmpty(stack)) {
        popped = pop(&stack);
        printf("%d - ", popped->data);

        if (popped->right != NULL) {
            push(&stack, popped->right);
        }
        if (popped->left != NULL) {
            push(&stack, popped->left);
        }
    }

    printf("End of tree\n");

    return;
}


/**
 * @brief Iterative postorder traversal and display using single stack
 * 
 * @param tree 
 */
void postorder_traverse_iterative_onestack(BST tree) {
    if (tree == NULL) 
        return;
    
    treenode *root = tree;
    treenode *popped = NULL;
    treenode *peeked = NULL;
  

    Stack datastk;
    initStack(&datastk);

    do {
        while (root != NULL) {
            if (root->right != NULL) {
                push(&datastk, root->right);
            }
            push(&datastk, root);
            root = root->left;
        }

        popped = pop(&datastk);
        root = popped;
        peeked = peek(datastk);
        if (popped->right != NULL && popped->right == peeked) {
            pop(&datastk);
            push(&datastk, root);
            root = root->right;
        } else {
            printf("%d - ", root->data);
            root = NULL;
        }

    } while (!isEmpty(datastk));

    printf("End of tree\n");

    return;
}

/**
 * @brief Iterative postorder traversal and display using double stack
 * 
 * @param tree 
 */
void postorder_traverse_iterative_twostack(BST tree) {
    if (tree == NULL) 
        return;

    Stack stack1;
    initStack(&stack1);
    Stack stack2;
    initStack(&stack2);

    treenode *root = tree;
    treenode *popped = NULL;

    push(&stack1, root);
    while (!isEmpty(stack1)) {
        popped = pop(&stack1);
        push(&stack2, popped);
        if (popped->left != NULL) {
            push(&stack1, popped->left);
        }
        if (popped->right != NULL) {
            push(&stack1, popped->right);
        }
    }

    while (!isEmpty(stack2)) {
        popped = pop(&stack2);
        printf("%d - ", popped->data);
    }

    printf("End of tree\n");

    return;
}


/**
 * @brief Level order traversal of a tree
 * 
 * @param tree 
 * @param level Level which is to be traversed
 */
void level_traversal(BST tree, int level) {
    if (tree == NULL) return;
    if (level == 1) {
        printf("%d - ", tree->data);
    } else if (level > 1) {
        level_traversal(tree->left, level - 1);
        level_traversal(tree->right, level - 1);
    }
}


/**
 * @brief Calculate height of tree recursively
 * 
 * @param tree 
 * @return int height
 */
int tree_height(BST tree) {
    if (tree == NULL) {
        return -1;
    }
    int height = 1 + MAX(tree_height(tree->left), tree_height(tree->right));

    return height;
}


/**
 * @brief Count number of nodes recursively
 * 
 * @param tree 
 * @return int number of nodes
 */
int count_nodes(BST tree) {
    int count=0;
    if (tree == NULL) {
        return 0;
    }
    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}


/**
 * @brief Check if a given binary tree is also a Binary Search Tree
 * 
 * @param tree 
 * @return int 1 if tree is a BST, else 0
 */
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


/**
 * @brief Count number of leaf nodes of a tree
 * 
 * @param tree 
 * @return int 
 */
int count_leaf_nodes(BST tree) {
    if (tree == NULL) {
        return 0;
    }
    if (tree->left == NULL && tree->right == NULL) {
        return 1;
    } else {
        return count_leaf_nodes(tree->left) + count_leaf_nodes(tree->right);
    }
}


/**
 * @brief Count number of non leaf nodes
 * 
 * @param tree 
 * @return int 
 */
int count_non_leaf_nodes(BST tree) {

    return count_nodes(tree) - count_leaf_nodes(tree);

}


/**
 * @brief Search the node in tree
 * 
 * @param tree 
 * @param element value of node to be found
 * @return treenode* pointer to the node if it is found, else NULL
 */
treenode * search_node(BST tree, int element) {
    if (tree == NULL)
        return NULL;

    treenode *p = tree;

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
 * @brief Check if the node passed is a leaf node
 * 
 * @param p 
 * @return int 
 */
int is_leaf(treenode *p) {
    if (p->left == NULL && p->right == NULL) {
        return 1;
    } else {
        return 0;
    }
}


/**
 * @brief Find the inorder successor, i.e. next element in ascending order
 * 
 * @param tree 
 * @return treenode* pointer to the successor node
 */
treenode *inorderSuccessor(BST tree) {
    treenode *p = tree;

    p = p->right;
    while (p != NULL && p->left != NULL) {
        p = p->left;
    }

    return p;
}


/**
 * @brief Remove node from a tree. The value in sucessor is copied to the node 
 *        to be deleted
 * 
 * @param tree 
 * @param element Value of node to be deleted
 * @return 0/1 if node deletion succeedes/fails
 */
int remove_node(BST *tree, int misno) {
    /*
     * Check if the tree exists
     */
    if (*tree == NULL) {
        return 0;
    }

    /*
     * Check if the node to be deleted actually exists in the tree
     */
    treenode *p = search_node(*tree, misno);
    if (p == NULL) {
        return 2;
    }

    if (p->left == NULL && p->right == NULL) {
        /*
         * Node is a leaf node
         */
        if (p == *tree) {
            *tree = NULL;
            free(p);
            return 1;
        }

        if (p->parent->left == p){
            p->parent->left = NULL;
        }
        else if (p->parent->right == p){
            p->parent->right = NULL;
        }
        free(p);
        p = NULL;
        return 1;
    
    } 
    else if (p->left == NULL && p->right != NULL) {
        /*
         * Node has only right child
         */
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
    else if (p->left != NULL && p->right == NULL) {   
        /*
         * Node has only left child
         */
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

    } 
    else if (p->left != NULL && p->right != NULL) { 
        /*
         * Node has both children. In this case, the node is replaced by its 
         * inorder successor/predecessor 
         */
        treenode *successor = inorderSuccessor(p);

        p->data = successor->data;

        successor->parent->left = successor->right;

        successor = NULL;
        free(successor);

        return 1;
    }

}


/**
 * @brief Count number of elements in inorder traversal less than a value
 * 
 * @param tree 
 * @param element 
 * @return int 
 */
int inorder_count_before_data(BST tree, int element) {
    int count = 0;
    inorder_count_before_data_recursion(tree, element, &count);
    return count;
}

/**
 * @brief Actual recursive code to count number of elements les than data in 
 *        inorder
 * 
 * @param tree 
 * @param element 
 * @param count 
 */
void inorder_count_before_data_recursion(BST tree, int element, int *count) {
    if (tree == NULL) 
        return;
    inorder_count_before_data_recursion(tree->left, element, count);
    if (tree->data < element) {
        (*count)++;
    }
    inorder_count_before_data_recursion(tree->right, element, count);
    return;
}


/**
 * @brief Calculate the average value of the leaf nodes of the tree
 * 
 * @param tree 
 * @return float average value returned as a float
 */
float leaf_node_average(BST tree) {
    int sum = 0, count = 0;
    Stack stack;
    initStack(&stack);

    treenode *p = tree;

    push(&stack, p);
    while (!isEmpty(stack)) {
        treenode *current = pop(&stack);

        if (current->left != NULL) {
            push(&stack, current->left);
        }

        if (current->right != NULL) {
            push(&stack, current->right);
        }

        if (current->left == NULL && current->right == NULL) {
            sum = sum + (current->data);
            count++;
        }
    }
    
    float avg = ((float)sum/(float)count);
    return avg;
}


/**
 * @brief Completely destroy the tree by freeing each node
 * 
 * @param tree 
 */
void destroy_tree (BST *tree) {
    if ((*tree) == NULL) {
        return;
    }
    
    if ((*tree)->left == NULL && (*tree)->right == NULL) {
        free(*tree);
        *tree = NULL;
        return;
    }

    destroy_tree(&((*tree)->left));
    destroy_tree(&((*tree)->right));
}
