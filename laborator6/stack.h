#ifndef stack_h
#define stack_h

#include "trees.h"
typedef struct StackNode
{
    Node *data;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

Stack *createStack();
void push(Stack *s, Node *data);
Node *pop(Stack *s);
int isStackEmpty(Stack *s);
void deleteStack(Stack *s);

#endif