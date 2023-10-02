/**
 *     author: brownfox2k6
 *    created: Wed 13 Sep 2023 23:21:43 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
#define vpii vector<pair<int, int>>
 
vpii proc(int n, int k) {
    vpii a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int occ = 1;
        while (x % k == 0) {
            x /= k;
            occ *= k;
        }
        if (!a.empty() && a.back().first == x) {
            a.back().second += occ;
        } else {
            a.emplace_back(x, occ);
        }
    }
    return a;
}
 
void solve() {
    int n, m, k;
    cin >> n >> k;
    vpii a = proc(n, k);
    cin >> m;
    vpii b = proc(m, k);
    if (a == b) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
        if (dbg) {
            cout << '\n';
        }
    }
}