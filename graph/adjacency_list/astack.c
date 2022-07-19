#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "astack.h"


void init_stack(Stack *stk, int stk_size) {
    stk->top = -1;
    stk->size = stk_size;
    stk->array = (int *)malloc(sizeof(int) * stk_size);
}


void push(Stack *stk, int data) {
    if (!isFull(stk)) {
        stk->top++;
        stk->array[stk->top] = data;
    } else {
        printf("Stack full!\n");
    }
}


int peek(Stack *stk) {
    if (!isEmpty(stk)) {
        return stk->array[0];
    } else {
        return -1;
    }
}


int pop(Stack *stk) {
    int num;
    if (!isEmpty(stk)) {
        num = stk->array[stk->top];
        stk->top--;
    } else {
        printf("Stack empty!\n");
        num = INT_MIN;
    }
    return num;
}


int isFull(Stack *s) {
    if (s->top==s->size-1)
        return 1;
    else 
        return 0;
}

int isEmpty(Stack *s) {
    if (s->top==-1)
        return 1;
    else
        return 0;
}


void traverseS(Stack stk) {
    if (isEmpty(&stk)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack==> ");
        for (int i = 0; i <= stk.top; i++) {
            printf("%d  ", stk.array[i]);
        }
        printf("<==top\n");
    }
}
