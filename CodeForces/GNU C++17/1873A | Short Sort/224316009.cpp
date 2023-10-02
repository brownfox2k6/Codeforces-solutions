/**
 *     author: brownfox2k6
 *    created: Thu 21 Sep 2023 21:35:41 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
 
void solve() {
    string s;
    cin >> s;
 
    int wrong = 0;
    for (int i = 0; i < 3; ++i) {
        if (s[i] != "abc"[i]) {
            wrong++;
        }
    }
    
    if (wrong == 3) {
        cout << "NO\n";
    } else {
        cout << "Yes\n";
    }
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