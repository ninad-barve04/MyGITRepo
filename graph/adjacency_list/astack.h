#ifndef STACK_H
#define STACK_H (1)

typedef struct Stack {
    int top;
    int size;
    int *array;
}Stack;

void init_stack(Stack *stk, int stk_size);
void push(Stack *stk, int data);
int peek(Stack *stk);
int pop(Stack *stk);
int isFull(Stack *s);
int isEmpty(Stack *s);
void traverseS(Stack stk);


#endif /* ifndef STACK_H */

