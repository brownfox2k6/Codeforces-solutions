/**
 *     author: brownfox2k6
 *    created: Sun 24 Sep 2023 13:24:05 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define N 300005
 
vector<pair<int, int>> adj[N];
int val[N];
int64_t dp[N], ans;
 
void dfs(int node, int par) {
    int64_t max1 = 0;
    int64_t max2 = 0;
    for (auto [u, wt] : adj[node]) {
        if (u != par) {
            dfs(u, node);
            int64_t tmp = dp[u] - wt;
            if (tmp > max1) {
                max2 = max1;
                max1 = tmp;
            } else if (tmp > max2) {
                max2 = tmp;
            }
        }
    }
    dp[node] = max1 + val[node];
    ans = max(ans, max1 + max2 + val[node]);
}
 
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }
    for (int i = 0; i < n-1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1, 0);
    cout << ans;
}