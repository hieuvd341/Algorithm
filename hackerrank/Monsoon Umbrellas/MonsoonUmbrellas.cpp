#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<Windows.h>
#include<algorithm>
using namespace std;

void solve(int requirement, vector<int> sizes, int n, int sum, map<int, int> &dp, int &res){
    if(sum == requirement) {
        if(dp[sum] < res) {
            res =  dp[sum];
        }
        return;
    }
    if(sum > requirement) {
        return;
    }
    for(int i =0; i < n; i++) {
        int tmp = dp[sum];
        sum += sizes[i];
        dp[sum] = tmp+1;
        solve(requirement, sizes, n, sum, dp, res);
        sum -= sizes[i];
    }
}

int bruteForce(int requirement, vector<int> sizes, int n){
    int res = INT_MAX;
    map<int, int> dp;
    dp[0] = 0;
    int sum = 0;
    solve(requirement, sizes, n, sum, dp, res);
    if(res != INT_MAX) {
        return res;
    }
    return -1;
}

int monsoonUmbrellas(int requirement, vector<int> sizes, int n) {
    vector<int> dp (n+1, INT_MAX);
    dp[0]= 0;
    for(int i =0; i < requirement+1; i++) {
        for(auto j : sizes) {
            if(i >= j) {
                dp[i] = min(dp[i], dp[i-j]+1);
            }

        }
    }
    if(dp[requirement] == INT_MAX) {
        return -1;
    }
    return dp[requirement];

}

int main(){
    ifstream inputFile("input006.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }
    int requirement;
    inputFile >> requirement;
    vector<int>sizes;
    int n;
    inputFile >> n;
    for(int i =0; i < n; i++){
        int a;
        inputFile >> a;
        sizes.push_back(a);
    }
    sort(sizes.begin(), sizes.end());
    cout << monsoonUmbrellas(requirement, sizes, n);
    return 0;
    
}