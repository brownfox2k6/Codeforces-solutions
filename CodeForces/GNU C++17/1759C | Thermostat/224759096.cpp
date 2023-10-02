/**
 *     author: brownfox2k6
 *    created: Sat 23 Sep 2023 21:18:12 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;
    if (a > b) {
        swap(a, b);
    }    
 
    if (a == b) {
        cout << 0;
    } else if (b - a >= x) {
        cout << 1;
    } else if (r - b >= x || a - l >= x) {
        cout << 2;
    } else if (r - a >= x && b - l >= x) {
        cout << 3;
    } else {
        cout << -1;
    }
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
        cout << '\n';
        if (dbg) {
            cout << '\n';
        }
    }
}