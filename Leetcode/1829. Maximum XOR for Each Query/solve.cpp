#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size();
    vector<int> ans(n);
    int mask = (1 << maximumBit) - 1;
    int xorSum = 0;
    for (int i = 0; i < n; i++) {
        xorSum ^= nums[i];
        ans[n - i - 1] = mask ^ xorSum;
    }
    return ans;
}
int main() {
    vector<int> nums = {0, 1, 1, 3};
    int maximunBit =2;
    vector<int> ans;
    ans = getMaximumXor(nums, maximunBit);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}