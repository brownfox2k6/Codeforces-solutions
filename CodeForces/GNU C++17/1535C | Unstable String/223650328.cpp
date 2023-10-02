/**
 *     author: brownfox2k6
 *    created: Sun 17 Sep 2023 00:22:45 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    string s;
    cin >> s;
 
    vector<int> dp(2, -1);
    int64_t ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        int k = s[i] - '0';
        if (k == 0 || k == 1) {
            dp[k ^ (i & 1)] = i;
        }
        ans += i - min(dp[0], dp[1]);
    }
 
    cout << ans << '\n';
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