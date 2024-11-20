#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int findMin(int a, int b, int c)
{
    return min(a, min(b, c));
}
int nthUglyNumber(int n)
{
    int i2 = 1;
    int i3 = 1;
    int i5 = 1;
    int count = 0;
    int next=1;
    vector<int> dp(n + 1, 0);
    while (count != n)
    {
        dp[++count] = next;
        next = findMin(dp[i2] * 2, dp[i3] * 3, dp[i5] * 5);
        if (next == dp[i2] * 2)
            i2++;
        if (next == dp[i3] * 3)
            i3++;
        if (next == dp[i5] * 5)
            i5++;
    }
    return dp[n];
}
int main()
{
    int n = 10;
    cout << nthUglyNumber(n) << endl;
    return 0;
}