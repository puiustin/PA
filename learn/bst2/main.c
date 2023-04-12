#include <stdio.h>

#include "bst.h"

int main(void)
{
    Node *root = NULL;
    root = insert(root, "partie", "partie balblalla");
    root = insert(root, "regie", "regie blallblal");
    root = insert(root, "carte", "carte blalalbla");
    root = insert(root, "muzica", "muzica reprezinta sunete balablala");

    printf("BST-ul:\n");
    printBST(root);

    printf("\nCaut cuvantul 'regie':\n");
    searchWord(root, "regie");

    printf("\nCaut cuvinte cu sufixul 'ie':\n");
    searchSuffix(root, "ie");

    freeTree(root);

    return 0;
}
