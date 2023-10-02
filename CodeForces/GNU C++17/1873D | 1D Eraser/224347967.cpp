/**
 *     author: brownfox2k6
 *    created: Thu 21 Sep 2023 21:49:05 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
 
    int total = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == 'B') {
            i += k;
            ++total;
        } else {
            ++i;
        }
    }
 
    cout << total << '\n';
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