#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < m; j++)
        {
            s += to_string(matrix[i][j]);
        }
        mp[s]++;
    }
    for (int i = 0; i < n; i++)
    {
        string s = "";
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                s += "1";
            }
            else
            {
                s += "0";
            }
        }

        mp[s]++;
    }

    int ans = 0;
    for (auto x : mp)
    {
        ans = max(ans, x.second);
    }
    return ans;
}
int main()
{
    vector<vector<int>> matrix;
    matrix.push_back({0, 0, 0});
    matrix.push_back({0, 0, 1});
    matrix.push_back({1, 1, 0});
    cout << maxEqualRowsAfterFlips(matrix) << endl;
    return 0;
}