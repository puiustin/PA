#include <stdio.h>
#include <stdlib.h>

#include "trees.h"
// #include "stack.h"

Node *create()
{
    char c;
    int data;
    Node *root = malloc(sizeof(Node));
    printf("Dati cheia pentru nod: ");
    scanf("%d", &data);
    root->data = data;
    printf("Nodul adaugat are subarbore stang? d/n \n");
    scanf("%s", &c);
    if (c == 'd' || c == 'D')
        root->left = create();
    else
        root->left = NULL;
    printf("Nodul adaugat are subarbore drept? (d/n) \n");
    scanf("%s", &c);
    if (c == 'd' || c == 'D')
        root->right = create();
    else
        root->right = NULL;

    return root;
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}