#include <iostream>
#include <map>
#include <queue>
#include <stdlib.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode *createNode(int value)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}
bool isEvenOddTree(TreeNode *root)
{
    if (!root)
        return false;

    queue<TreeNode *> q;
    q.push(root);
    int level = 0;

    while (!q.empty())
    {
        int size = q.size();
        int prev_value = (level % 2 == 0) ? INT_MIN : INT_MAX;

        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = q.front();
            q.pop();

            if (level % 2 == node->val % 2)
                return false;

            if ((level % 2 == 0 && (node->val <= prev_value)) || (level % 2 == 1 && (node->val >= prev_value)))
            {
                return false;
            }

            prev_value = node->val; 
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        level++;
    }

    return true;
}
int main()
{
    TreeNode *root;
    root = createNode(5);
    TreeNode *node1 = createNode(10);
    TreeNode *node2 = createNode(2);
    TreeNode *node3 = createNode(3);
    TreeNode *node4 = createNode(5);
    TreeNode *node5 = createNode(7);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    cout << isEvenOddTree(root);
}