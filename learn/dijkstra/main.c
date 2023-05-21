#include <stdio.h>

#include "dijkstra.h"

int main(void)
{
    int i, j, v, w;
    int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, {4, 0, 8, 0, 0, 0, 0, 11, 0}, {0, 8, 0, 7, 0, 4, 0, 0, 2}, {0, 0, 7, 0, 9, 14, 0, 0, 0}, {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0}, {0, 0, 0, 0, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7}, {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    Graph *g = alocGraph(9);
    for (v = 0; v < g->V; v++)
        for (w = 0; w < g->V; w++)
            g->a[v][w] = graph[v][w];
    // printGraph(g);
    dijkstra2(g, 0);
    return 0;
}