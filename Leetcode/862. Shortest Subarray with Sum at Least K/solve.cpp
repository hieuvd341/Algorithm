#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    vector<long long> prefixSum(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + nums[i];
    }

    int minLen = n + 1; 

    for (int i = 0; i < n + 1; ++i) {
        while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
            minLen = min(minLen, i - dq.front());
            dq.pop_front();
        }

        while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return minLen <= n ? minLen : -1;
}

int main() {
    vector<int> nums = {1, -1, 2, 2, -1, 2};
    int k = 3;
    cout << shortestSubarray(nums, k) << endl;
    return 0;
}
