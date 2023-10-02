/**
 *     author: brownfox2k6
 *    created: Thu 07 Sep 2023 21:36:00 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    int n;
    cin >> n;
    // pair<int, int> p = {INT_MAX, INT_MAX};
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int d, s;
        cin >> d >> s;
        ans = min(ans, d + ((s-1)/2));
        // p = min(p, {d, s});
    }
 
    cout << ans << '\n';
    // int d, s;
    // tie(d, s) = p;
    // cout << d << ' ' << s << '\n';
    // if (d == 1)
    //     cout << d + ((s-2)/2) << '\n';
    // else 
    //     cout << d + ((s-1)/2) << '\n';
}
 
int main() {
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