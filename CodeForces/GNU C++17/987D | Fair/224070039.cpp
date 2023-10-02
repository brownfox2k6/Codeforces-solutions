/**
 *     author: brownfox2k6
 *    created: Tue 19 Sep 2023 23:29:41 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, m, k, s;
    cin >> n >> m >> k >> s;
 
    vector<int> color[k];
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        color[c-1].emplace_back(i);
    }
 
    vector<int> g[n];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[--u].emplace_back(--v);
        g[v].emplace_back(u);
    }
 
    int choice[n][k];
    for (int i = 0; i < k; ++i) {
        vector<int> dist(n, -1);
        queue<int> q;
        for (int u : color[i]) {
            q.push(u);
            dist[u] = 0;
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            choice[j][i] = dist[j];
        }
    }
 
    for (int i = 0; i < n; ++i) {
        nth_element(choice[i], choice[i]+s, choice[i]+k);
        cout << accumulate(choice[i], choice[i]+s, 0) << ' ';
    }
}