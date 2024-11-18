#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int item)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    return node;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    char command[10];
    int key;

    while (scanf("%s", command) != EOF && command[0] != '#')
    {
        if (scanf("%d", &key) == 1)
        {
            root = insert(root, key);
        }
    }

    preOrder(root);
    printf("\n");
    return 0;
}
