/**
 *     author: brownfox2k6
 *    created: Wed 20 Sep 2023 22:52:57 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define BORDER 100000
 
void solve() {
    int minX = -BORDER;
    int maxX = BORDER;
    int minY = -BORDER;
    int maxY = BORDER;
 
    int n;
    for (cin >> n; n--; ) {
        int x, y, left, up, right, down;
        cin >> x >> y >> left >> up >> right >> down;
        if (!left) {
            minX = max(minX, x);
        }
        if (!right) {
            maxX = min(maxX, x);
        }
        if (!up) {
            maxY = min(maxY, y);
        }
        if (!down) {
            minY = max(minY, y);
        }
    }
 
    if (minX > maxX || minY > maxY) {
        cout << "0\n";
    } else {
        cout << "1 " << minX << ' ' << minY << '\n';
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