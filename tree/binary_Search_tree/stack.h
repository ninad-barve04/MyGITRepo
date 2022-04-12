
typedef struct st_node {
    node *data;
    struct st_node * next;
} st_node;

typedef st_node * Stack;


void initStack(Stack *stk);
void push(Stack *stk, node *datanode);
node * pop(Stack *stk);
node * peek(Stack stk);
int isEmpty(Stack stk);
void printStack(Stack stk);
