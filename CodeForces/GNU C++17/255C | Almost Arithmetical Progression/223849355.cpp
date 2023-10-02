/**
 *     author: brownfox2k6
 *    created: Mon 18 Sep 2023 20:51:29 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    map<int, int> mp;
    int ind = 0;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (!mp.count(a[i])) {
            mp[a[i]] = ind++;
        }
        a[i] = mp[a[i]];
    }
 
    int ans = 1;
    vector dp(n, vector(n, 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i][a[j]] = max(1 + dp[j][a[i]], dp[i][a[j]]);
            ans = max(ans, dp[i][a[j]]);
        }
    }
 
    cout << ans;
}