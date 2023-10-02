/**
 *     author: brownfox2k6
 *    created: Sun 24 Sep 2023 21:00:00 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    bool changed[26] = {0};
    for (int i = 0; i < n; ++i) {
        while (s[i] > 'a') {
            if (changed[s[i] - 'a']) {
                --s[i];
            } else if (k) {
                changed[s[i] - 'a'] = 1;
                --s[i];
                --k;
            } else {
                break;
            }
        }
    }
    cout << s << '\n';
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