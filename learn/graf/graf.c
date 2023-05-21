#include <stdio.h>
#include <stdlib.h>

#include "graf.h"

GraphM *createM()
{                       // functia aloca spatiu pentru un graf si il initializeaza cu valori
    int i, j, orientat; // Tema: Modificati functia astfel incat sa citeasca date dintr-un fisier
    GraphM *g = (GraphM *)malloc(sizeof(GraphM));
    if (g == NULL)
    {
        printf(" no memory for this graph");
        return NULL;
    }
    printf("Cate varfuri are ?\n");
    scanf(" %d", &(g->V));
    g->a = (int **)malloc(g->V * sizeof(int *));
    for (i = 0; i < g->V; i++)
        g->a[i] = (int *)calloc(g->V, sizeof(int)); // o initializez cu 0
    if (g->a == NULL)
    {
        printf(" no memory for this matrix");
        return NULL;
    }
    g->E = 0;
    printf("E orientat? 0 - da, altfel - nu este\n");
    scanf(" %d", &orientat);
    if (orientat != 0)
    { // daca nu e orientat => matricea a este simetrica
        for (i = 0; i < g->V; i++)
            for (j = 0; j < i; j++)
            {
                printf("Exista arc de la %d la %d?(0-nu/1-da)\n", i, j);
                scanf("%d", &g->a[i][j]);
                g->a[j][i] = g->a[i][j];
                if (g->a[i][j] != 0)
                    g->E += 2;
            }
    }
    else
    { // este orientat
        for (i = 0; i < g->V; i++)
            for (j = 0; j < g->V; j++)
            {
                printf("Exista arc de la %d la %d?\n", i, j);
                scanf("%d", &g->a[i][j]);
                //  if(g->a[i][j]!=0) g->E++;
            }
    }
    return g;
}

GraphL *createL()
{ // creare graf folosind liste de adiacenta
    int i, j, next, val;
    GraphL *g = (GraphL *)malloc(sizeof(GraphL));
    if (g == NULL)
    {
        printf(" no memory for this graph\n");
        return NULL;
    }
    printf("Cate varfuri are ?\n");
    scanf(" %d", &(g->V));
    g->a = (Node **)malloc(g->V * sizeof(Node *));
    for (i = 0; i < g->V; i++)
    {
        printf("Dati nr varfului stocat ca si capat de lista pe pozitia %d \n", i);
        scanf("%d", &val);
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->vertex = val;
        newnode->next = NULL;
        g->a[i] = newnode;
    }
    g->E = 0;
    for (i = 0; i < g->V; i++)
    {
        printf("dati varfurile care urmeaza dupa %d \n", g->a[i]->vertex);
        next = 1;
        Node *p = g->a[i];
        while (next == 1)
        {
            printf("exista varf urmator? da=1, nu- altceva\n");
            scanf(" %d", &next);
            if (next == 1)
            {
                printf("care e varful urmator ?\n");
                scanf("%d", &val);
                Node *newnode = (Node *)malloc(sizeof(Node));
                newnode->vertex = val;
                newnode->next = NULL;
                p->next = newnode;
                p = p->next;
                g->E++;
            }
        }
    }
    return g;
}

void printGraphM(GraphM *g)
{
    int i, j;
    for (i = 0; i < g->V; i++)
    {
        for (j = 0; j < g->V; j++)
            printf(" %d ", g->a[i][j]);
        printf("\n");
    }
}

void printGraphL(GraphL *g)
{
    int i, j;
    for (i = 0; i < g->V; i++)
    {
        while (g->a[i] != NULL)
        {
            printf("%d ", g->a[i]->vertex);
            g->a[i] = g->a[i]->next;
        }
        printf("\n");
    }
}

GraphL *matriceToList(GraphM *gm)
{
    int i, j;
    GraphL *gl = (GraphL *)malloc(sizeof(GraphL));
    gl->V = gm->V;
    gl->E = gm->E;
    gl->a = (Node **)malloc(gl->V * sizeof(Node *));

    for (i = 0; i < gl->V; i++)
    {
        gl->a[i] = NULL;
        for (j = 0; j < gm->V; j++)
        {
            if (gm->a[i][j] != 0)
            {
                Node *newNode = (Node *)malloc(sizeof(Node));
                newNode->vertex = j;
                newNode->next = gl->a[i];
                gl->a[i] = newNode;
            }
        }
    }
    return gl;
}

GraphM *listToMatrice(GraphL *gl)
{
    int i;
    GraphM *gm = (GraphM *)malloc(sizeof(GraphM));
    gm->V = gl->V;
    gm->E = gl->E;
    gm->a = (int **)malloc(gm->V * sizeof(int *));

    for (i = 0; i < gm->V; i++)
    {
        gm->a[i] = (int *)calloc(gm->V, sizeof(int));
        Node *currentNode = gl->a[i];
        while (currentNode != NULL)
        {
            gm->a[i][currentNode->vertex] = 1;
            currentNode = currentNode->next;
        }
    }
    return gm;
}

void freeGraphM(GraphM *gm)
{
    for (int i = 0; i < gm->V; i++)
    {
        free(gm->a[i]);
    }
    free(gm->a);
    free(gm);
}

void freeGraphL(GraphL *gl)
{
    for (int i = 0; i < gl->V; i++)
    {
        Node *currentNode = gl->a[i];
        while (currentNode != NULL)
        {
            Node *nextNode = currentNode->next;
            free(currentNode);
            currentNode = nextNode;
        }
    }
    free(gl->a);
    free(gl);
}

int existaMuchieM(GraphM *gm, int x, int y)
{
    return gm->a[x][y];
}

int existaMuchieL(GraphL *gl, int x, int y)
{
}

void afisaremuchii(GraphM *gm, int x)
{
    printf("Muchii incidente cu %d: ", x);
    for (int i = 0; i < gm->V; i++)
    {
        if (gm->a[x][i] != 0)
        {
            printf("(%d, %d) ", x, i);
        }
    }
    printf("\n");
}

void royWarshall(GraphM *gm)
{
    int i, j, k;
    int V = gm->V;
    int **matriceDrumuri = (int **)malloc(V * sizeof(int *));

    for (i = 0; i < V; i++)
    {
        matriceDrumuri[i] = (int *)calloc(V, sizeof(int));
        for (j = 0; j < V; j++)
        {
            matriceDrumuri[i][j] = gm->a[i][j] || (i == j);
        }
    }

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                matriceDrumuri[i][j] = matriceDrumuri[i][j] || (matriceDrumuri[i][k] && matriceDrumuri[k][j]);
            }
        }
    }

    printf("Matricea drumurilor:\n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            printf("%d ", matriceDrumuri[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < V; i++)
    {
        free(matriceDrumuri[i]);
    }
    free(matriceDrumuri);
}
