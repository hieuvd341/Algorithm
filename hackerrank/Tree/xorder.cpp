<<<<<<< HEAD
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <fstream>
using namespace std;
using ll = long long;
const int MOD =1e9+7;

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
        return new Node(x);
    }
    if(root->val < x) {
        root->right = insert(root->right, x);
    }
    if(root -> val >= x) {
        root->left = insert(root->left, x);
    }
    return root;
}

void findheight(Node *root, int &height, int& curr) {
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
    cout << height-1;
=======
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <fstream>
using namespace std;
using ll = long long;
const int MOD =1e9+7;

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
        return new Node(x);
    }
    if(root->val < x) {
        root->right = insert(root->right, x);
    }
    if(root -> val >= x) {
        root->left = insert(root->left, x);
    }
    return root;
}

void findheight(Node *root, int &height, int& curr) {
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
    cout << height-1;
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}