/**
 *     author: brownfox2k6
 *    created: Tue 19 Sep 2023 14:51:30 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
vector<int> g[1001];
 
vector<int> bfs(int u) {
    vector<int> dist(1001, -1);
    dist[u] = 0;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int x : g[v]) {
            if (dist[x] == -1) {
                dist[x] = dist[v] + 1;
                q.push(x);
            }
        }
    }
    return dist;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;
 
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
 
    vector<int> to_s = bfs(s);
    vector<int> to_t = bfs(t);
    int s_to_t = to_s[t];
    int ans = 0;
    for (int u = 1; u <= n-1; ++u) {
        for (int v = u+1; v <= n; ++v) {
            ans += min(to_s[u] + to_t[v], to_s[v] + to_t[u]) + 1 >= s_to_t;
        }
    }
 
    cout << ans - m;
}