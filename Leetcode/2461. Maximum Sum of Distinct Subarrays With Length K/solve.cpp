#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{
    long long maxSum = 0, currentSum = 0;
    unordered_map<int, int> freq; // To keep track of the frequency of elements
    int n = nums.size();

    for (int i = 0; i < n; ++i)
    {
        // Add the current element to the window
        currentSum += nums[i];
        freq[nums[i]]++;

        // If the window size exceeds k, remove the leftmost element
        if (i >= k)
        {
            currentSum -= nums[i - k];
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0)
            {
                freq.erase(nums[i - k]);
            }
        }

        if (freq.size() == k) // All elements in the window are distinct
        {
            maxSum = max(maxSum, currentSum);
        }
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {9, 9, 4, 2, 9, 9, 9};
    int k = 3;
    cout << maximumSubarraySum(nums, k) << endl;
    return 0;
}
