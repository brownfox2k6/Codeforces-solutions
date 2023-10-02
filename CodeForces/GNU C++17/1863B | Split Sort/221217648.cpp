/**
 *     author: brownfox2k6
 *    created: Thu 31 Aug 2023 10:59:59 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int t, n, x, ans;
int a[100001];
 
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        a[x] = i;
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (a[i] < a[i-1]);
    }
    cout << ans << '\n';
}
 
int main() {
    for (cin >> t; t--; ) solve();
}