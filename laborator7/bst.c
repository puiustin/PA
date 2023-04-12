#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bst.h"

Node *newNode(const char *word, const char *description)
{
    Node *node = malloc(sizeof(Node));
    node->word = malloc((strlen(word) + 1) * sizeof(char));
    node->description = malloc((strlen(description) + 1) * sizeof(char));
    strcpy(node->word, word);
    strcpy(node->description, description);
    node->left = node->right = NULL;
    return node;
}

Node *insert(Node *root, const char *word, const char *description)
{
    if (root == NULL)
        return newNode(word, description);

    int aux = strcmp(root->word, word);
    if (aux < 0)
        root->left = insert(root->left, word, description);
    else if (aux > 0)
        root->right = insert(root->right, word, description);

    return root;
}

void printBST(Node *root)
{
    if (root != NULL)
    {
        printBST(root->left);
        printf("%s - %s\n", root->word, root->description);
        printBST(root->right);
    }
}

void freeBST(Node *root)
{
    if (root != NULL)
    {
        freeBST(root->left);
        freeBST(root->right);
        free(root->word);
        free(root->description);
        free(root);
    }
}

void searchWord(Node *root, char *word)
{
    if (root == NULL)
    {
        printf("Cuvantul '%s' nu a fost gasit!\n", word);
        return;
    }
    int aux = strcmp(root->word, word);
    if (aux < 0)
        searchWord(root->left, word);
    else if (aux > 0)
        searchWord(root->right, word);
    else if (aux == 0)
    {
        printf("%s - %s\n", root->word, root->description);
    }
}

// void searchSuffix(Node *root, char *suffix)
// {
//     if (root == NULL)
//         return;
//     searchSuffix(root->left, suffix);
//     if (strstr(root->word, suffix) != NULL)
//         printf("%s - %s\n", root->word, root->description);
//     searchSuffix(root->right, suffix);
// }

void searchSuffix(Node *root, char *suffix)
{

    if (root == NULL)
        return;
    searchSuffix(root->left, suffix);

    if (strcmp(root->word + strlen(root->word) - strlen(suffix), suffix) == 0)
        printf("%s - %s\n", root->word, root->description);
    searchSuffix(root->right, suffix);
}
