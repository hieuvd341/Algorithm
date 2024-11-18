#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int id;
    vector<Node*> children;
};
typedef struct Node NODE;
unordered_map<int, NODE*> mp;

NODE* makeRoot(int id) {
    NODE* node = new NODE{id};
    mp[id] = node;
    return node;
}

void insert(int parent_id, int child_id) {
    if (mp.find(child_id) != mp.end()) return;

    if (mp.find(parent_id) == mp.end()) {
        makeRoot(parent_id);
    }

    NODE* parentNode = mp[parent_id];
    NODE* childNode = new NODE{child_id};
    parentNode->children.push_back(childNode);
    mp[child_id] = childNode;
}

void inOrder(NODE* node) {
    if (!node) return;
    bool isFirstChild = true;
    for (auto& child : node->children) {
        if (isFirstChild) {
            inOrder(child);
            cout << node->id << " ";
            isFirstChild = false;
        } else {
            inOrder(child);
        }
    }
    if (isFirstChild) {
        cout << node->id << " ";
    }
}

void preOrder(NODE* node) {
    if (!node) return;
    cout << node->id << " ";
    for (auto& child : node->children) {
        preOrder(child);
    }
}

void postOrder(NODE* node) {
    if (!node) return;
    for (auto& child : node->children) {
        postOrder(child);
    }
    cout << node->id << " ";
}

void freeTree(NODE* node) {
    for (auto& child : node->children) {
        freeTree(child);
    }
    delete node;
}

int main() {
    string operation;
    int id, parent_id, child_id;
    NODE* root = nullptr;

    while (cin >> operation) {
        if (operation == "MakeRoot") {
            cin >> id;
            root = makeRoot(id);
        } else if (operation == "Insert") {
            cin >> child_id >> parent_id;
            insert(parent_id, child_id);
        } else if (operation == "PreOrder") {
            preOrder(root);
            cout << endl;
        } else if (operation == "InOrder") {
            inOrder(root);
            cout << endl;
        } else if (operation == "PostOrder") {
            postOrder(root);
            cout << endl;
        } else if (operation == "*") {
            break;
        }
    }

    freeTree(root);
    return 0;
}
