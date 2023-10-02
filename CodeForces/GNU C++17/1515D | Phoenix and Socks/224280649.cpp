/**
 *     author: brownfox2k6
 *    created: Thu 21 Sep 2023 17:21:04 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
 
    map<int, int> cl;
    for (int i = 0; i < l; ++i) {
        int c;
        cin >> c;
        ++cl[c];
    }
 
    int lrem = l;
    int rrem = r;
    map<int, int> cr;
    for (int i = 0; i < r; ++i) {
        int c;
        cin >> c;
        if (cl[c]) {
            --cl[c];
            --lrem;
            --rrem;
        } else {
            ++cr[c];
        }
    }
 
    if (lrem < rrem) {
        swap(lrem, rrem);
        swap(cl, cr);
    }
 
    int ans = 0;
    for (auto &[c, v] : cl) {
        int can = min(lrem-rrem, v-(v%2));
        ans += can/2;
        lrem -= can;
    }
 
    ans += (lrem - rrem) / 2 + (lrem + rrem) / 2;
    cout << ans << '\n';
}
 
 
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    for (cin >> t; t--; ) {
        solve();
    }
}