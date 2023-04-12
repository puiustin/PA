#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

Node *newNode(char *word, char *description)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->word = strdup(word);
    node->description = strdup(description);
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *root, char *word, char *description)
{
    if (root == NULL)
    {
        return newNode(word, description);
    }

    int cmp = strcmp(word, root->word);
    if (cmp < 0)
    {
        root->left = insert(root->left, word, description);
    }
    else if (cmp > 0)
    {
        root->right = insert(root->right, word, description);
    }

    return root;
}

void printTree(Node *root)
{
    if (root != NULL)
    {
        printTree(root->left);
        printf("%s: %s\n", root->word, root->description);
        printTree(root->right);
    }
}

void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root->description);
        free(root);
    }
}

void searchWord(Node *root, char *word)
{
    if (root == NULL)
    {
        printf("Cuvantul nu a fost gasit.\n");
        return;
    }

    int cmp = strcmp(word, root->word);
    if (cmp < 0)
    {
        searchWord(root->left, word);
    }
    else if (cmp > 0)
    {
        searchWord(root->right, word);
    }
    else
    {
        printf("Cuvant: %s\nDescriere: %s\n", root->word, root->description);
    }
}

void searchBySuffix(Node *root, char *suffix)
{
    if (root == NULL)
    {
        return;
    }

    searchBySuffix(root->left, suffix);
    if (strstr(root->word, suffix) != NULL)
    {
        printf("Cuvant: %s\nDescriere: %s\n", root->word, root->description);
    }
    searchBySuffix(root->right, suffix);
}
