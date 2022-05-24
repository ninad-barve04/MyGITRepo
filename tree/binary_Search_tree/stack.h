
typedef struct st_node {
    treenode *data;
    struct st_node * next;
} st_node;

typedef st_node * Stack;


void initStack(Stack *stk);
void push(Stack *stk, treenode *datanode);
treenode * pop(Stack *stk);
treenode * peek(Stack stk);
int isEmpty(Stack stk);
void printStack(Stack stk);
