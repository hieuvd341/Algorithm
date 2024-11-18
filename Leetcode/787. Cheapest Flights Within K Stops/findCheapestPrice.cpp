#include <vector>
#include <iostream>
#include <map>
#include<unordered_map>
#include<queue>
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for (auto flight : flights)
    {
        adj[flight[0]].push_back({flight[1], flight[2]});
    }
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    queue<pair<int, int>> q;
    q.push({src, 0});
    int stops = 0;
    while (!q.empty() && stops <= k)
    {
        int sz = q.size();
        while (sz-- > 0)
        {
            auto [node, distance] = q.front();
            q.pop();

            if (!adj.count(node))
                continue;
            for (auto &[neighbour, price] : adj[node])
            {
                if (price + distance >= dist[neighbour])
                    continue;
                dist[neighbour] = price + distance;
                q.push({neighbour, dist[neighbour]});
            }
        }
        stops++;
    }
    return dist[dst] == INT_MAX ? -1 : dist[dst];
}
int main()
{
    int n = 5;
    vector<vector<int>> flights;
    flights.push_back({0, 1, 100});
    flights.push_back({1, 2, 100});
    flights.push_back({2, 0, 100});
    flights.push_back({1, 3, 600});
    flights.push_back({2, 3, 200});
    flights.push_back({3, 4, 100});
    int src = 0;
    int dst = 4;
    int k = 2;
    cout << findCheapestPrice(n, flights, src, dst, k);
}