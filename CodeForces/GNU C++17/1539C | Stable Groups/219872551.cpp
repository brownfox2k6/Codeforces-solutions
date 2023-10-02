/**
 *     author: brownfox2k6
 *    created: Tue 22 Aug 2023 13:02:53 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
// equivalent to ceil(1.0 * n / k)
int ceildiv(int n, int k) {
    return (n + k - 1) / k;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, k, x;
    cin >> n >> k >> x;
    int a[n];
    for (int &i : a) {
        cin >> i;
    }
 
    sort(a, a+n);
    vector<int> v;
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i-1] > x) {
            v.emplace_back(ceildiv(a[i] - a[i-1], x) - 1);
            ++ans;
        }
    }
 
    sort(v.begin(), v.end());
    for (int i : v) {
        if (i <= k) {
            --ans;
            k -= i;
        } else {
            break;
        }
    }
 
    cout << ans;
}