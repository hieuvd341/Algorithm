#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int main()
{
    int times;
    cin >> times;
    long long chia = (long long)(pow(10, 9) + 7);
    for (int time = 0; time < times; time++)
    {
        int n, k;
        cin >> n;
        cin >> k;
        vector<int> array;
        int tmp;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            array.push_back(tmp);
        }
        vector<int> dp(n, INT_MIN);
        dp[0] = array[0];
        for (int i = 1; i < n; i++)
        {
            if (dp[i - 1] + array[i] > array[i])
            {
                dp[i] = dp[i - 1] + array[i];
            }
            else
            {
                dp[i] = array[i];
            }
        }
        int max = dp[0];
        for (int i = 0; i < n; i++)
        {
            sum += array[i];
            if (max < dp[i])
                max = dp[i];
        }
        if (max > 0)
        {
            for (int i = 0; i < k; i++)
            {
                sum = sum%chia;
                max = max%chia;
                sum += max;
                max = max * 2;
                
            }
            cout << sum % chia << endl;
        }
        else
        {
            while(sum < 0) sum += chia;
            cout << sum << endl;
        }
    }
}