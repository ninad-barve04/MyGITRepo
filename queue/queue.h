typedef struct node {
    int data;
    struct node * next;
}node;

typedef struct Queue {
    node *front;
    node *rear;
}Queue;


void init_queue(Queue *q);
void enQueue(Queue *q, int data);
void priority_enqueue(Queue *q, int data);
int deQueue(Queue *q);
void traverse(Queue q);
