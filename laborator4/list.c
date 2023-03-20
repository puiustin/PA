#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "list.h"

Node *createlist()
{
    Node *sentinel = malloc(sizeof(Node));
    sentinel->next = sentinel;
    return sentinel;
}

void addonpos(Node *sentinel, Punct data, int pos)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    Node *current = sentinel;
    int i;

    for (i = 0; i < pos && current->next != sentinel; i++)
    {
        current = current->next;
    }

    if (i == pos)
    {
        new_node->next = current->next;
        current->next = new_node;
    }
    else
        printf("Pozitia nu este valida.\n");
}

void afisare(Node *sentinel)
{
    Node *current = sentinel->next;
    while (current != sentinel)
    {
        printf("%s: (%f, %f)\n", current->data.nume_punct, (float)current->data.x, (float)current->data.y);
        current = current->next;
    }
}

void delonpos(Node *sentinel, int pos)
{
    Node *current = sentinel;
    int i;

    for (i = 0; i < pos && current->next != sentinel; i++)
    {
        current = current->next;
    }

    if (i == pos && current->next != sentinel)
    {
        Node *delete = current->next;
        current->next = delete->next;
        free(delete);
    }
    else
        printf("Pozitia nu este valida.\n");
}

void modifyonpos(Node *sentinel, Punct data, int pos)
{
    Node *current = sentinel;
    int i;

    for (i = 0; i < pos && current->next != sentinel; i++)
    {
        current = current->next;
    }

    if (i == pos && current->next != sentinel)
    {
        current->data = data;
    }
    else
        printf("Pozitia nu este valida.\n");
}

void deletelist(Node *sentinel)
{
    Node *current = sentinel->next;

    while (current != sentinel)
    {
        Node *delete = current;
        current = current->next;
        free(delete);
    }
}

double perimetru(Node *sentinel)
{
    Node *current = sentinel->next;
    double perimetru = 0;

    while (current->next != sentinel)
    {
        perimetru = perimetru + sqrt((current->data.x - current->next->data.x) * (current->data.x - current->next->data.x) + (current->data.y - current->next->data.y) * (current->data.y - current->next->data.y));
        current = current->next;
    }
    return perimetru;
}
