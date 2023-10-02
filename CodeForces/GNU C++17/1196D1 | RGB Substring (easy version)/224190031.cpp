/**
 *     author: brownfox2k6
 *    created: Wed 20 Sep 2023 22:13:07 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int n, k;
string s;
struct node {
    int rgb, gbr, brg;
} pref[200005];
 
void solve() {
    cin >> n >> k >> s;
    
    for (int i = 0; i < n; ++i) {
        pref[i+1].rgb = pref[i].rgb + (s[i] == "RGB"[i % 3]);
        pref[i+1].brg = pref[i].brg + (s[i] == "BRG"[i % 3]);
        pref[i+1].gbr = pref[i].gbr + (s[i] == "GBR"[i % 3]);
    }
 
    int ans = 0;
    for (int i = k; i <= n; ++i) {
        ans = max(ans, max({
            pref[i].rgb - pref[i-k].rgb,
            pref[i].brg - pref[i-k].brg,
            pref[i].gbr - pref[i-k].gbr
        }));
    }
 
    cout << k - ans << '\n';
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