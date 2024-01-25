#include<iostream>
#include<vector>
#include<map>
#include <fstream>
using namespace std;
int nonDivisibleSubset(int k, vector<int> s) {
    map<int, int> mp;
    for(int i =0; i < s.size(); i++) {
        mp[s[i] % k]++;
    }
    for(int i =0; i < k; i++) {
        cout << mp[i] << " ";
    }
    cout << endl;
    int count = 0;
    for(int i =1; i <= k/2; i++) {
        if(mp[i] > mp[k-i]) {
            count += mp[i];
            cout << count << " " <<  mp[i] << endl;
        }
        else {
            count += mp[k-i];
            cout << count << " " << mp[k-i] << endl;
        }
    }
    if(mp[0] != 0) {
        count ++;
    }
    if(k%2 ==0) {
        count -= mp[k/2];
        count++;
    } 
    return count;
}

int main() {
    vector<int> s;
    int n;
    int k;
    ifstream inputFile ("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    inputFile >> n >> k;
    int a;
    for(int i = 0; i < n; i++) {
        inputFile >> a;
        s.push_back(a);
    }

    inputFile.close();

    cout << nonDivisibleSubset(k, s);

    return 0;
}