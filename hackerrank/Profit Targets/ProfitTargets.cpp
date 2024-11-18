#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ifstream inputFile("input014.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error!! Can not open file";
        return 1;
    }
    int n;
    inputFile >> n;
    vector<int> arr;
    int a;
    for (int i = 0; i < n; i++)
    {
        inputFile >> a;
        arr.push_back(a);
    }
    int target;
    inputFile >> target;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int ans = 0;
    if (target % 2 == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (mp[target - arr[i]] != 0)
            {
                ans+= min(mp[target - arr[i]], mp[arr[i]]);
                // cout << target - arr[i] << endl;
            }
        }
        cout << ans/2;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (mp[target - arr[i]] != 0 && target - arr[i] != target / 2)
            {
                ans+= min(mp[target - arr[i]], mp[arr[i]]);
            }
            ans += mp[target - arr[i]] / 2;
        }
        cout << ans/2;
    }
    
    return 0;
}