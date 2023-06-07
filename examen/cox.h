#ifndef cox_h
#define cox_h

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createList();
void addtolist(Node *head, int data);
void afisare(Node *head);

#endif