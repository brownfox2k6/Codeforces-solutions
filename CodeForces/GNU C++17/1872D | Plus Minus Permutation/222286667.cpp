/**
 *     author: brownfox2k6
 *    created: Thu 07 Sep 2023 21:36:00 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
#define int long long
 
bool prime(int x) {
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return x >= 2;
}
 
int sr(int l, int r) {
    // cout << l << ' ' << r << '\n';
    return (r-l+1) * (l+r) / 2;
}
 
int lcm(int x, int y) {
    return x * y / __gcd(x, y);
}
 
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
 
    int ans = sr(n-n/x+1, n) - sr(1, n/y - n/(lcm(x, y))) - sr(n-n/x+1, n-n/x+n/lcm(x, y));
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
        // cout << '\n';
        if (dbg) {
            cout << '\n';
        }
    }
}