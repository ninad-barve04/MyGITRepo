typedef struct Stack {
    int top;
    int size;
    int *array;
}Stack;

void init_stack(Stack *stk, int stk_size);
void push(Stack *stk, int data);
int pop(Stack *stk);
int isFull(Stack *s);
int isEmpty(Stack *s);
void traverse(Stack stk);
