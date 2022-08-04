#include <stdio.h>

#include "avl.h"
#include "avl_utilities.h"


int main(int argc, char const *argv[])
{
    AVL tree;
    initAVL(&tree);

    
    int x = 0;
    x = insertNode(&tree,  12);
    printf("\n%d\nFirst insertion done\n\n", x);
    x = insertNode(&tree,  1);
    printf("\n%d\nSecond insertion done\n\n", x);
    x = insertNode(&tree,  4);
    printf("\n%d\nThird insertion done\n\n", x);
    x = insertNode(&tree,  3);
    printf("\n%d\nFourth insertion done\n\n", x);
    x = insertNode(&tree,  7);
    printf("\n%d\nFifth insertion done\n\n", x);
    x = insertNode(&tree,  8);
    printf("\n%d\nSixth insertion done\n\n", x);
    x = insertNode(&tree,  10);
    printf("\n%d\nSeventh insertion done\n\n", x);
    x = insertNode(&tree,  2);
    printf("\n%d\nEighth insertion done\n\n", x);
    x = insertNode(&tree,  9);
    printf("\n%d\nNinth insertion done\n\n", x);
    x = insertNode(&tree,  5);
    printf("\n%d\nTenth insertion done\n\n", x);
    x = insertNode(&tree,  6);
    printf("\n%d\nEleventh insertion done\n\n", x);


    traverse(tree, 1);printf("END\n");
    traverse(tree, 2);printf("END\n");
    traverse(tree, 3);printf("END\n");
    
    //removeNode(&tree, "June");
    //traverse(tree, 3);printf("END\n");

    destroyTree(&tree);
    traverse(tree, 1);printf("END\n");
    

    
    // int operation =10;
    
    // while ( operation !=0){
        
    //     printf("\n-------------------\n");
    //     printf("Enter AVL Tree operation to perform:\n");
    //     printf("1: Add node to tree\n");
    //     printf("2: Remove node from tree\n");
    //     printf("3: Search node in tree\n");
    //     printf("4: Display tree nodes as per traversal\n");
    //     printf("5: Destroy tree\n");
    //     printf("0: End the program\n");

    //     printf("\nEnter operation: ");

    //     scanf("%d",&operation);
    //     if( operation == 0 ){
    //         printf("Exiting program, Thank You!\n");
    //         break;
    //     }

    //     printf("\n\n");
    //     switch(operation){
    //         case 1:{
    //             printf ("Enter element\n");
    //             int element;
    //             scanf("%d", &element);
    //             insertNode(&tree, element);
    //             break;
    //         }
    //         case 2:{
    //             printf ("Enter element to remove\n");
    //             int element;
    //             scanf("%d", &element);
    //             int node = removeNode(&tree, element);

    //             if( node == 0){
    //                 printf("Element %d not found in tree\n", element);
    //             }
    //             else{ 
    //                 printf("Node with data %d removed from tree\n", element);
    //             }
    //             break;
    //         }
    //         case 3:{
    //             printf ("Enter Element to Search\nNumber: ");
    //             int element;
    //             scanf("%d", &element);
    //             avlnode * node = searchNode(tree, element);
    //             if( node == NULL){
    //                 printf("Element %d not found in tree\n", element);
    //             }
    //             else{
    //                 printf("Element %d found in tree\n", node->data);
    //             }
    //             break;
    //         }
    //         case 4:{
    //             int traversal = 10;
    //             while (traversal != 0) {
    //                 printf("11: Inorder Traversal\n");
    //                 printf("12: Preorder Traversal\n");
    //                 printf("13: Postorder Traversal\n");
    //                 printf(" 0: Quit traversal\n");
    //                 printf("Choice: ");
    //                 scanf("%d", &traversal);
    //                 switch (traversal)
    //                 {
    //                 case 11:{
    //                     printf("\n");
    //                     inorderTraversal(tree);
    //                     printf("\n");
    //                     break;
    //                 }
    //                 case 12:{
    //                     printf("\n");
    //                     preorderTraversal(tree);
    //                     printf("\n");
    //                     break;
    //                 }
    //                 case 13:{
    //                     printf("\n");
    //                     postorderTraversal(tree);
    //                     printf("\n");
    //                     break;
    //                 }
    //                 default:
    //                     break;
    //                 }
    //             }
                
                
    //             break;
    //         }
    //         case 5:{
    //             printf ("Destroying complete tree\n");
    //             destroyTree(&tree);
                 
    //             break;
    //         }
    //         default:
    //             break;

    //     }
       
    // }
    
    

    return 0;
}
