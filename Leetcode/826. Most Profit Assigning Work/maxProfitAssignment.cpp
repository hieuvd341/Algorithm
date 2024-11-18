#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <Windows.h>
using namespace std;
int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
{
    map<int, int> mp;
    for (int i = 0; i < difficulty.size(); i++)
    {
        mp[difficulty[i]] = max(profit[i], mp[difficulty[i]]);
    }
    int res = 0;
    for (int i = 0; i < worker.size(); i++)
    {
        int curr = 0;
        for (auto entry : mp)
        {
            if (worker[i] < entry.first)
            {
                break;
            }
            curr = max(curr, entry.second);
        }
        cout << curr << " ";
        res += curr;
    }
    return res;
}
int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Can not open file";
        return 1;
    }
    vector<int> profit;
    vector<int> difficulty;
    vector<int> worker;
    int n;
    inputFile >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        inputFile >> tmp;
        difficulty.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        inputFile >> tmp;
        profit.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        inputFile >> tmp;
        worker.push_back(tmp);
    }
    cout << maxProfitAssignment(difficulty, profit, worker);
}