#ifndef dijkstra_h
#define dijkstra_h

#define MAX 100
#define INT_MAX 100

#include "graf.h"

typedef struct
{
    int V, E; // nr. varfuri si muchii
    int **a;  // matricea de adiacenta
} Graph;

Graph *alocGraph(int val);
int printSolution(int dist[], int n);
int minDistance(int dist[], int sps[], int V);
void dijkstra(Graph *g, int s);
void dijkstra2(Graph *g, int s);
void printPath(int predecessors[], int dest);
void printGraph(Graph *);
void dijkstralist(GraphL *list, int s);

#endif