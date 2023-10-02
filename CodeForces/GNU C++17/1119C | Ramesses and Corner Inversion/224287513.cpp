/**
 *     author: brownfox2k6
 *    created: Thu 21 Sep 2023 18:22:41 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<int> rowA(n), colA(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool c; cin >> c;
            rowA[i] += c;
            colA[j] += c;
        }
    }
 
    vector<int> rowB(n), colB(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool c; cin >> c;
            rowB[i] += c;
            colB[j] += c;
        }
    }
 
    for (int i = 0; i < n; ++i) {
        if (rowA[i] % 2 != rowB[i] % 2) {
            cout << "No";
            return;
        }
    }
 
    for (int j = 0; j < m; ++j) {
        if (colA[j] % 2 != colB[j] % 2) {
            cout << "No";
            return;
        }
    }
 
    cout << "Yes";
}
 
 
 
#define mtt false
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