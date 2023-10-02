/**
 *     author: brownfox2k6
 *    created: Fri 08 Sep 2023 19:05:01 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mod 998244353
 
int bpow(int n, int k) {
    int ans = 1;
    while (k) {
        if (k & 1) {
            ans = ans * n % mod;
        }
        n = n * n % mod;
        k >>= 1;
    }
    return ans;
}
 
main() {
    int w, h;
    cin >> w >> h;
    cout << bpow(2, w+h);
}