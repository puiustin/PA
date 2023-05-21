#ifndef graf_H
#define graf_H

typedef struct
{
    int **a;
    int V;
    int E;
} GraphM;

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct
{
    Node **a;
    int V;
    int E;
} GraphL;

GraphM *createM();
GraphL *createL();
void printGraphM(GraphM *g);
void printGraphL(GraphL *g);
GraphL *matrixToList(GraphM *gm);
GraphM *listToMatrix(GraphL *gl);
void freeGraphM(GraphM *gm);
void freeGraphL(GraphL *gl);
int existaMuchieM(GraphM *gm, int x, int y);
int existaMuchieL(GraphL *gl, int x, int y);
void afisareIncidente(GraphM *gm, int x);
void royWarshall(GraphM *gm);

#endif