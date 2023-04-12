#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "queue.h"
#include "stack.h"

#define MAX_WORD_LENGTH 256

char *backwards(char *original)
{
    int length = strlen(original);
    char *reversed = malloc(length + 1);
    Stack *s = createStack();

    for (int i = 0; i < length; i++)
    {
        push(s, original[i]);
    }

    for (int i = 0; !isStackEmpty(s); i++)
    {
        reversed[i] = pop(s);
    }

    reversed[length] = '\0';
    freeStack(s);
    return reversed;
}

int main()
{
    Queue *q = createQueue();
    char word[MAX_WORD_LENGTH];

    printf("Introduceti cuvinte urmate de tasta Enter. Pentru a opri, scrieti 'stop'.\n");

    while (1)
    {
        scanf("%s", word);

        if (strcmp(word, "stop") == 0)
        {
            break;
        }

        char *reversed = backwards(word);
        enQueue(q, reversed);
        free(reversed);
    }

    printf("\nCuvintele inversate:\n");
    while (!isEmpty(q))
    {
        char *word = deQueue(q);
        printf("%s\n", word);
        free(word);
    }

    freeQueue(q);
    return 0;
}
