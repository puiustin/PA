#include <stdio.h>

#include "trees.h"

int main(void)
{
    Node *root = create();

    printf("Componentele arborelui in ordine SRD: \n");
    inorder(root);

    int a = 4, b = 5;
    Node *lca = findLCA(root, a, b);
    printf("LCA al cheilor %d si %d este: %d", a, b, lca->data);
    freeTree(root);
    return 0;
}