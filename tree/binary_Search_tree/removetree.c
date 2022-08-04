/*
treenode* removeNode(treenode *tree, int misno) {
    if (tree == NULL)
        return NULL;

    if( tree->MIS > misno){
        //printf("Less\n");
        tree->left = removeNode(tree->left, misno);
    }
    else if ( tree->MIS < misno){
        //printf("More\n");
        tree->right = removeNode(tree->right, misno);
    }
    else if (tree->MIS == misno) {  
        // misno == tree->MIS , so this node is to be deleted

        if(tree->left == NULL && tree->right != NULL) 
        {
            treenode *temp = tree->right;
            free (tree);
            tree = NULL;
            return temp;
        }
        else if(tree->left != NULL && tree->right == NULL)
        {
            treenode *temp = tree->left;
            free(tree);
            tree = NULL;
            return temp;
        } else if (tree->left != NULL && tree->right != NULL) {
            treenode *p = inorderSuccessor(tree);
            printf("%d\n", tree->MIS);
            printf("%d\n", p->MIS);
            
            p->left = tree->left;
            p->right = tree->right;
            p->parent = tree->parent;
            
            tree->parent->left = p;
           
            if (p->right == p) {
                p->right = NULL;
            }
            printf("%d\n",tree->parent->parent->MIS);
            free(tree);
            tree = NULL;
            return p;
        } else {
            // leaf node with no left/right child
            free(tree);
            tree = NULL;
            return NULL;
        }
    }
}
*/



//   int a[] = {100, 200, 50, 30, 35, 40, 45, 10, 175, 150, 300};
//     int a[] = {100, 50, 200, 30, 175, 300, 10, 40, 150, 190, 45};
//     char *name[] = {"Nin", "man", "mil", "bat", "cat", "boy", "horse", "fish", "team", "jeff who", "elon"};
    
     
//     for (int i = 0; i < 11; i++) {
//         insertNode(&tree1, a[i], name[i]);
//     }
    

//     postorder(tree1);

//    // displayLevel(tree1, 2);   

//     removeNode(&tree1,300);

//     printf("after removal\n");

//     //displayLevel(tree1, 2);

   
//     // printf("\n");

//    postorder(tree1);
