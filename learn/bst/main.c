#include <stdio.h>

#include "bst.h"

int main(void)
{
    Node *root = NULL;
    root = insert(root, "partie", "Suprafata pe care se practica schiul");
    root = insert(root, "regie", "Institutie publica care asigura servicii de utilitate publica");
    root = insert(root, "carte", "Obiect realizat din foi legate care contin informatii");
    root = insert(root, "muzica", "Arta organizării sunetelor și a tăcerilor în timp");

    printf("BST-ul complet:\n");
    printTree(root);

    printf("\nCaut cuvantul 'regie':\n");
    searchWord(root, "regie");

    printf("\nCaut cuvinte cu sufixul 'ie':\n");
    searchBySuffix(root, "ie");

    freeTree(root);

    return 0;
}