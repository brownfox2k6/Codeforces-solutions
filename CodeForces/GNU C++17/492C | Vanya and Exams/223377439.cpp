/**
 *     author: brownfox2k6
 *    created: Thu 14 Sep 2023 22:48:16 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
signed main() {
    int n, r, avg;
    cin >> n >> r >> avg;
 
    pair<int, int> p[n];
    int totalp = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        p[i] = {b, r-a};
        totalp += a;
    }
 
    sort(p, p+n);
    int need = max(0LL, avg*n - totalp);
    int ans = 0;
    for (int i = 0; i < n && need > 0; ++i) {
        int y = min(need, p[i].second);
        ans += y * p[i].first;
        need -= y;
    }
 
    cout << ans;
}