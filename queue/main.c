#include <stdio.h>

#include "queue.h"

int main()
{
    Queue a;
    enQueue(&a, 10);
    enQueue(&a, 20);
    enQueue(&a, 30);
    enQueue(&a, 40);
    enQueue(&a, 50);
    priority_enqueue(&a, 100);
    enQueue(&a, 60);

    traverse(a);

    deQueue(&a);
    deQueue(&a);
    deQueue(&a);
    deQueue(&a);
    deQueue(&a);
    deQueue(&a);
    deQueue(&a);
    traverse(a);

    printf("Is empty %d\n", isEmptyQueue(a));

    return 0;
}

