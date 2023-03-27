#include <stdlib.h>
#include <string.h>
#include "queue.h"

Queue *createQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue *q, char *data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = strdup(data);
    temp->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

char *deQueue(Queue *q)
{
    if (q->front == NULL)
        return NULL;

    Node *temp = q->front;
    char *data = temp->data;
    q->front = temp->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return data;
}

int isEmpty(Queue *q)
{
    return q->front == NULL;
}

void freeQueue(Queue *q)
{
    Node *current, *temp;
    current = q->front;

    while (current != NULL)
    {
        temp = current->next;
        free(current->data);
        free(current);
        current = temp;
    }

    free(q);
}
