typedef struct Node{
    float val;
    struct Node * next;
}Node;

typedef struct stack{
    Node * top;
}stack;

void push(stack *, float);

bool pop(stack *, float *);

Node * cons(float, Node *);

void removeNode(stack *);

void freeStack(stack * );
