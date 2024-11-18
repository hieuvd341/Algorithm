#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

void bfs(const vector<vector<int>>& graph, int start_node, set<int>& visited) {
    queue<int> q;
    
    visited.insert(start_node);
    q.push(start_node);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();
        cout << current_node << " ";
        
        for (int next_node : graph[current_node]) {
            if (visited.find(next_node) == visited.end()) {
                visited.insert(next_node);
                q.push(next_node);
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
    while(k > 0){
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
        k--;
    }

    for (int i = 1; i <= n; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    for (int i = 1; i <= n; ++i) {
        if (visited.find(i) == visited.end()) {
            bfs(graph, i, visited);
        }
    }
    return 0;
}