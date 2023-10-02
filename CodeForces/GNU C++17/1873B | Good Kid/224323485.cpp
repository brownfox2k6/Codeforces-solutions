/**
 *     author: brownfox2k6
 *    created: Thu 21 Sep 2023 21:38:16 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    long long ans = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        a[i] += 1;
        long long prod = 1;
        for (int i = 0; i < n; ++i) {
            prod *= a[i];
        }
        a[i] -= 1;
        ans = max(ans, prod);
    }
 
    cout << ans << '\n';
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