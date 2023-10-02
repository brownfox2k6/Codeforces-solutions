/**
 *     author: brownfox2k6
 *    created: Fri 08 Sep 2023 18:30:32 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    int n;
    cin >> n;
    
    int a[n+1];
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a[x] = i;
    }
 
    int k = n >> 1;
    while (k && a[k] < a[k+1] && a[n-k] < a[n-k+1]) {
        --k;
    }
 
    cout << k << '\n';
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