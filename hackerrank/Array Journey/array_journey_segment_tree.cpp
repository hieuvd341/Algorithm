#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int N = 100005;
vector<int> tree (N, INT_MIN);
int query(int id, int l, int r, int i , int j) {
    if(r < i || l > j) {
        return INT_MIN;
    }
    if(i <=l && j >= r) {
        return tree[id];
    }
    int mid = (l+ r)/2;
    return max(query(id*2, l, mid, i, j), query(id*2+1, mid +1, r, i, j));
}


void update(int id, int l, int r, int pos, int val){
    if(l == r) {
        tree[id] = val;
        return;
    }
    int mid = (l+r)/2;
    if(pos <= mid) {
        update(2*id, l, mid, pos, val);
    }
    else{
        update(2*id +1, mid+1, r, pos, val);
    }
    tree[id] = max(tree[id*2], tree[id*2+1]);
}

int journey(vector<int> arr, int maxSize) {
    int n = arr.size();
    update(1, 0, n-1, 0, arr[0]);
    for(int i =1; i<n; i++) {
        int mx = query(1, 0, n-1, max(i-maxSize, 0), i-1);
        update(1, 0, n-1, i, mx + arr[i]);
    }
    return query(1, 0, n-1, n-1, n-1);
}

int main() {
    ifstream inputFile("input003.txt");
    if(!inputFile.is_open()) {
        cerr<< "error";
        return 0;
    }
    int n;
    vector<int> arr;
    int maxSize;
    inputFile >> n;
    for(int i = 0 ; i < n; i++) {
        int tmp;
        inputFile >> tmp;
        arr.push_back(tmp);
    }
    inputFile >> maxSize;
    cout << journey(arr, maxSize);
}