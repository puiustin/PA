#include <stdio.h>

#include "bst.h"

int main(void)
{
    Node *root = newNode("partie", "partie bblalblalblalba");

    root = insert(root, "regie", "regie balblallbalba");
    root = insert(root, "carte", "carte balblalblalba");
    root = insert(root, "masina", "masina blalblabla");
    root = insert(root, "pancreas", "pancreas blalblablallb");

    printf("BST-ul: \n");
    printBST(root);

    printf("\nCaut cuvantul 'masina':\n");
    searchWord(root, "masina");

    printf("\nCaut cuvantul 'hartie':\n");
    searchWord(root, "hartie");

    printf("\nCuvintele care au ca sufix 'ie' sunt: \n");
    searchSuffix(root, "ie");
    freeBST(root);
}