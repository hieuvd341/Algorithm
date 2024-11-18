//https://www.youtube.com/watch?v=RppuJYwlcI8
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

int N, M, s, t;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INT_MAX});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow() {
    int flow = 0;
    vector<int> parent(N + 1);
    int new_flow;

    while (new_flow = bfs(parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    cin >> N >> M >> s >> t;
    capacity.assign(N + 1, vector<int>(N + 1, 0));
    adj.assign(N + 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        capacity[u][v] = c;
    }

    cout << maxflow() << endl;

    return 0;
}
