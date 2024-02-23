#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int size = s.size();
    if (size == 0)
    {
        return 0;
    }
    vector<int> dp(size, 0);
    unordered_map<int, int> mp;
    int i;
    for (i = 0; i < size; i++)
    {
        if (mp[s[i]] == 0)
        {
            mp[s[i]]++;
        }
        else
        {
            break;
        }
    }
    dp[0] = i - 1;
    int m = dp[0];
    if (m == size - 1)
    {
        return m + 1;
    }
    for (int j = 1; j < size; j++)
    {
        mp[s[j - 1]]--;
        int k;
        for (k = j + dp[j - 1]; k < size; k++)
        {
            if (mp[s[k]] == 0)
            {
                mp[s[k]]++;
                // cout << s[k] << " ";
            }
            else
            {
                break;
            }
        }
        dp[j] = k - 1 - j;
        if (m < dp[j])
            m = dp[j];
    }
    return m + 1;
}
int main()
{
    string s = "pwwkew";
    cout << lengthOfLongestSubstring(s);
}