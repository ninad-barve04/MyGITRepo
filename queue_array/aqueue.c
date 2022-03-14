#include <stdlib.h>
#include <stdio.h>

#include "aqueue.h"

void init_queue(Queue *q, int size) {
    q->size = size;
    q->array = (int *)malloc(sizeof(int)*(q->size));
    q->front = -1;
    q->rear = -1;
}

void enQueue(int data, Queue *q) {
    if (q->front == -1 && q->rear == -1) {
        q->front++;
        q->rear++;
        q->array[q->rear] = data;
    } else if(q->rear+1 == q->size) {
        printf("Queue full!\n");
        return;
    } else {
        q->rear++;
        q->array[q->rear] = data;
    }
    return;
}

int deQueue(Queue *q) {
    int first;
    if (q->front == -1 || q->rear == -1) {
        return -1;
    }
    first = q->array[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return first;
}

void traverse(Queue q) {
    
    if (q.front == -1) {
        printf("Empty queue\n");
    } else {
        printf("<==| ");
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d==>", q.array[i]);
        }
        printf("NULL\n");
        printf("\n");
    }
    // if (p == NULL) {
    //     printf("List is empty!\n");
    //     return;
    // }
    // printf("<==| ");
    // do {
    //     printf("%d ==> ", p->data);
    //     p = p->next;

    // } while (p != NULL);
    // printf("NULL\n");
    // printf("\n");
    // return;
}

