#ifndef queue_h
#define queue_h

typedef struct Node
{
    char *data;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front, *rear;
} Queue;

Queue *createQueue();
void enQueue(Queue *q, char *data);
char *deQueue(Queue *q);
int isEmpty(Queue *q);
void deleteQueue(Queue *q);
void printQueue(Queue *q);

#endif