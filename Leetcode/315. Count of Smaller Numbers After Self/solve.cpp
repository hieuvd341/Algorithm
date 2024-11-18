#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> countSmaller(vector<int> &nums)
{
    vector<int> result;
    vector<int> sorted;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int left = 0, right = sorted.size();
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (sorted[mid] >= nums[i])
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        result.push_back(right);
        sorted.insert(sorted.begin() + right, nums[i]);
    }
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    vector<int> nums = {5, 2, 6, 1};
    vector<int> result = countSmaller(nums);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}