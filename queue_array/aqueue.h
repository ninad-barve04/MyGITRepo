typedef struct Queue{
    int front, rear, size;
    int *array;
}Queue;

void init_queue(Queue *q, int size);
void enQueue(int data, Queue *q);
int deQueue(Queue *q);
void traverse(Queue q);