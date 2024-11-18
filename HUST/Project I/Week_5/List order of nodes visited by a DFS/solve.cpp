#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void dfs(const vector<vector<int>>& graph, int start_node, set<int>& visited) {
    if (visited.find(start_node) == visited.end()) {
        visited.insert(start_node);
        cout << start_node << " ";

        for (int next_node : graph[start_node]) {
            if (visited.find(next_node) == visited.end()) {
                dfs(graph, next_node, visited);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<vector<int>> graph(n + 1); 
    set<int> visited; 
    int tmp1, tmp2;
    while(k>0){
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
        k--;
    }
    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(graph, 1, visited);

    return 0;
}
