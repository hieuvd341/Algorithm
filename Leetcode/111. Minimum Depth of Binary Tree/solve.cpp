#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the minimum depth of a binary tree
int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

TreeNode* createSampleTree() {
    // Example tree:
    //       3
    //      / \
    //     9   20
    //        /  \
    //       15   7
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20);
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);

    node3->left = node9;
    node3->right = node20;
    node20->left = node15;
    node20->right = node7;

    return node3; // Return the root node
}

int main() {
    TreeNode* root = createSampleTree();
    cout << "Minimum depth of the tree: " << minDepth(root) << endl;

    // Clean up allocated memory
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
