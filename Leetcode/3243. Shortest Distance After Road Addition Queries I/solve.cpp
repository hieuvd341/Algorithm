#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

int dfs(vector<vector<int>> &adj, int n){
    queue<int> q;
    q.push(0);
    vector<int> dist(n, -1);
    dist[0] = 0;
    while(!q.empty()) {
        int node = q.front();
        if(node == n-1){
            return dist[node];
        }
        q.pop();
        for(int i =0; i < adj[node].size(); i++){
            if(dist[adj[node][i]] == -1){
                dist[adj[node][i]] = dist[node] + 1;
                q.push(adj[node][i]);
            }
        }
    }
    return -1;

}
vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
{
    vector<int> res;
    vector<vector<int>> adj(n);
    vector<int> dist(n, -1);

    for(int i =0; i < n; i++){
        adj[i].push_back(i+1);
    }

    int s = queries.size();
    for(int i =0; i < s; i++){
        adj[queries[i][0]].push_back(queries[i][1]);
        int ans = dfs(adj, n);
        res.push_back(ans);
    }
    return res;
}

int main()
{
    int n = 5;
    vector<vector<int>> queries = {{2, 4}, {0, 2}, {0, 4}};
    vector<int> res = shortestDistanceAfterQueries(n, queries);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}