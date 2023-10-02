/**
 *     author: brownfox2k6
 *    created: Tue 12 Sep 2023 21:29:16 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt false
#define dbg false
 
void solve() {
    string s;
    cin >> s;
    string ans;
 
    for (char c : s) {
        if (!ans.empty() && c == ans.back()) {
            ans.pop_back();
        } else {
            ans.push_back(c);
        }
    }
 
    cout << ans;
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