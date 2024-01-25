#include<iostream>
#include<malloc.h>
#include<map>
#include<vector>
#include<fstream>
#include <string>
using namespace std;

void countSort(vector<vector<string>> arr) {
    vector<vector<string>> my_arr;
    int n = arr.size();
    for(int i =0; i < n; i++) {
        vector<string> v;
        string str_a = arr[i][1];
        string str_b = arr[i][0];
        v.push_back(str_b);
        if(i < n/2) {
            v.push_back("-");
        }
        else {
            v.push_back(str_a);
        }
        my_arr.push_back(v);
        // arr.push_back(pair(b,a));
    }
    map<int, vector<string>> mp;
    int size = my_arr.size();
    
    for(int i =0; i < size; i++) {
        mp[stoi(arr[i][0])].push_back(my_arr[i][1]);
    }
    for(auto entry : mp) {
        for(int i = 0; i < entry.second.size(); i++) {
            cout << entry.second[i] << " ";
        }
    }
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