#include <stdio.h>
#include <stdlib.h>

#include "dijkstra.h"

Graph *alocGraph(int val)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (g == NULL)
        return NULL;
    (g->V) = val;
    g->a = (int **)malloc(sizeof(int *) * g->V);
    for (int i = 0; i < g->V; i++)
        g->a[i] = (int *)calloc(g->V, sizeof(int));
    return g;
}

int printSolution(int dist[], int n)
{
    int ok = 1;
    printf("Varf Distanta fata de sursa \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", i, dist[i]);
        ok = 0;
    }
    return ok;
}

int minDistance(int dist[], int sps[], int V)
{
    int v, min = MAX, min_index;
    for (v = 0; v < V; v++)
        if (sps[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

void printGraph(Graph *g)
{
    int i, j;
    for (i = 0; i < g->V; i++)
    {
        for (j = 0; j < g->V; j++)
            printf(" %d ", g->a[i][j]);
        printf("\n");
    }
}
void printPath(int predecessors[], int dest)
{
    if (predecessors[dest] == -1)
    {
        printf("%d ", dest);
        return;
    }
    printPath(predecessors, predecessors[dest]);
    printf("%d ", dest);
}

void dijkstra(Graph *g, int s)
{
    int i, j, u;
    int dist[g->V];
    int sps[g->V];
    for (i = 0; i < g->V; i++)
    {
        dist[i] = INT_MAX;
        sps[i] = 0;
    }

    dist[s] = 0;

    for (j = 0; j < g->V - 1; j++)
    {
        u = minDistance(dist, sps, g->V);
        printf("%d\n", u);
        sps[u] = 1;
        for (i = 0; i < g->V; i++)
        {
            if (sps[i] == 0 && g->a[u][i] != 0 &&
                dist[u] != INT_MAX && dist[u] + g->a[u][i] < dist[i])
                dist[i] = dist[u] + g->a[u][i];
        }
    }
    printSolution(dist, g->V);
}

void dijkstra2(Graph *g, int s)
{
    int i, j, u;
    int dist[g->V];
    int sps[g->V];
    int predecessors[g->V];

    for (i = 0; i < g->V; i++)
    {
        dist[i] = INT_MAX;
        sps[i] = 0;
        predecessors[i] = -1;
    }

    dist[s] = 0;

    for (j = 0; j < g->V - 1; j++)
    {
        u = minDistance(dist, sps, g->V);
        sps[u] = 1;

        for (i = 0; i < g->V; i++)
        {
            if (sps[i] == 0 && g->a[u][i] != 0 &&
                dist[u] != INT_MAX && dist[u] + g->a[u][i] < dist[i])
            {
                dist[i] = dist[u] + g->a[u][i];
                predecessors[i] = u;
            }
        }
    }

    for (i = 0; i < g->V; i++)
    {
        printf("Cost minim de la %d la %d: %d\n", s, i, dist[i]);
        printf("Calea: ");
        printPath(predecessors, i);
        printf("\n");
    }
}

void dijkstralist(GraphL *list, int s)
{
    int i, j, u;
    int dist[list->V];
    int sps[list->V];
    int predecessors[list->V];

    for (int i = 0; i < list->V; i++)
    {
        Node *currentNode = gl->a[i];
        while (currentNode != NULL)
        {
            Node *nextNode = currentNode->next;
            dist[i] = INT_MAX;
            sps[i] = 0;
            predecessors[i] = -1;
            currentNode = nextNode;
        }
    }

    dist[s] = 0;

    for (j = 0; j < list->V - 1; j++)
    {
        u = minDistance(dist, sps, list->V);
        sps[u] = 1;

        for (i = 0; i < list->V; i++)
        {
            if (sps[i] == 0 && list->a[u][i] != 0 &&
                dist[u] != INT_MAX && dist[u] + list->a[u][i] < dist[i])
            {
                dist[i] = dist[u] + list->a[u][i];
                predecessors[i] = u;
            }
        }
    }

    for (i = 0; i < list->V; i++)
    {
        printf("Cost minim de la %d la %d: %d\n", s, i, dist[i]);
        printf("Calea: ");
        printPath(predecessors, i);
        printf("\n");
    }
}