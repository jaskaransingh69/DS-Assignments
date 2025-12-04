#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for(int nei : adj[node]) {
        if(!visited[nei])
            dfs(nei, adj, visited);
    }
}
int main() {
    int n, e;
    cout << "Enter vertices and edges: ";
    cin >> n >> e;
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):\n";
    while(e--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph
    }
    int start;
    cout << "Enter start node: ";
    cin >> start;
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    dfs(start, adj, visited);
    return 0;
}