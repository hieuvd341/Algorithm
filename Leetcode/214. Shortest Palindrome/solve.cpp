#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Function to find the shortest palindrome
string shortestPalindrome(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    
    string combined = s + "#" + rev_s;
    
    int n = combined.size();
    vector<int> lps(n, 0);
    
    // Compute the LPS array (Longest Prefix Suffix array)
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && combined[i] != combined[j]) {
            j = lps[j - 1];
        }
        if (combined[i] == combined[j]) {
            j++;
        }
        lps[i] = j;
    }
    
    // The length of the palindrome suffix
    int pal_length = lps[n - 1];
    
    // Add the necessary characters to the front
    return rev_s.substr(0, s.size() - pal_length) + s;
}

int main() {
    // Example input
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    string result = shortestPalindrome(s);
    cout << "Shortest Palindrome: " << result << endl;

    return 0;
}
