#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// wrong solution by misunderstanding the problem. but the idea is the same
struct Node{
    int val;
    Node *left;
    Node* right;
    Node (int x){
        val = x;
        left = right = NULL;
    }
};

Node* insert(Node* root, int x) {
    if(root == NULL) {
        return new Node(x);
    }
    if(root->val > x){
        root->left = insert(root->left, x);
    }
    if(root->val <  x){
        root->right = insert(root->right, x);
    }
    return root;
}
void leftTopView(Node* root, int &left_width, vector<int>& left, int curr) {
    if (root == nullptr) {
        return;
    }
    if (curr < left_width) {
        left_width = curr;
        left.push_back(root->val);
    }
    if (root->left != nullptr) {
        leftTopView(root->left, left_width, left, curr - 1);
    }
    if (root->right != nullptr) {
        leftTopView(root->right, left_width, left, curr + 1);
    }
}

void rightTopView(Node* root, int &right_width, vector<int> &right, int curr) {
    if (root == nullptr) {
        return;
    }
    if (curr > right_width) {
        right_width = curr;
        right.push_back(root->val);
    }
    if (root->right != nullptr) {
        rightTopView(root->right, right_width, right, curr + 1);
    }
    if (root->left != nullptr) {
        rightTopView(root->left, right_width, right, curr - 1);
    }
}
vector<int> topView(Node*root) {
    int left_width = -1;
    int right_width = 1;
    int curr_left  = -1;
    vector<int> ans;
    
    
    
    vector<int>right;
    vector<int> left;
    leftTopView(root->left, left_width, left, curr_left);
    int curr_right = 1;
    rightTopView(root->right, right_width, right, curr_right);
    int size_left = left.size();
    int size_right = right.size();
    
    for(int i = 0; i < size_left; i++) {
        ans.push_back(left[size_left- 1- i]);
    }
    if(root->left != nullptr) {
        ans.push_back(root->left->val);
    }
    ans.push_back(root-> val);
    if(root->right != nullptr) {
        ans.push_back(root->right->val);
    }
    for(int i = 0; i < size_right; i++) {
        ans.push_back(right[i]);
    }
    
    return ans;
}

int main(){
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
    vector<int> ans;
    ans = topView(root);
    for(int i =0; i < ans.size(); i ++) {
        cout << ans[i] << " ";
    }
}