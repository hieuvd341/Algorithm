#include<iostream>
#include<algorithm>
#include<windows.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int x) {
        val=x;
        left=right=NULL;
    }
};

Node* insert(Node*root, int x) {
    if(root == NULL) {
        return;
    }
    if(root->val < x) {
        root->right = insert(root->right, x);
    }
    if(root -> val >= x) {
        root->left = insert(root->left, x);
    }
    return root;
}

Node* findheight(Node *root, int &height, int& curr) {
    if(root == NULL) {
        height = max(height, curr);
        return;
    }
    curr++;
    findheight(root->left, height, curr);
    findheight(root->right, height, curr);
    curr--;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Node *root=NULL;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;cin>>x;
        root=insert(root,x);
    }
    int height = 0, curr = 0;
    findheight(root, height, curr);
    cout << height;
}