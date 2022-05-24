#ifndef TREE_H
#define TREE_H (1)

typedef struct treenode {
    int data;
    struct treenode *left, *right;
    struct treenode *parent;
}treenode;

typedef treenode * BST;

void init_BST(BST *bstree);
treenode * make_node(int data);

void insert_node(BST *bstree, int dat);
treenode * insert_recursion(BST *tree, int dat);

void inorder_traverse(BST tree);
void preorder_traverse(BST tree);
void postorder_traverse(BST tree);
int count_nodes(BST tree);
int verify_BST(BST tree);
void level_traversal(BST tree, int level);
int count_non_leaf_nodes(BST tree);
int count_leaf_nodes(BST tree);
int search_node(BST tree, int element);
void delete_node(BST *tree, int element);
int inorder_count_before_data(BST tree, int data);

#endif /* ifndef TREE_H */

