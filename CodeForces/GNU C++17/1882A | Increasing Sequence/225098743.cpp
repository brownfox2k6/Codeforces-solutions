/**
 *     author: brownfox2k6
 *    created: Mon 25 Sep 2023 21:36:02 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    int n;
    cin >> n;
    int a[n+1];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // sort(a+1, a+n+1);
    a[0] = 0;
 
    int b[n+1];
    b[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (b[i-1]+1 == a[i]) b[i] = b[i-1] + 2;
        else b[i] = b[i-1] + 1;
    }   
 
    cout << b[n] << '\n';
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