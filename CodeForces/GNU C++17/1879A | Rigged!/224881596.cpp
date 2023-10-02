/**
 *     author: brownfox2k6
 *    created: Sun 24 Sep 2023 21:37:11 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int sf, ef;
    cin >> sf >> ef;
    bool ok = 1;
    for (int i = 0; i < n-1; ++i) {
        int s, e;
        cin >> s >> e;
        if (s >= sf && e >= ef) {
            ok = 0;
        }
    }
    if (ok) {
        cout << sf << '\n';
    } else {
        cout << -1 << '\n';
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
        if (dbg) {
            cout << '\n';
        }
    }
}