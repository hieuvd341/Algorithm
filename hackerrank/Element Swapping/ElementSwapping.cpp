#include<iostream>
#include<vector>
#include<fstream>
#include<map>
#include<Windows.h>
using namespace std;
int elementSwapping(vector<int>array, int n) {
    vector<int>dp(n+1, 0);
    dp[0] = 0;
    dp[1] = array[0];
    int swap;
    int no_swap;
    for(int i =2; i<=n; i++){
        swap = dp[i-1] + array[i-1] * i;
        no_swap = dp[i-2] + (i-1) * array[i-1] + i * array[i-2];
        dp[i] = max(swap, no_swap);
    }
    return dp[n];
}
int main(){
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file";
        return 1;
    }
    int n;
    inputFile >> n;
    vector<int> array;
    int a;
    for(int i =0; i < n; i++) {
        inputFile >> a;
        array.push_back(a);
    }
    cout << elementSwapping(array, n);
    
    
}