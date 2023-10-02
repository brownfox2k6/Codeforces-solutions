/**
 *     author: brownfox2k6
 *    created: Mon 21 Aug 2023 15:07:05 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    vector<int> v(n, n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        if (x > y) {
            swap(x, y);
        }
        v[x] = min(v[x], y);
    }
 
    for (int i = n-2; i >= 0; --i) {
        v[i] = min(v[i+1], v[i]);
    }
 
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += v[i] - i;
    }
    cout << ans << ' ';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    for (cin >> t; t--; ) {
        solve();
    }
}