#include <stdio.h>
#include "tree.h"

int main(void)
{
    BST main_tree;
    init_BST(&main_tree);

    
    int choice = 10;
    while (choice != 0) {
        printf("-------------------\n");
        printf("List of operations which can be performed now\n");
		printf("1 : Add node to tree\n");
        printf("2 : Create prefilled tree\n");
        printf("3 : Traversal of tree \n");
        printf("4 : Display tree at given level\n");
        printf("5 : Remove node from tree\n");
        printf("6 : Search node in tree\n");
        printf("7 : Counting in tree\n");
        printf("8 : Find average of leaf nodes\n");
        printf("9 : Destroy tree\n");
		printf("0 : End the program\n");
        printf("\nEnter BS Tree operation to perform:\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("1 : Add node to tree\n");
                printf("Enter node to be added: ");
                int value = 0;
                scanf("%d", &value);
                insert_node(&main_tree, value);
                printf("\nNode with data %d was inserted iteratively\n", value);
                printf("\n");
                break;
            }

            case 2: {
                printf("2 : Create prefilled tree\n");
                destroy_tree(&main_tree);

                int a[] = {100, 200, 50, 30, 40, 45, 10, 175, 150, 300};    
                for (int i = 0; i < 10; i++) {
                    printf("%d  ", a[i]);
                    insert_recursion(&main_tree, a[i]);
                }
                printf("\nThe above values were inserted in the tree recursively\n");
                printf("\n");
                break;
            }
            
            case 3: {
                printf("3 : Traversal of tree \n");
                printf("\nTree traversals with choice number are as follows\n");
                printf("30: Inorder recursive\n");
                printf("31: Inorder iterative\n");
                printf("32: Preorder recursive\n");
                printf("33: Preorder iterative\n");
                printf("34: Postorder recursive\n");
                printf("35: Postorder iterative one stack\n");
                printf("36: Postorder iterative two stack\n");
                printf("\nEnter type of traversal: ");
                int traverssal = 0;
                scanf("%d", &traverssal);
                switch (traverssal) {
                    case 30: {
                        printf("30: Inorder recursive\n");
                        inorder_traverse_recursive(main_tree);
                        printf("End of tree\n");
                        break;
                    }

                    case 31: {
                        printf("31: Inorder iterative\n");
                        inorder_traverse_iterative(main_tree);
                        break;
                    }
                    
                    case 32: {
                        printf("32: Preorder recursive\n");
                        preorder_traverse_recursive(main_tree);
                        printf("End of tree\n");
                        break;
                    }
                    
                    case 33: {
                        printf("33: Preorder iterative\n");
                        preorder_traverse_iterative(main_tree);
                        break;
                    }
                    
                    case 34: {
                        printf("34: Postorder recursive\n");
                        postorder_traverse_recursive(main_tree);
                        printf("End of tree\n");
                        break;
                    }
                    
                    case 35: {
                        printf("35: Postorder iterative one stack\n");
                        postorder_traverse_iterative_onestack(main_tree);
                        break;
                    }
                    
                    case 36: {
                        printf("36: Postorder iterative two stack\n");
                        postorder_traverse_iterative_twostack(main_tree);
                        break;
                    }
                    
                    default: {
                        break;
                    }
                }
                printf("\n");
                break;
            }
            
            case 4: {
                printf("4 : Display tree at given level\n");
                printf("Enter level of tree to display: ");
                int level = 0;
                scanf("%d", &level);
                level_traversal(main_tree, level);
                printf("\n\n");
                break;
            }
            
            case 5: {
                printf("5 : Remove node from tree\n");
                printf("Enter node value to be removed: ");
                int value = 0;
                scanf("%d", &value);
                int status = remove_node(&main_tree, value);
                if (status == 1) {
                    printf("Node removed successfully!\n");
                } 
                else if (status == 2) {
                    printf("Node with value not found\n");
                }
                else if (status == 0) {
                    printf("Tree is empty (NULL) or Does not exist\n");
                } else {
                    printf("Error has occurred in deletion of mentioned node\n");
                }
                printf("\n");
                break;
            }
            
            case 6: {
                printf("6 : Search node in tree\n");
                printf("Only denotes if node is found\n");
                printf("Enter node to be searched: ");
                int node = 0;
                scanf("%d", &node);
                treenode *found = search_node(main_tree, node);
                if (found != NULL) {
                    printf("Node with value %d exists in the tree\n", node);
                } else {
                    printf("Node with value %d does not exist in the tree\n", node);
                }
                printf("\n");
                break;
            }
            
            case 7: {
                printf("7 : Counting in tree\n");
                printf("70: Count total nodes in tree\n");
                printf("71: Count non leaf nodes in tree\n");
                printf("72: Count leaf nodes in tree\n");
                printf("73: Count inorder elements before data\n");
                printf("Enter counting choice: ");
                int cc = 0;
                scanf("%d", &cc);
                
                switch (cc) {
                    case 70: {
                        printf("70: Count total nodes in tree\n");
                        printf("Total number of nodes in given tree is %d\n", count_nodes(main_tree));
                        break;
                    }

                    case 71: {
                        printf("71: Count non leaf nodes in tree\n");
                        printf("Total number of non-leaf nodes in given tree is %d\n", count_non_leaf_nodes(main_tree));
                        break;
                    }
                    
                    case 72: {
                        printf("72: Count leaf nodes in tree\n");
                        printf("Total number of leaf nodes in given tree is %d\n", count_leaf_nodes(main_tree));
                        break;
                    }
                    
                    case 73: {
                        printf("73: Count inorder elements before data\n");
                        printf("Enter element for counting: ");
                        int element = 0;
                        scanf("%d", &element);
                        printf("Total number of inorder elements (found iteratively) before %d is \n%d\n", element, inorder_count_before_data(main_tree, element));
                        break;
                    }
                    
                    default: {
                        break;
                    }
                    
                }

                printf("\n");
                break;
            }
            
            case 8: {
                printf("8 : Find average of leaf nodes\n");
                printf("The average of leaf nodes in the tree is %f\n", leaf_node_average(main_tree));
                printf("\n");
                break;
            }
            
            case 9: {
                printf("9 : Destroy tree\n");
                destroy_tree(&main_tree);
                printf("The tree has been destroyed!!\n");
                printf("\n");
                break;
            }

            default: {
                printf("\n");
                break;
            }
            
        }

    }

    return 0;
}

