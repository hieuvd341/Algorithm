#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestCombination(vector<int> &candidates)
{
    int n = candidates.size();
    vector<int> res(24, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 24; j >= 0; j--)
        {
            int k = candidates[i] >> j;
            if (k & 1)
            {
                res[j] += 1;
            }
        }
    }
    int max = res[0];
    for (int i = 0; i < 24; i++)
    {
        if (res[i] > max)
        {
            max = res[i];
        }
    }
    return max;
}

int main()
{
    vector<int> candidates = {8,8};
    int res = largestCombination(candidates);
    cout << res << endl;
    return 0;
}