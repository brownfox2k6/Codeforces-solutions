/**
 *     author: brownfox2k6
 *    created: Tue 19 Sep 2023 20:58:54 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
 
    vector<int> v[26];
    for (int i = 0; i < n; ++i) {
        v[s[i] - 'a'].emplace_back(i);
    }
 
    int ps = 0;
    int ans = 1;
    for (int pt = 0; pt < m; ++pt) {
        int c = t[pt] - 'a';
        if (v[c].empty()) {
            return -1;
        }
        auto it = lower_bound(v[c].begin(), v[c].end(), ps);
        if (it == v[c].end()) {
            ++ans;
            ps = v[c][0] + 1;
        } else {
            ps = *it + 1;
        }
    }
 
    return ans;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t;
    for (cin >> t; t--; ) {
        cout << solve() << '\n';
    }
}