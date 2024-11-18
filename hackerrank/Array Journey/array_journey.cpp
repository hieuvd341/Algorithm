#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

// brute force solution
int brute_force(vector<int> &arr, int maxSize, int n) {
    vector<int> dp(n, INT_MIN);
    dp[0] = arr[0];
    // cout << "dp0: "<<  dp[0] << endl;
    for(int i = 1;i < n; i ++) {
        for(int j = 1; j <= maxSize; j++) {
            if(i - j >= 0) {
                dp[i] = max(dp[i], dp[i-j] + arr[i]);
            }
        }
        // cout << "dp" << i <<": "<<  dp[i] << endl;
    }
    return dp[n-1];
}

// segment tree solution

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
    // for(int i =0; i < n; i++) {
    //     cout << arr[i] << endl;
    // }
    // cout << maxSize << endl;
    cout << brute_force(arr, maxSize, n);
}