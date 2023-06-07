#include <stdio.h>
#include <stdlib.h>

#include "cox.h"

Node *createList()
{
    Node *list = malloc(sizeof(Node));
    list->next = NULL;
    return list;
}

void addtolist(Node *head, int data)
{
    Node *newnode = malloc(sizeof(Node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void afisare(Node *head)
{
    Node *current = malloc(sizeof(Node));
    current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        current = current->next;
    }
}