#include <iostream>
#include <map>
#include <vector>
using namespace std;

void help(int edge, int curr, map<int, int> &mp, bool &res)
{
    if (mp.size() == 0)
    {
        res = true;
        return;
    }
    if (curr > edge)
        return;
    if (curr == edge)
    {
        curr = 0;
    }
    for (auto &entry : mp)
    {
        int tmp = entry.first;
        mp[entry.first]--;
        if (entry.second == 0)
            mp.erase(tmp);
        help(edge, curr + entry.first, mp, res);
        mp[tmp]++;
    }
}
bool makesquare(vector<int> &matchsticks)
{
    int sz = matchsticks.size();
    map<int, int> mp;
    int total = 0;
    for (int i = 0; i < sz; i++)
    {
        total += matchsticks[i];
        mp[matchsticks[i]]++;
    }
    if (total % 4 != 0)
        return false;
    int edge = total / 4;
    for (int i = 0; i < sz; i++)
    {
        if (matchsticks[i] > edge)
            return false;
    }
    bool res = false;
    help(edge, 0, mp, res);
    return res;
}

int main()
{
    vector<int> matchsticks;
    matchsticks.push_back(1);
    matchsticks.push_back(1);
    matchsticks.push_back(2);
    matchsticks.push_back(2);
    matchsticks.push_back(2);
    if (makesquare(matchsticks))
    {
        cout << "Squareeeeeeee";
    }
    else
    {
        cout << "Nope";
    }
}