/**
 *     author: brownfox2k6
 *    created: Fri 08 Sep 2023 18:21:03 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    int n;
    cin >> n;
 
    int a[n];
    for (int &x : a) {
        cin >> x;
    }
 
    int ones = count(a, a+n, 1);
    int64_t sa = accumulate(a, a+n, 0ll);
 
    if (n != 1 && sa >= ones + n) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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
        if (dbg) {
            cout << '\n';
        }
    }
}