/**
 *     author: brownfox2k6
 *    created: Fri 22 Sep 2023 23:55:47 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define vi vector<int>
#define vvi vector<vi>
 
void countSubtree(int node, int par, vi &cnt, vvi &adj) {
    for (int v : adj[node]) {
        if (v != par) {
            countSubtree(v, node, cnt, adj);
            cnt[node] += cnt[v];
        }
    }
}
 
void dfs(int node, int par, vi &dp, vi &cnt, vvi &adj) {
    vi child;
    for (int v : adj[node]) {
        if (v != par) {
            child.emplace_back(v);
            dfs(v, node, dp, cnt, adj);
        }
    }
    if (adj[node].size() == 2) {
        dp[node] = cnt[child[0]] - 1;
    } else if (adj[node].size() == 3) {
        dp[node] = max({
            dp[node],
            dp[child[0]] + cnt[child[1]] - 1,
            dp[child[1]] + cnt[child[0]] - 1
        });
    }
}
 
void solve() {
    int n;
    cin >> n;
 
    vvi adj(n+1);
    adj[1].emplace_back(0);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
 
    vi cnt(n+1, 1);
    countSubtree(1, 0, cnt, adj);
 
    vi dp(n+1, 0);
    dfs(1, 0, dp, cnt, adj);
 
    cout << dp[1] << '\n';
}
 
 
 
 
#define mtt true
#define dbg false
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    if (mtt) {
        cin >> t;
    }
    for (int i = 1; i <= t; ++i) {
        if (dbg) {
            cout << "Testcase #" << i << '\n';
        }
        solve();
        if (dbg) {
            cout << '\n';
        }
    }
}