<<<<<<< HEAD
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void input(int &n, int &q, vector<vector<string>> &cache_entries, vector<vector<string>> &queries ) {
    cin >> n >>q;
    string str_temp;
    for(int i =0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> str_temp;
            cache_entries[i].push_back(str_temp);
        }
    }
    for(int i=0; i<q; i++) {
        for(int j=0; j<2; j++) {
            cin >> str_temp;
            queries[i].push_back(str_temp);
        }
    }
    
}

int main() {
    int n, q;
    vector<vector<string>> cache_entries;
    vector<vector<string>> queries;
    input(n,q, cache_entries, queries);
    for(int i =0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cout<<cache_entries[i][j];
        }
    }
=======
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void input(int &n, int &q, vector<vector<string>> &cache_entries, vector<vector<string>> &queries ) {
    cin >> n >>q;
    string str_temp;
    for(int i =0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cin >> str_temp;
            cache_entries[i].push_back(str_temp);
        }
    }
    for(int i=0; i<q; i++) {
        for(int j=0; j<2; j++) {
            cin >> str_temp;
            queries[i].push_back(str_temp);
        }
    }
    
}

int main() {
    int n, q;
    vector<vector<string>> cache_entries;
    vector<vector<string>> queries;
    input(n,q, cache_entries, queries);
    for(int i =0; i<n; i++) {
        for(int j=0; j<3; j++) {
            cout<<cache_entries[i][j];
        }
    }
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}