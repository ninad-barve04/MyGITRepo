#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "astack.h"

int main(void)
{
    Stack st;
    init_stack(&st, 15);
    for (int i = 0; i < 16; i++) {
        push(&st, i);
    }
    //printf("Top = %d\n", st.top);
    traverse(st);
    int a1 = pop(&st);
    int a2 = pop(&st);
    int a3 = pop(&st);
    printf("%d  %d  %d\n", a1, a2, a3);
    traverse(st);
    return 0;
}

