#ifndef list
#define list

typedef struct Punct
{
    char *nume_punct;
    int x, y;
} Punct;

typedef struct Node
{
    Punct data;
    struct Node *next;
} Node;

Node *createlist();
void addonpos(Node *sentinel, Punct data, int pos);
void afisare(Node *sentinel);
void delonpos(Node *sentinel, int pos);
void modifyonpos(Node *sentinel, Punct data, int pos);
void deletelist(Node *sentinel);
double perimetru(Node *sentinel);

#endif