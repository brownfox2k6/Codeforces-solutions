/**
 *     author: brownfox2k6
 *    created: Wed 20 Sep 2023 22:38:23 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> po;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x & 1) {
            po.emplace_back(i);
        }
    }
 
    int m = po.size();
    if (m < k || m % 2 != k % 2) {
        cout << "NO\n";
        return;
    }
 
    cout << "YES\n";
    for (int i = 0; i < k-1; ++i) {
        cout << po[i] << ' ';
    }
    cout << n << '\n';
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