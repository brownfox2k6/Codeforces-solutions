/**
 *     author: brownfox2k6
 *    created: Thu 31 Aug 2023 11:10:18 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<int> a(n);
    vector<bool> exist(n+1, false);
    for (int &x : a) {
        cin >> x;
        exist[x] = true;
    }
    a.emplace_back(find(exist.begin(), exist.end(), false)-exist.begin());
 
    k %= n+1;
    for (int i = n-k+1; i <= n; ++i) cout << a[i] << ' ';
    for (int i = 0; i < n-k; ++i) cout << a[i] << ' ';
    cout << '\n';
}
 
int main() {
    int t;
    for (cin >> t; t--; ) {
        solve();
    }
}