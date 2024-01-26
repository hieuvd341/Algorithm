#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<Windows.h>
using namespace std;
int maximumInformation(vector<int>security_val, int k) {
    int n = security_val.size();
    vector<int>dp(n+k+1, 0);
    for(int i = 0; i<k; i++) {
        dp[i] = security_val[i];
    }
    for(int i =k; i< n; i++) {
        if(dp[i-k] > 0) {
            dp[i] = dp[i-k] +security_val[i];
        }
        else {
            dp[i] = security_val[i];
        }
    }
    int max = INT_MIN;
    for(int i = n-1; i >= n-k;i--) {
        if(dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }

    int n;
    inputFile >> n;
    vector<int> security_val;
    int tmp;
    for(int i = 0;i <n; i++){
        inputFile >> tmp;
        security_val.push_back(tmp);
    }
    int k;
    inputFile >> k;
    cout <<maximumInformation(security_val, k);
}