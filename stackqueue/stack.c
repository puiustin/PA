#include <stdlib.h>
#include "stack.h"

Stack *createStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack *s, char data)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data = data;
    temp->next = s->top;
    s->top = temp;
}

char pop(Stack *s)
{
    if (s->top == NULL)
        return '\0';

    StackNode *temp = s->top;
    char data = temp->data;
    s->top = temp->next;

    free(temp);
    return data;
}

int isStackEmpty(Stack *s)
{
    return s->top == NULL;
}

void freeStack(Stack *s)
{
    StackNode *current, *temp;
    current = s->top;
    while (current != NULL)
    {
        temp = current->next;
        free(current);
        current = temp;
    }

    free(s);
}
