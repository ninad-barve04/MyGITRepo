/**
 * @file stack.c
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief Stack functions slightly modified for tree nodes
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "stack.h"

/**
 * @brief Initialize the stack
 * 
 * @param stk Stack pointer
 */
void initStack(Stack *stk) {
    *stk = NULL;
    return;
}


/**
 * @brief Push node to top of stack
 * 
 * @param stk Stack pointer
 * @param datanode Node pointer to be pushed
 */
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


/**
 * @brief Pop node from top of stack 
 * 
 * @param stk Stack pointer
 * @return treenode* Node pointer to the top removed
 */
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


/**
 * @brief Only get the top node of stack without removing it
 * 
 * @param stk Stack pointer
 * @return treenode* Node pointer to the top of stack
 */
treenode * peek(Stack stk) {
    if (stk == NULL) {
        return NULL;
    }
    st_node *pop_node = stk;
    return pop_node->data;
}


/**
 * @brief Check if the stack is empty
 * 
 * @param stk Stack pointer
 * @return int Return 1 if empty, else return 0
 */
int isEmpty(Stack stk) {
    
    if (stk == NULL) {
        return 1;
    }

    return 0;
}


/**
 * @brief Print contents of stack from top to bottom
 * 
 * @param stk Stack pointer
 */
void printStack(Stack stk) {
    st_node *start_node = stk;

    while(start_node != NULL){
        printf("__%d\n", start_node->data->data);
        start_node = start_node->next;
    }
    return;
}
