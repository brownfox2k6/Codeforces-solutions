/**
 *     author: brownfox2k6
 *    created: Thu 21 Sep 2023 21:41:14 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    string a[10];
    for (int i = 0; i < 10; ++i) {
        cin >> a[i];
    }
 
    int total = 0;
 
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (a[i][j] == 'X') {
                if ((i == 0 || i == 9) || (j == 0 || j == 9)) {
                    total += 1;
                } else if ((i == 1 || i == 8) || (j == 1 || j == 8)) {
                    total += 2;
                } else if ((i == 2 || i == 7) || (j == 2 || j == 7)) {
                    total += 3;
                } else if ((i == 3 || i == 6) || (j == 3 || j == 6)) {
                    total += 4;
                } else {
                    total += 5;
                }
            }
        }
    }
 
    cout << total << '\n';
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