#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;
    vector<vector<int>> adj(n);
    cout << "Enter edges (u v):\n";
    while(e--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // remove for directed graph
    }
    int start;
    cout << "Enter start node: ";
    cin >> start;
    vector<bool> visited(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    cout << "BFS Traversal: ";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int nei : adj[node]) {
            if(!visited[nei]) {
                visited[nei] = true;
                q.push(nei);
            }
        }
    }
    return 0;
}
