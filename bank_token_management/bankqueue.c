#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "bankqueue.h"


void init_queue(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}


void enQueue(Queue *q, int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (q->front == NULL || q->rear == NULL) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        node *last = q->rear;
        last->next = newnode;
        q->rear = newnode;
    }
}


void priority_enqueue(Queue *q, int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (q->front == NULL || q->rear == NULL) {
        q->front = newnode;
        q->rear = newnode;
    } else {
        newnode->next = q->front;
        q->front = newnode;
    }

}


int deQueue(Queue *q) {
    if (q->front == NULL || q->rear == NULL) {
        return INT_MIN;
    }
    node *head = q->front;
    int dat = head->data;
    if(head == q->rear) {
        q->front = NULL;
        q->rear = NULL;
    } else {
        q->front = head->next;
        
        free(head);
    }

   return dat;
    
}


void traverse(Queue q) {
    node *p = q.front;
    if (p == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("<==| ");
    do {
        printf("%d ==> ", p->data);
        p = p->next;

    } while (p != NULL);
    printf("NULL\n");
    printf("\n");
    return;
}
