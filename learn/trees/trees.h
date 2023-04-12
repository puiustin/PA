#ifndef trees_h
#define trees_h

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *create();
void inorder(Node *root);
void freeTree(Node *root);
Node *findLCA(Node *root, int a, int b);
#endif