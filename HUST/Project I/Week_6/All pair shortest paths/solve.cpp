#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> d(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i)
    {
        d[i][i] = 0; // Distance to itself is 0
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u - 1][v - 1] = w;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (d[i][k] != INT_MAX && d[k][j] != INT_MAX && d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (d[i][j] == INT_MAX)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << d[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
