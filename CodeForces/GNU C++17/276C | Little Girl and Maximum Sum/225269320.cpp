/**
 *     author: brownfox2k6
 *    created: Tue 26 Sep 2023 20:52:31 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define N 200005
int a[N], b[N];
int n, q, l, r;
 
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    while (q--) {
        cin >> l >> r;
        ++b[l];
        --b[r+1];
    }
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i-1];
    }
    sort(b+1, b+n+1);
    sort(a+1, a+n+1);
    int64_t ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (int64_t) b[i] * a[i];
    }
    cout << ans;
}