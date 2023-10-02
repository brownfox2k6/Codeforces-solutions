/**
 *     author: brownfox2k6
 *    created: Sun 27 Aug 2023 11:03:23 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define int int64_t
 
// count how many numbers in [l, r] which % 3 = mod
int cnt(int l, int r, int mod) {
    while (l % 3 != mod) {
        ++l;
    }
    while (r % 3 != mod) {
        --r;
        if (l > r) {
            return 0;
        }
    }
    return (r - l) / 3 + 1;
}
 
signed main() {
    int n, l, r;
    cin >> n >> l >> r;
 
    int c0 = cnt(l, r, 0);
    int c1 = cnt(l, r, 1);
    int c2 = cnt(l, r, 2);
    
    vector<int> prev = {1, 0, 0};
    for (int i = 1; i <= n; ++i) {
        vector<int> cur(3);
        cur[0] = (c0*prev[0] + c1*prev[2] + c2*prev[1]) % MOD;
        cur[1] = (c0*prev[1] + c1*prev[0] + c2*prev[2]) % MOD;
        cur[2] = (c0*prev[2] + c1*prev[1] + c2*prev[0]) % MOD;
        prev = cur;
    }
    cout << prev[0];
}