#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countFairPairs(vector<int> &nums, int lower, int upper) {
    sort(nums.begin(), nums.end());
    long long count = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; ++i) {
        int minVal = lower - nums[i];
        int maxVal = upper - nums[i];
        
        // Find the range [minVal, maxVal] in the sorted array for valid pairs
        auto left = lower_bound(nums.begin() + i + 1, nums.end(), minVal);
        auto right = upper_bound(nums.begin() + i + 1, nums.end(), maxVal);
        
        // Count the number of valid elements in range
        count += distance(left, right);
    }
    
    return count;
}

int main() {
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3, upper = 6;
    cout << countFairPairs(nums, lower, upper) << endl;
    return 0;
}
