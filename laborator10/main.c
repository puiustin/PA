#include <stdio.h>

#include "dijkstra.h"
#include "graf.h"

int main(void)
{
    int i, j, v, w;
    int graph[6][6] = {{0, 5, 8, 0, 0, 0}, {5, 0, 0, 3, 2, 0}, {8, 0, 0, 10, 0, 0}, {0, 3, 10, 0, 0, 4}, {0, 2, 0, 0, 0, 0}, {0, 0, 0, 4, 0, 0}};

    Graph *g = alocGraph(6);
    for (v = 0; v < g->V; v++)
        for (w = 0; w < g->V; w++)
            g->a[v][w] = graph[v][w];
    printGraph(g);
    dijkstra2(g, 0);

    printf("Lista de adiacenta: \n");
    GraphL *list = createL();

    return 0;
}