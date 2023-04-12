#ifndef BST_H_
#define BST_H_

struct node
{
    char *word;
    char *description;
    struct node *left, *right;
};
typedef struct node Node;

Node *newNode(char *word, char *description);
Node *insert(Node *root, char *word, char *description);
void printTree(Node *root);
void freeTree(Node *root);
void searchWord(Node *root, char *word);
void searchBySuffix(Node *root, char *suffix);

#endif