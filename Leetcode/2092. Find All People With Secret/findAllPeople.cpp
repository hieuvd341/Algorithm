#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
{
    vector<vector<pair<int, int>>> meet(n);

    for (auto v : meetings)
    {
        meet[v[0]].push_back({v[1], v[2]});
        meet[v[1]].push_back({v[0], v[2]});
    }

    vector<int> timeStamp(n, INT_MAX);
    unordered_set<int> res = {0, firstPerson};
    queue<pair<int, int>> q;

    q.push({0, 0});
    q.push({firstPerson, 0});
    timeStamp[firstPerson] = timeStamp[0] = 0;

    while (!q.empty())
    {
        auto [personA, timeA] = q.front();
        q.pop();
        for (auto [personB, timeB] : meet[personA])
        {
            if (timeStamp[personA] <= timeB && timeStamp[personB] > timeB)
            {
                q.push({personB, timeB});
                timeStamp[personB] = timeB;
                res.insert(personB);
            }
        }
    }
    vector<int> ans(begin(res), end(res));
    return ans;
}

int main(){
    int n = 6;
    vector<vector<int>> meetings;
    meetings.push_back({1,2,5 });
    meetings.push_back({2,3,8 });
    meetings.push_back({1,5,10 });
    int firstPerson = 1;
    vector<int> res;
    res=  findAllPeople(n, meetings, firstPerson);
    for(int i =0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}