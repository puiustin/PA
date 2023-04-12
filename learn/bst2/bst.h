#ifndef BST_H_
#define BST_H_
struct node
{
    char *word;
    char *description;
    struct node *left, *right;
};
typedef struct node Node;

/* Alte funcţii pentru BST */
Node *newNode(char *word, char *description);
Node *insert(Node *root, char *word, char *description);
void printBST(Node *root);
void freeBST(Node *root);
void searchWord(Node *root, char *word);
void searchSuffix(Node *root, char *suffix);
#endif