#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, const vector<vector<bool>> &graph, vector<int> &path, int pos)
{
    if (!graph[path[pos - 1]][v])
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool backTrack(const vector<vector<bool>> &graph, vector<int> &path, int pos)
{
    if (pos == graph.size())
    {
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }

    for (int v = 1; v < graph.size(); v++)
    {
        if (isSafe(v, graph, path, pos))
        {
            path[pos] = v;

            if (backTrack(graph, path, pos + 1))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool isHamiltonianCycle(const vector<vector<bool>> &graph)
{
    vector<int> path(graph.size(), -1);
    path[0] = 0;
    if (!backTrack(graph, path, 1))
    {
        return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<bool>> graph(n, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u - 1][v - 1] = graph[v - 1][u - 1] = true;
        }

        cout << (isHamiltonianCycle(graph) ? 1 : 0) << endl;
    }
    return 0;
}
