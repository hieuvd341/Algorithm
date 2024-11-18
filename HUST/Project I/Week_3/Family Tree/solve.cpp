#include<iostream>
#include<map>
#include<vector>
#include <istream>
#include<string>
using namespace std;

void descendants(string parent, map<string, vector<string>> mp, int &count){
    int sz = mp[parent].size();
    count +=sz;
    for(int i =0; i <sz ; i++) {
        descendants(mp[parent][i], mp, count);
    }
}

void generation (string parent, map<string, vector<string>> mp, int count, int &res){
    if(count > res) res = count;
    int sz = mp[parent].size();
    for(int i =0; i <sz ; i++) {
        generation(mp[parent][i], mp, count+1, res);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string input;
    map<string, vector<string>> mp;
    while(true){
        getline(cin, input);
        if(input == "***") {
            break;
        }
        int sz = input.size();
        string child = "";
        string parent = "";
        int i =0;
        for(; i < sz; i++){
            if(input[i] == ' ') {
                i++;
                break;
            }
            child += input[i];
        }
        for(; i < sz; i++){
            parent += input[i];
        }
        mp[parent].push_back(child);
    }
    while(true) {
        getline(cin, input);
        if(input == "***") {
            break;
        }
        int sz = input.size();
        string query = "";
        string parent = "";
        int i =0;
        for(; i < sz; i++){
            if(input[i] == ' ') {
                i++;
                break;
            }
            query += input[i];
        }
        for(; i < sz; i++){
            parent += input[i];
        }
        int count =0;
        int res = 0;
        if(query == "descendants"){
            descendants(parent, mp, count);
            cout << count << endl;
        }
        else if(query == "generation"){
            generation(parent, mp, count, res);
            cout << res << endl;
        }
    }
    return 0;
}