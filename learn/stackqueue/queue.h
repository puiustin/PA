#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node
{
    char *data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue();
void enQueue(Queue *q, char *data);
char *deQueue(Queue *q);
int isEmpty(Queue *q);
void freeQueue(Queue *q);

#endif
