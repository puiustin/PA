#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"

char *backwards(char *aux)
{
    int len = strlen(aux);
    char *backw = malloc(len + 1);
    Stack *s = createStack();

    for (int i = 0; i < len; i++)
    {
        push(s, aux[i]);
    }
    int i = 0;
    while (isStackEmpty(s) == 0)
    {
        backw[i] = pop(s);
        i++;
    }

    backw[len] = '\0';
    deleteStack(s);
    return backw;
}

int main(void)
{
    Queue *q = createQueue();
    char aux[128];
    printf("Introduceti cuvintele: \n");

    while (1)
    {
        scanf("%s", aux);
        if (strcmp(aux, "stop") == 0)
            break;

        char *backw;

        backw = backwards(aux);
        enQueue(q, backw);
        free(backw);
    }

    printf("Cuvintele inversate sunt:\n");
    printQueue(q);
}