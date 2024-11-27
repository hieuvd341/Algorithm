#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find minimum insertions to form a palindrome
int shortestPalindrome(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    int n = s.size();

    // Dynamic Programming Table for LCS
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Fill DP Table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == rev_s[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Calculate Minimum Insertions
    int longest_palindromic_suffix = dp[n][n];
    return n - longest_palindromic_suffix;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Minimum insertions needed: " << shortestPalindrome(s) << endl;
    return 0;
}
