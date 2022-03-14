#include <stdlib.h>
#include <stdio.h>

#include "aqueue.h"

int main()
{
    Queue queue;
    init_queue(&queue, 10);
    for (int i = 0; i < 10; i++) {
        enQueue(i, &queue);
    }
    
    traverse(queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    deQueue(&queue);
    printf("front: %d\trear: %d\n", queue.front, queue.rear);
    traverse(queue);
    return 0;
}

