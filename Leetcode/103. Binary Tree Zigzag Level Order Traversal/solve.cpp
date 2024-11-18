#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to create the sample tree
TreeNode *createSampleTree()
{
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node9 = new TreeNode(9);
    TreeNode *node20 = new TreeNode(20);
    TreeNode *node15 = new TreeNode(15);
    TreeNode *node7 = new TreeNode(7);

    node3->left = node9;
    node3->right = node20;
    node20->left = node15;
    node20->right = node7;

    return node3; // Return the root node
}
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if(root == nullptr)
    {
        return {};
    }
    vector<vector<int>> result;
    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for(int i = 0; i < size; i++)
        {
            TreeNode* node = q.front();
            q.pop();
            int index = leftToRight ? i : size - 1 - i;
            level[index] = node->val;
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
        leftToRight = !leftToRight;
        result.push_back(level);
    }
    return result;
}
int main()
{
    TreeNode *root = createSampleTree();

    // Now you can call your zigzagLevelOrder function on this root
    // Example: vector<vector<int>> result = zigzagLevelOrder(root);
    vector<vector<int>> result = zigzagLevelOrder(root);
    for(auto v : result)
    {
        for(auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    // Clean up allocated memory after use
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
