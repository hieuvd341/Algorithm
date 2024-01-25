#include<iostream>
#include<malloc.h>
#include<map>
#include<vector>
#include<fstream>
#include <string>
using namespace std;

void countSort(vector<vector<string>> arr) {
    map<int, vector<string>> mp;
    int size = arr.size();
    
    for(int i =0; i < size; i++) {
        mp[stoi(arr[i][0])].push_back(arr[i][1]);
    }
    for(auto entry : mp) {
        for(int i = 0; i < entry.second.size(); i++) {
            cout << entry.second[i] << " ";
        }
        cout << endl;
    }
    // vector<string> res;
    // for(auto entry: mp) {
    //     int s = entry.second.size();
    //     int tmp = 0;
    //     // cout << entry.first << endl;
    //     for(int ii =0; ii < s-2; ii++) {
    //         res.push_back("-");
    //     }
    //     if (!entry.second.empty()) {
    //         res.push_back(entry.second.back());
    //     }
    // }
    // for(int i =0; i < res.size(); i++) {
    //     cout << res[i] << " ";
    // }
}

int main() {
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file!";
        return 0;
    }
    int n;
    inputFile >> n;
    vector<vector<string>> arr;
    for(int i =0; i < n; i++) {
        vector<string> v;
        string str_a;
        int b;
        inputFile >> b;
        inputFile >> str_a;
        string str_b = to_string(b);
        v.push_back(str_b);
        v.push_back(str_a);
        arr.push_back(v);
        // arr.push_back(pair(b,a));
    }
    countSort(arr);
}