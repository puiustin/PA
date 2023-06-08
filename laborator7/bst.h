#ifndef BST_H_
#define BST_H_
struct node
{
    char *word;
    char *description;
    struct node *left, *right;
};
typedef struct node Node;

struct TrieNode
{
    char data;
    int final_string;
    struct TrieNode *next[26];
};
typedef struct TrieNode TrieNode;

/* Alte funcţii pentru BST */
Node *newNode(const char *word, const char *description);
Node *insert(Node *root, const char *word, const char *description);
void printBST(Node *root);
void freeBST(Node *root);
void searchWord(Node *root, char *word);
void searchSuffix(Node *root, char *suffix);

#endif