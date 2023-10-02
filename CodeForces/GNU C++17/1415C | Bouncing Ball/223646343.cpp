/**
 *     author: brownfox2k6
 *    created: Sat 16 Sep 2023 22:56:52 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, p, k, x, y;
    string a;
    cin >> n >> p >> k >> a >> x >> y;
 
    int ans = INT_MAX;
    for (int i = 0; i < k; ++i) {
        int rem = 0;
        for (int j = n-i-1; j >= p-1; j -= k) {
            if (a[j] == '0') {
                rem += x;
            }
            ans = min(ans, rem + (j - p + 1) * y);
        }
    }
 
    cout << ans << ' ';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    for (cin >> t; t--; ) {
        solve();
    }
}