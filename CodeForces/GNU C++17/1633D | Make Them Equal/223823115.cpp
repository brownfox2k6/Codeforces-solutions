/**
 *     author: brownfox2k6
 *    created: Mon 18 Sep 2023 16:50:23 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define N 1001
int t, k, n;
int dep[N], b[N], c[N];
 
void prep() {
    memset(dep, -1, sizeof dep);
    queue<int> q;
    q.push(1);
    dep[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= x/2 + 1; ++i) {
            int y = x + x/i;
            if (y < N && dep[y] == -1) {
                q.push(y);
                dep[y] = dep[x] + 1;
            }
        }
    }
}
 
int f(int ind, int op, vector<vector<int>> &dp) {
    if (op < 0) return INT_MIN;
    if (ind == n) return 0;
    if (dp[ind][op] != -1) return dp[ind][op];
 
    int take = c[ind] + f(ind+1, op-b[ind], dp);
    int notTake = f(ind+1, op, dp);
    return dp[ind][op] = max(take, notTake);
}
 
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        b[i] = dep[b[i]];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<vector<int>> dp(n, vector<int>(min(k, 12*n)+1, -1));
    cout << f(0, min(k, 12*n), dp) << '\n';
}
 
main() {
    cin.tie(0)->sync_with_stdio(0);
    prep();
    for (cin >> t; t--; ) {
        solve();
    }
}