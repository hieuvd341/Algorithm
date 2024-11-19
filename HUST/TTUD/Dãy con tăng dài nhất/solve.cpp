#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longest_increasing_subsequence(const vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;

    vector<int> dp(size, 1); 
    int max_length = 1;

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_length = max(max_length, dp[i]);
    }

    return max_length;
}

int main() {
    vector<int> nums = {2, 0, 6, 1, 2, 9};
    cout << "Length of the longest increasing subsequence: " << longest_increasing_subsequence(nums) << endl;
    return 0;
}
