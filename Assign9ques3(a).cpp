#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;
};
struct DSU {
    vector<int> parent, rankv;
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if(rankv[a] == rankv[b]) rankv[a]++;
        }
    }
};
int main() {
    int n, e;
    cout << "Enter vertices and edges: ";
    cin >> n >> e;
    vector<Edge> edges(e);
    cout << "Enter edges (u v w):\n";
    for(int i = 0; i < e; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end(), [](auto& a, auto& b){
        return a.w < b.w;
    });
    DSU dsu(n);
    int total = 0;
    cout << "Kruskal MST edges:\n";
    for(auto& ed : edges) {
        if(dsu.find(ed.u) != dsu.find(ed.v)) {
            dsu.unite(ed.u, ed.v);
            total += ed.w;
            cout << ed.u << " - " << ed.v << " (weight " << ed.w << ")\n";
        }
    }
    cout << "Total MST Cost = " << total << endl;
    return 0;
}
