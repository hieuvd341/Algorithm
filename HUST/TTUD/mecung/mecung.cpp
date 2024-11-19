#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void dfs(vector<vector<int>> &maps, int n, int m, int curr_x, int curr_y, int &min, int step)
{
    if (curr_x == 0 || curr_x == n - 1 || curr_y == 0 || curr_y == m - 1)
    {
        if (step < min)
            min = step;
    }
    if (curr_x < n - 1 && maps[curr_x+1][curr_y] == 0)
    {
        maps[curr_x][curr_y] = 2;
        dfs(maps, n, m, curr_x + 1, curr_y, min, step + 1);
        maps[curr_x][curr_y] = 0;
    }
    if (curr_x > 0 && maps[curr_x-1][curr_y] == 0){
        maps[curr_x][curr_y] = 2;
        dfs(maps, n, m, curr_x - 1, curr_y, min, step + 1);
        maps[curr_x][curr_y] = 0;

    }
    if (curr_y < m - 1 && maps[curr_x][curr_y+1] == 0){
        maps[curr_x][curr_y] = 2;
        dfs(maps, n, m, curr_x, curr_y + 1, min, step + 1);
        maps[curr_x][curr_y] = 0;

    }
    if (curr_y > 0 && maps[curr_x][curr_y-1] == 0) {
        maps[curr_x][curr_y] = 2;
        dfs(maps, n, m, curr_x, curr_y - 1, min, step + 1);
        maps[curr_x][curr_y] = 0;
    }
}

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        return 1;
    }
    int n, m, r, c;
    inputFile >> n >> m >> r >> c;
    int tmp;
    vector<vector<int>> maps;
    for (int i = 0; i < n; i++)
    {
        vector<int> map;
        for (int j = 0; j < m; j++)
        {
            inputFile >> tmp;
            map.push_back(tmp);
        }
        maps.push_back(map);
    }
    int min = INT_MAX;
    dfs(maps, n, m, r-1, c-1, min, 1);
    if (min == INT_MAX)
        return -1;
    cout << min;
    return min;
}