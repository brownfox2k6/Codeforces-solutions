/**
 *     author: brownfox2k6
 *    created: Tue 12 Sep 2023 20:42:05 Hanoi, Vietnam
**/
#include "bits/stdc++.h"
using namespace std;
 
#define int int64_t
 
void solve() {
    int n, g, b;
    cin >> n >> g >> b;
 
    int need = (n + 1) >> 1LL;
    int ans = (need / g) * (b + g);
    if (need % g == 0) {
        ans -= b;
    } else {
        ans += need % g;
    }
 
    cout << max(n, ans) << ' ';
}
 
signed main() {
    int t;
    for (cin >> t; t--; ) solve();
}