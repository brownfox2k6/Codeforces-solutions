/**
 *     author: brownfox2k6
 *    created: Sun 17 Sep 2023 11:52:59 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007
 
int mul(int a, int b) {
    return (ll) a * b % mod;
}
 
int bp(int n, int k) {
    int ans = 1;
    while (k) {
        if (k & 1) {
            ans = mul(ans, n);
        }
        n = mul(n, n);
        k >>= 1;
    }
    return ans;
}
 
int fac(int n) {
    int ans = 1;
    for (int i = 2; i <= n; ++i) {
        ans = mul(ans, i);
    }
    return ans;
}
 
main() {
    int n;
    cin >> n;
    int ans = fac(n) - bp(2, n-1);
    if (ans < 0) {
        ans += mod;
    }
    cout << ans;
}