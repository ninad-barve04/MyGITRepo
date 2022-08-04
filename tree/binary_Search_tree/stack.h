/**
 * @file stack.h
 * @author Ninad Barve (ninad.barve04@gmail.com)
 * @brief Stack header file with typedef for modified stack accommodating treenodes
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef STACK_H
#define STACK_H (1)

/**
 * @brief Typedef for node of a stack of linked list with treenode pointers as 
 *        elements 
 */
typedef struct st_node {
    treenode *data;
    struct st_node * next;
} st_node;

/**
 * @brief Typedef for stack 
 */
typedef st_node * Stack;


void initStack(Stack *stk);
void push(Stack *stk, treenode *datanode);
treenode * pop(Stack *stk);
treenode * peek(Stack stk);
int isEmpty(Stack stk);
void printStack(Stack stk);


#endif // STACK_H
