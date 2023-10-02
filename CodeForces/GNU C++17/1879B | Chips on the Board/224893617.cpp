/**
 *     author: brownfox2k6
 *    created: Sun 24 Sep 2023 21:40:20 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
 
    int64_t sa = accumulate(a.begin(), a.end(), 0LL);
    int64_t sb = accumulate(b.begin(), b.end(), 0LL);
 
    int64_t op1 = sa + (int64_t)b[0] * n;
    int64_t op2 = sb + (int64_t)a[0] * n;
    cout << min(op1, op2) << '\n';
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