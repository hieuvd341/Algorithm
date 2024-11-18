#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;
    // Count the reverse pairs
    for (int i = left; i <= mid; i++) {
        while (j <= right && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += (j - (mid + 1));
    }
    
    // Merge step
    vector<int> temp;
    int i = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);
        }
    }
    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= right) temp.push_back(nums[j++]);
    
    // Copy sorted elements back to the original array
    for (int i = left; i <= right; i++) {
        nums[i] = temp[i - left];
    }
    
    return count;
}

int mergeSortAndCount(vector<int>& nums, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    int count = mergeSortAndCount(nums, left, mid);
    count += mergeSortAndCount(nums, mid + 1, right);
    count += mergeAndCount(nums, left, mid, right);
    return count;
}

int reversePairs(vector<int>& nums) {
    return mergeSortAndCount(nums, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Number of reverse pairs: " << reversePairs(nums) << endl;
    return 0;
}
