#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to check if two trees are mirror images of each other
bool isMirror(TreeNode* left, TreeNode* right) {
    if (left == nullptr && right == nullptr) return true;
    if (left == nullptr || right == nullptr) return false;
    return (left->val == right->val) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}

// Function to check if a tree is symmetric
bool isSymmetric(TreeNode* root) {
    return root == nullptr || isMirror(root->left, root->right);
}

// Helper function to create a sample tree for testing
TreeNode* createSampleTree() {
    // Example tree:
    //       1
    //      / \
    //     2   2
    //    / \ / \
    //   3  4 4  3
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2a = new TreeNode(2);
    TreeNode* node2b = new TreeNode(2);
    TreeNode* node3a = new TreeNode(3);
    TreeNode* node3b = new TreeNode(3);
    TreeNode* node4a = new TreeNode(4);
    TreeNode* node4b = new TreeNode(4);

    node1->left = node2a;
    node1->right = node2b;
    node2a->left = node3a;
    node2a->right = node4a;
    node2b->left = node4b;
    node2b->right = node3b;

    return node1;
}

int main() {
    TreeNode* root = createSampleTree();

    if (isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    // Clean up the allocated memory (optional)
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
