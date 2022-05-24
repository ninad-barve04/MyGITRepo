#include <stdio.h>
#include "tree.h"

int main(void)
{
    BST tree1;
    init_BST(&tree1);

//    printf("found/not found %d\n", search_node(tree1, 123));
    
    /*
    insert_node(&tree1, 100);
    insert_node(&tree1, 200);
    insert_node(&tree1, 50);
    insert_node(&tree1, 30);
    insert_node(&tree1, 40);
    insert_node(&tree1, 45);
    insert_node(&tree1, 10);
    insert_node(&tree1, 175);
    insert_node(&tree1, 150);
    insert_node(&tree1, 300);
    */
    
    int a[] = {100, 200, 50, 30, 40, 45, 10, 175, 150, 300};
    
    for (int i = 0; i < 10; i++) {
        insert_recursion(&tree1, a[i]);
    }

    inorder_traverse(tree1);
    printf("End of tree\n");

    preorder_traverse(tree1);
    printf("End of tree\n");
    
    postorder_traverse(tree1);
    printf("End of tree\n");

    printf("Count = %d\n", count_nodes(tree1));
    
    level_traversal(tree1, 2);
    printf("END\n");

    printf("\nCount non leaf = %d\n\n", count_non_leaf_nodes(tree1));

    int inorder_count = inorder_count_before_data(tree1, 40);
    printf("Count inorder before 40\ncount = %d\n", inorder_count);

    return 0;
}

