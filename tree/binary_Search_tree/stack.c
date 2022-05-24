#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "stack.h"


void initStack(Stack *stk) {
    *stk = NULL;
    return;
}

void push(Stack *stk, treenode *datanode) {
    st_node *stacknode = (st_node *)malloc(sizeof(st_node));
    

    stacknode->data = datanode;
    stacknode->next = NULL;

    st_node *start = *stk;
    if (start == NULL) {
        *stk = stacknode;
    } else {
        stacknode->next = start;
        *stk = stacknode;
    }
}

treenode * pop(Stack *stk) {
    if (*stk == NULL) {
        return NULL;
    }

    st_node *popnode = *stk;
   
    *stk = popnode->next;
    treenode *popdata = popnode->data;
    
    free(popnode);
    popnode=NULL;

    return popdata;
}

treenode * peek(Stack stk) {
    if (stk == NULL) {
        return NULL;
    }
    st_node *pop_node = stk;
    return pop_node->data;
}


int isEmpty(Stack stk) {
    
    if (stk == NULL) {
        return 1;
    }

    return 0;
}


void printStack(Stack stk) {
    st_node *start_node = stk;

    while(start_node != NULL){
        printf("__%d\n", start_node->data->data);
        start_node = start_node->next;
    }
    return;
}
