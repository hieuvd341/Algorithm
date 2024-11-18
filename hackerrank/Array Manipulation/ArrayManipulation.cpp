#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<int> arr (n+1, 0);
    for(auto query : queries) {
        arr[query[0] -1] += query[2];
        if (query[1] < n) {
            arr[query[1]] -= query[2];
        }
    }
    long curr_max = 0;
    long save_max = 0;
    for(int i =0; i < n; i++) {
        curr_max += arr[i];
        if(save_max < curr_max) save_max = curr_max;
    }
    cout << save_max << endl;
    return save_max;
    
}

int main() {
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Error!!";
        return 0;
    }
    int n;
    inputFile >> n;
    int a, b, k;
    int s;
    inputFile >> s;
    vector<vector<int>> queries;
    while(s > 0) {
        vector<int> v;
        inputFile >> a;
        inputFile >> b;
        inputFile >> k;
        v.push_back(a);
        v.push_back(b);
        v.push_back(k);
        queries.push_back(v);
        s--;
    }
    // for(auto query : queries) {
    //     cout << query[0]  << " " << query[1] << " "<<query[2] << endl;
    // }
    cout << arrayManipulation(n, queries);
}