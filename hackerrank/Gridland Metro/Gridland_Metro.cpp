<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

long long gridlandMetro(int n, int m, int k, vector<vector<int>> track)
{
    map<long long, vector<vector<long long>>> mp;

    for (long long i = 0; i < k; i++)
    {
        long long row = track[i][0];
        long long start_col = track[i][1];
        long long end_col = track[i][2];

        if (mp[row].empty())
        {
            mp[row].push_back({start_col, end_col});
        }
        else
        {
            long long s = mp[row].size();
            bool flag = false;
            for (long long j = 0; j < s; j++) 
            {
                if (start_col >= mp[row][j][0] && mp[row][j][1] >= start_col)
                {
                    mp[row][j][0] = min(mp[row][j][0], start_col);
                    mp[row][j][1] = max(mp[row][j][1], end_col);
                    flag = true;
                }
                else if (mp[row][j][1] >= end_col && mp[row][j][0] <= end_col)
                {
                    mp[row][j][0] = min(mp[row][j][0], start_col);
                    mp[row][j][1] = max(mp[row][j][1], end_col);
                    flag = true;
                }
            }
            if (flag == false)
            {
                mp[row].push_back({start_col, end_col});
            }
        }
    }
    long long sum = 0;
    for (const auto &entry : mp)
    {
        long long size = entry.second.size();
        for (long long i = 0; i < size; i++)
        {
            sum += entry.second[i][1] - entry.second[i][0] + 1;
        }
    }
    long long mmm = static_cast<long long>(m) * n;
    return mmm - sum;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening input file";
        return 1;
    }
    int n, m, k;
    vector<vector<int>> track;
    inputFile >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        vector<int> v;
        int a, b, c;
        inputFile >> a >> b >> c;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        track.push_back(v);
    }
    cout << gridlandMetro(n, m, k, track);
=======
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

long long gridlandMetro(int n, int m, int k, vector<vector<int>> track)
{
    map<long long, vector<vector<long long>>> mp;

    for (long long i = 0; i < k; i++)
    {
        long long row = track[i][0];
        long long start_col = track[i][1];
        long long end_col = track[i][2];

        if (mp[row].empty())
        {
            mp[row].push_back({start_col, end_col});
        }
        else
        {
            long long s = mp[row].size();
            bool flag = false;
            for (long long j = 0; j < s; j++) 
            {
                if (start_col >= mp[row][j][0] && mp[row][j][1] >= start_col)
                {
                    mp[row][j][0] = min(mp[row][j][0], start_col);
                    mp[row][j][1] = max(mp[row][j][1], end_col);
                    flag = true;
                }
                else if (mp[row][j][1] >= end_col && mp[row][j][0] <= end_col)
                {
                    mp[row][j][0] = min(mp[row][j][0], start_col);
                    mp[row][j][1] = max(mp[row][j][1], end_col);
                    flag = true;
                }
            }
            if (flag == false)
            {
                mp[row].push_back({start_col, end_col});
            }
        }
    }
    long long sum = 0;
    for (const auto &entry : mp)
    {
        long long size = entry.second.size();
        for (long long i = 0; i < size; i++)
        {
            sum += entry.second[i][1] - entry.second[i][0] + 1;
        }
    }
    long long mmm = static_cast<long long>(m) * n;
    return mmm - sum;
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening input file";
        return 1;
    }
    int n, m, k;
    vector<vector<int>> track;
    inputFile >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        vector<int> v;
        int a, b, c;
        inputFile >> a >> b >> c;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        track.push_back(v);
    }
    cout << gridlandMetro(n, m, k, track);
>>>>>>> bad19b40af882feab18b89e58bb73dec7250f825
}