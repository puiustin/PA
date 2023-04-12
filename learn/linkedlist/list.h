#ifndef LIST_H
#define LIST_H

typedef struct Punct
{
    char *nume_punct;
    double x, y;
} Punct;

typedef struct Node
{
    Punct data;
    struct Node *next;
} Node;

Node *create_list();
void add_element(Node *sentinel, Punct data, int position);
void print_list(Node *sentinel);
void delete_element(Node *sentinel, int position);
void modify_element(Node *sentinel, Punct data, int position);
void delete_list(Node *sentinel);
double calculate_perimeter(Node *sentinel);

#endif // LIST_H
