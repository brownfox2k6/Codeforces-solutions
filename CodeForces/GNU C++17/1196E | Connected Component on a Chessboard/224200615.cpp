/**
 *     author: brownfox2k6
 *    created: Wed 20 Sep 2023 23:09:45 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int b, w;
    cin >> b >> w;
 
    bool s = b < w;
    if (s) {
        swap(b, w);
    }
 
    vector<pair<int, int>> ans;
    int y = 2;
    for ( ; w; ++y) {
        if (y & 1) {
            --b;
        } else {
            --w;
        }
        ans.emplace_back(2, y);
    }
 
    for (int ny = 2; ny <= y && b; ny += 2) {
        ans.emplace_back(1, ny);
        --b;
    }
    for (int ny = 2; ny <= y && b; ny += 2) {
        ans.emplace_back(3, ny);
        --b;
    }
    if (b) {
        ans.emplace_back(2, 1);
        --b;
    }
    if (b) {
        ans.emplace_back(2, y);
        --b;
    }
 
    if (b) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto p : ans) {
            cout << p.first << ' ' << p.second + s << '\n';
        }
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