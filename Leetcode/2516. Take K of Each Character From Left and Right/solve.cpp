#include <iostream>
#include <string>
#include <algorithm> // For std::min
using namespace std;

int takeCharacters(string s, int k) {
    int size = s.size();
    int total_a = 0, total_b = 0, total_c = 0;

    // Count all occurrences of 'a', 'b', and 'c'
    for (char c : s) {
        if (c == 'a') total_a++;
        else if (c == 'b') total_b++;
        else if (c == 'c') total_c++;
    }

    // If it's impossible to collect k of each character
    if (total_a < k || total_b < k || total_c < k) {
        return -1;
    }

    // Sliding window: Find the maximum valid substring to remove
    int count_a = 0, count_b = 0, count_c = 0;
    int left = 0, max_remove = 0;

    for (int right = 0; right < size; right++) {
        // Add current character to the count
        if (s[right] == 'a') count_a++;
        else if (s[right] == 'b') count_b++;
        else if (s[right] == 'c') count_c++;

        // Ensure remaining characters outside the window satisfy at least k
        while (total_a - count_a < k || total_b - count_b < k || total_c - count_c < k) {
            // Shrink the window from the left
            if (s[left] == 'a') count_a--;
            else if (s[left] == 'b') count_b--;
            else if (s[left] == 'c') count_c--;
            left++;
        }

        // Update maximum removable substring length
        max_remove = max(max_remove, right - left + 1);
    }

    // Minimum time = size - max removable substring
    return size - max_remove;
}

int main() {
    string s = "aabaaaacaabc";
    int k = 2;
    cout << takeCharacters(s, k); // Output should be 8
    return 0;
}
