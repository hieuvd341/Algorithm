#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> resultsArray(vector<int> &nums, int k)
{
    int size = nums.size();
    vector<int> result;
    vector<int> tmp(size, 0);
    tmp[0] = 1;
    for (int i = 1; i < size; i++)
    {
        if (nums[i] == nums[i - 1]+1)
        {
            tmp[i] = 1;
        }
    }

    int sum = 0;
    for (int i = 1; i < k; i++)
    {
        sum += tmp[i];
    }
    if (sum == k-1)
    {
        result.push_back(nums[k - 1]);
    }
    else
    {
        result.push_back(-1);
    }

    for (int i = k; i < size; i++)
    {
        sum = sum - tmp[i - k+1] + tmp[i];
        // cout << sum << " ";
        if (sum == k-1)
        {
            result.push_back(nums[i]);
        }
        else
        {
            result.push_back(-1);
        }
    }

    return result;
}
int main()
{
    vector<int> nums = {1,3,4};
    int k = 2;
    vector<int> result = resultsArray(nums, k);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}