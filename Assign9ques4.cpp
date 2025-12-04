// dijkstra_fixed.cpp
#include <bits/stdc++.h>
using namespace std;
struct PQcmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        return a.first > b.first; // min-heap by distance
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, e;
    cout << "Enter vertices and edges: ";
    if(!(cin >> n >> e)) return 0;
    vector<vector<pair<int,int>>> adj(n);
    cout << "Enter edges (u v w):\n";
    for(int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if(u < 0 || u >= n || v < 0 || v >= n) {
            cerr << "Invalid vertex index\n";
            return 0;
        }
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove for directed graph
    }
    int start;
    cout << "Enter start node: ";
    cin >> start;
    if(start < 0 || start >= n) {
        cerr << "Invalid start node\n";
        return 0;
    }
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, PQcmp> pq;
    pq.push({0, start});
    while(!pq.empty()) {
        pair<int,int> top = pq.top(); pq.pop();
        int d = top.first;
        int node = top.second;
        if(d != dist[node]) continue;
        for(const auto &pr : adj[node]) {
            int nei = pr.first;
            int w = pr.second;
            if((long long)dist[node] + w < dist[nei]) {
                dist[nei] = dist[node] + w;
                pq.push({dist[nei], nei});
            }
        }
    }
    cout << "Shortest distances from node " << start << ":\n";
    for(int i = 0; i < n; ++i) {
        if(dist[i] == INT_MAX) cout << "Node " << i << " : INF\n";
        else cout << "Node " << i << " : " << dist[i] << "\n";
    }
    return 0;
}
