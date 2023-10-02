/**
 *     author: brownfox2k6
 *    created: Sat 19 Aug 2023 14:31:13 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int n, q, l, r, a[100005];
 
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for (cin >> q; q--; ) {
        cin >> l >> r;
        cout << (a[r] - a[l-1]) / 10 << '\n';
    }
}