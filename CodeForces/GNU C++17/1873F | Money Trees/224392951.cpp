/**
 *     author: brownfox2k6
 *    created: Thu 21 Sep 2023 22:07:21 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt 1
#define dbg 0
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    int v[n], w[n];
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
 
    vector<pair<int, int>> segs = {{0, 0}};
    for (int i = 1; i < n; ++i) {
        if (w[i-1] % w[i] == 0) {
            segs.back().second = i;
        } else {
            segs.emplace_back(i, i);
        }
    }
 
    if (dbg) {
        for (auto p : segs) cout << p.first << ' ' << p.second << '\n';
    }
 
    int ans = 0;
    for (auto [l, r] : segs) {
        int cursum = 0;
        int maxlength = 0;
        for (int i = l; i <= r; ++i) {
            cursum += v[i];
            while (cursum > k) {
                cursum -= v[l++];
            }
            maxlength = max(maxlength, i-l+1);
        }
        ans = max(ans, maxlength);
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