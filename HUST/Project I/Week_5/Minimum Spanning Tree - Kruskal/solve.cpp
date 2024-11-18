#include <iostream>
#include <vector>
#include <algorithm>
#define max 100
using namespace std;

struct Edge
{
    int u, v, weight;
};
// sắp xếp theo weight
bool compareEdge(Edge a, Edge b)
{
    return a.weight < b.weight;
}

// tìm nút cố nội tổ tiên
int find(vector<int> &parent, int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}
// kết nối 2 nút lại với nhau
void Union(vector<int> &parent, int x, int y)
{
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset)
    {
        parent[xset] = yset;
    }
}

int kruskal(vector<Edge> &edges, int V)
{
    sort(edges.begin(), edges.end(), compareEdge);
    vector<int> parent(V, -1);
    int sum = 0;

    for (Edge edge : edges)
    {
        int x = find(parent, edge.u);
        int y = find(parent, edge.v);

        if (x != y)
        {
            sum += edge.weight;
            Union(parent, x, y);
        }
    }

    return sum;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);

    for (int i = 0; i < E; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }

    cout << kruskal(edges, V) << endl;

    return 0;
}