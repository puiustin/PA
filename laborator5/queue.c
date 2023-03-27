#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "queue.h"

Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;
    q->front = q->rear = NULL;
    return q;
}

void enQueue(Queue *q, char *data)
{
    Node *aux = malloc(sizeof(Node));
    aux->data = malloc((strlen(data) + 1) * sizeof(char));
    strcpy(aux->data, data);
    aux->next = NULL;
    if (q->rear == NULL)
        q->rear = aux;
    else
    {
        (q->rear)->next = aux;
        (q->rear) = aux;
    }
    if (q->front == NULL)
        q->front = q->rear;
}

char *deQueue(Queue *q)
{
    if (q->front == NULL)
        return NULL;

    Node *aux = q->front;
    char *data = aux->data;
    q->front = aux->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(aux);
    return data;
}

int isEmpty(Queue *q)
{
    return (q->front == NULL);
}

void deleteQueue(Queue *q)
{
    Node *current, *aux;
    current = q->front;

    while (current != NULL)
    {
        aux = current->next;
        free(current->data);
        free(current);
        current = aux;
    }

    free(q);
}

void printQueue(Queue *q)
{
    Node *current, *aux;
    current = q->front;

    while (current != NULL)
    {
        aux = current->next;
        printf("%s\n", current->data);
        current = aux;
    }
}
