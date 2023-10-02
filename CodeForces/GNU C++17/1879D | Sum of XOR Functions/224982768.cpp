/**
 *     author: brownfox2k6
 *    created: Mon 25 Sep 2023 00:04:37 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mod 998244353
 
signed main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    int ans = 0;
    for (int b = 0; b < 30; ++b) {
        int curbit = 1 << b;
        int cnt[2] = {1, 0};
        int sum[2] = {0, 0};
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] & curbit) {
                cur ^= 1;
            }
            ++cnt[cur];
            sum[cur] += i + 1;
            int curval = (cnt[cur^1] * (i+1) - sum[cur^1]) % mod;
            (ans += (curval * curbit)) %= mod;
        }
    }
 
    cout << ans;
}