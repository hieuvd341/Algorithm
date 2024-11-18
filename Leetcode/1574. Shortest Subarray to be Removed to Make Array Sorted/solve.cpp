#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();
    int right = n - 1;

    while (right > 0 && arr[right] >= arr[right - 1]) {
        right--;
    }

    if (right == 0) return 0;

    int left = 0;
    int res = right; 

    while (left < n && (left == 0 || arr[left] >= arr[left - 1])) {
        while (right < n && arr[right] < arr[left]) {
            right++;
        }
        res = min(res, right - left - 1);
        left++;
    }

    return res;
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    cout << findLengthOfShortestSubarray(arr) << endl;
    return 0;
}
