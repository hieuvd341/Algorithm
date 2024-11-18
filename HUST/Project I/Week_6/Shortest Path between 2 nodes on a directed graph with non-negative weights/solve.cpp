#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge
{
    int to;
    int weight;
};

void create(vector<vector<Edge>> &graph, int from, int to, int weight)
{
    graph[from].push_back(Edge{to, weight});
}

// Dijkstra's algorithm to find the shortest path from source to target
int dijkstra(const vector<vector<Edge>> &graph, int source, int target)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(graph.size(), INT_MAX);

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
        {
            continue;
        }

        for (const auto &edge : graph[u])
        {
            int v = edge.to;
            int weight = edge.weight;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[target] == INT_MAX ? -1 : dist[target];
}

int main()
{
    int n, m, s, t;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        create(graph, u, v, w);
    }

    cin >> s >> t;
    int res = dijkstra(graph, s, t);

    cout << res << endl;

    return 0;
}
