/**
 *     author: brownfox2k6
 *    created: Tue 12 Sep 2023 21:45:03 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
#define mtt true
#define dbg false
 
void solve() {
    int n, x;
    cin >> n >> x;
 
    vector<int> a(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }
 
    vector<int> b(n+1, INT_MIN);
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n-len; ++i) {
            b[len] = max(b[len], a[i+len] - a[i]);
        }
    }
 
    for (int k = 0; k <= n; ++k) {
        int mx = 0;
        for (int len = 1; len <= n; ++len) {
            mx = max(mx, b[len] + min(len, k) * x);
        }
        cout << mx << ' ';
    }
}
 
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
        cout << '\n';
        if (dbg) {
            cout << '\n';
        }
    }
}