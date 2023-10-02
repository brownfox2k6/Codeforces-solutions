/**
 *     author: brownfox2k6
 *    created: Thu 28 Sep 2023 21:06:12 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    vector<int> a[1001];
    for (int i = 0; i < n; ++i) {
        int h, w;
        cin >> h >> w;
        a[w].emplace_back(h);
    }
 
    vector<int> pref[1001];
    for (int i = 1; i <= 1000; ++i) {
        sort(a[i].begin(), a[i].end());
        pref[i].resize(a[i].size() + 1);
        pref[i][0] = 0;
        for (int j = 0; j < a[i].size(); ++j) {
            pref[i][j+1] = pref[i][j] + a[i][j];
        }
    }
 
    while (q--) {
        int64_t ans = 0;
        int hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        for (int w = ws+1; w <= wb-1; ++w) {
            int itl = upper_bound(a[w].begin(), a[w].end(), hs) - a[w].begin();
            int itr = upper_bound(a[w].begin(), a[w].end(), hb-1) - a[w].begin();
            ans += (int64_t) w * (pref[w][itr] - pref[w][itl]);
        }
        cout << ans << '\n';
    }
}
 
 
 
 
 
#define mtt true
#define dbg false
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // freopen("inp.txt", "r", stdin);
 
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