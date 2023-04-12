#ifndef STACK_H
#define STACK_H

typedef struct StackNode
{
    char data;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

Stack *createStack();
void push(Stack *s, char data);
char pop(Stack *s);
int isStackEmpty(Stack *s);
void freeStack(Stack *s);

#endif
