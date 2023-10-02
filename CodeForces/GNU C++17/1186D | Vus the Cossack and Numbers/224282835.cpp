/**
 *     author: brownfox2k6
 *    created: Thu 21 Sep 2023 17:43:10 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
 
    double bal = 0;
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        int rounded = bal < 0? ceil(x) : floor(x);
        bal += rounded - x;
        cout << rounded << '\n';
    }
}
 
 
 
 
#define mtt false
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