#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *createStack()
{
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack *s, Node *data)
{
    StackNode *aux = malloc(sizeof(StackNode));
    aux->data = data;
    aux->next = s->top;
    s->top = aux;
}

Node *pop(Stack *s)
{
    if (s->top == NULL)
        return NULL;

    StackNode *aux = s->top;
    Node *data = aux->data;
    s->top = aux->next;

    free(aux);
    return data;
}

int isStackEmpty(Stack *s)
{
    return (s->top == NULL);
}

void deleteStack(Stack *s)
{
    StackNode *current, *aux;
    current = s->top;
    while (current != NULL)
    {
        aux = current->next;
        free(current);
        current = aux;
    }

    free(s);
}
