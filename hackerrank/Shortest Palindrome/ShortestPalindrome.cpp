<<<<<<< HEAD
#include<iostream>
#include<map>
#include<fstream>
#include<vector>
using namespace std;

int solve(string s) {
    int size = s.size();
    map<char, int> mp;
    for(int i =0; i < size; i++){
        mp[s[i]] ++;
    }
    int dp[1100];
    dp[0] = 0;
    int max = 0;
    int idx;
    for(int i =1; i < size-1; i++ ) {
        dp[i] += dp[i-1] + mp[i-1]-1;
        mp[i-1] = mp[i-1]/2-1;
        if(dp[i] > max) {
            idx = i;
            max = dp[i];
        }
    }
    cout << idx << endl;
    cout << max << endl;
    return size - max*2;

}
int main() {
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file.";
        return 0;
    }
    string s;
    inputFile >> s;
    cout << solve(s);
=======
#include<iostream>
#include<map>
#include<fstream>
#include<vector>
using namespace std;

int solve(string s) {
    int size = s.size();
    map<char, int> mp;
    for(int i =0; i < size; i++){
        mp[s[i]] ++;
    }
    int dp[1100];
    dp[0] = 0;
    int max = 0;
    int idx;
    for(int i =1; i < size-1; i++ ) {
        dp[i] += dp[i-1] + mp[i-1]-1;
        mp[i-1] = mp[i-1]/2-1;
        if(dp[i] > max) {
            idx = i;
            max = dp[i];
        }
    }
    cout << idx << endl;
    cout << max << endl;
    return size - max*2;

}
int main() {
    ifstream inputFile("input.txt");
    if(!inputFile.is_open()) {
        cerr << "Can not open file.";
        return 0;
    }
    string s;
    inputFile >> s;
    cout << solve(s);
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}