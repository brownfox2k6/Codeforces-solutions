/**
 *     author: brownfox2k6
 *    created: Thu 07 Sep 2023 21:36:00 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
bool prime(int x) {
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return x >= 2;
}
 
void solve() {
    int l, r;
    cin >> l >> r;
 
    int ok = 0;
    for (int i = max(2, l); i <= r; ++i) {
        if (!prime(i)) {
            ok = i;
            break;
        }
    }
 
    // cout << ok;
    if (!ok) {
        cout << -1;
        return;
    }
 
    int a = 2;
    int b = ok - 2;
    while (a <= b) {
        if (__gcd(a, b) != 1) {
            cout << a << ' ' << b;
            return;
        }
        ++a;
        --b;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    if (mtt) {
        cin >> t;
    }
    for (int i = 1; i <= t; ++i) {
        if (dbg) {
            cout << "Testcase #" << i << '\n';
        }
        solve();
        cout << '\n';
        if (dbg) {
            cout << '\n';
        }
    }
}