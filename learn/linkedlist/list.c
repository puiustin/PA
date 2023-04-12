#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "list.h"

Node *create_list()
{
    Node *sentinel = (Node *)malloc(sizeof(Node));
    sentinel->next = sentinel;
    return sentinel;
}

void add_element(Node *sentinel, Punct data, int position)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    Node *current = sentinel;
    int i;

    for (i = 0; i < position && current->next != sentinel; i++)
    {
        current = current->next;
    }

    if (i == position)
    {
        new_node->next = current->next;
        current->next = new_node;
    }
    else
    {
        free(new_node);
        printf("Pozitia nu este valida!\n");
    }
}

void print_list(Node *sentinel)
{
    Node *current = sentinel->next;

    while (current != sentinel)
    {
        printf("%s: (%lf, %lf)\n", current->data.nume_punct, current->data.x, current->data.y);
        current = current->next;
    }
}

void delete_element(Node *sentinel, int position)
{
    Node *current = sentinel;
    int i;

    for (i = 0; i < position && current->next != sentinel; i++)
    {
        current = current->next;
    }

    if (i == position && current->next != sentinel)
    {
        Node *to_delete = current->next;
        current->next = to_delete->next;
        free(to_delete);
    }
    else
    {
        printf("Pozitia nu este valida!\n");
    }
}

void modify_element(Node *sentinel, Punct data, int position)
{
    Node *current = sentinel->next;
    int i;

    for (i = 0; i < position && current != sentinel; i++)
    {
        current = current->next;
    }

    if (i == position && current != sentinel)
    {
        current->data = data;
    }
    else
    {
        printf("Pozitia nu este valida!\n");
    }
}

void delete_list(Node *sentinel)
{
    Node *current = sentinel->next;

    while (current != sentinel)
    {
        Node *to_delete = current;
        current = current->next;
        free(to_delete);
    }

    free(sentinel);
}

double calculate_perimeter(Node *sentinel)
{
    double perimeter = 0;
    Node *current = sentinel->next;

    if (current != sentinel)
    {
        Node *first = current;
        Node *previous = current;

        current = current->next;

        while (current != sentinel)
        {
            double distance = sqrt

    // coxdawdawd
