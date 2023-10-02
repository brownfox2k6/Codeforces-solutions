/**
 *     author: brownfox2k6
 *    created: Wed 20 Sep 2023 00:03:35 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, m;
    cin >> n >> m;
 
    int a[n];
    for (int &x : a) {
        cin >> x;
    }
    sort(a, a+n);
 
    vector<int64_t> sum(m, 0);
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        sum[i % m] += a[i];
        ans += sum[i % m];
        cout << ans << ' ';
    }
}