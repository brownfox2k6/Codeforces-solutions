/**
 *     author: brownfox2k6
 *    created: Wed 20 Sep 2023 21:11:00 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    string s;
    cin >> s;
 
    vector<int> ind[10];
    for (int i = 0; i < s.length(); ++i) {
        ind[s[i] - '0'].emplace_back(i);
    }
 
    int ans = 0;
    for (int i = 0; i <= 9; ++i) {
        ans = max(ans, (int) ind[i].size());
    }
 
    for (int first = 0; first <= 9; ++first) {
        for (int second = 0; second <= 9; ++second) {
            if (first == second) {
                continue;
            }
            int len = 0;
            int i = 0;
            while (true) {
                if (len & 1) {
                    auto it = lower_bound(ind[first].begin(), ind[first].end(), i);
                    if (it == ind[first].end()) {
                        break;
                    }
                    i = *it + 1;
                } else {
                    auto it = lower_bound(ind[second].begin(), ind[second].end(), i);
                    if (it == ind[second].end()) {
                        break;
                    }
                    i = *it + 1;
                }
                ++len;
            }
            ans = max(ans, len - (len & 1));
        }
    }
 
    cout << s.length() - ans << '\n';
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