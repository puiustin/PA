#include <stdio.h>
#include <stdlib.h>

#include "trees.h"
#include "stack.h"

Node *create()
{
    char c;
    int data;
    Node *root = (Node *)malloc(sizeof(Node));
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

void inorder(Node *root)
{
    if (root == NULL)
        return;

    Node *current = root;
    Stack *stack = createStack();

    while (current != NULL || !isStackEmpty(stack))
    {
        if (current != NULL)
        {
            push(stack, current);
            current = current->left;
        }
        else
        {
            current = pop(stack);
            printf("%d", current->data);
            current = current->right;
        }
    }

    deleteStack(stack);
}

void freeTree(Node *root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

Node *findLCA(Node *root, int a, int b)
{
    if (root == NULL)
        return;

    if (root->data == a || root->data == b)
        return root;

    Node *left = findLCA(root->left, a, b);
    Node *right = findLCA(root->right, a, b);

    if (left && right)
        return root;
    else
    {
        if (left)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}