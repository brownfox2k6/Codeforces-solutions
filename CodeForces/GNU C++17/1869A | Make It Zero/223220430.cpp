/**
 *     author: brownfox2k6
 *    created: Wed 13 Sep 2023 20:25:53 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
    }
 
    if (n & 1) {
        cout << 4 << '\n';
        cout << 1 << ' ' << n-1 << '\n';
        cout << 1 << ' ' << n-1 << '\n';
        cout << n-1 << ' ' << n << '\n';
        cout << n-1 << ' ' << n << '\n';
    } else {
        cout << 2 << '\n';
        cout << 1 << ' ' << n << '\n';
        cout << 1 << ' ' << n << '\n';
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