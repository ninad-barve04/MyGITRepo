/**
 * @file tree.h
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef TREE_H
#define TREE_H (1)

#define MAX(a, b) ((a > b) ?  a:  b)

/************ Typedefs ************/
/**
 * @brief Node of tree data structure
 * 
 */
typedef struct treenode {
    int data;
    struct treenode *left, *right;
    struct treenode *parent;
}treenode;

/**
 * @brief Typedef for tree datastructure 
 */
typedef treenode * BST;


/************ Initialization Functions ************/
void init_BST(BST *bstree);
treenode * make_node(int data);


/************ Insertion of node ************/
void insert_node(BST *bstree, int dat);
treenode * insert_recursion(BST *tree, int dat);


/************ Tree traversals ************/
/****** Recursive ******/
void inorder_traverse_recursive(BST tree);
void preorder_traverse_recursive(BST tree);
void postorder_traverse_recursive(BST tree);

/****** Iterative ******/
void inorder_traverse_iterative(BST tree);
void preorder_traverse_iterative(BST tree);
void postorder_traverse_iterative_onestack(BST tree);
void postorder_traverse_iterative_twostack(BST tree);
void level_traversal(BST tree, int level);


/************ Counting nodes ************/
int count_nodes(BST tree);
int count_non_leaf_nodes(BST tree);
int count_leaf_nodes(BST tree);
int inorder_count_before_data(BST tree, int element);
void inorder_count_before_data_recursion(BST tree, int data, int *count);


/************ Verification ************/
int verify_BST(BST tree);


/************ Searching and removal ************/
treenode * search_node(BST tree, int element);
treenode *inorderSuccessor(BST tree);
int remove_node(BST *tree, int element);


/************ Finding average of leaf nodes ************/
float leaf_node_average(BST tree);


/************ Complete tree deletion ************/
void destroy_tree (BST *tree);

#endif /* ifndef TREE_H */

