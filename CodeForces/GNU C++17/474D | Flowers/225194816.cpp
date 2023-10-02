// brownfox2k6
// 8.10 am
 
#include <bits/stdc++.h>
using namespace std;
 
#define N 100005
#define MOD 1000000007
 
int main() {
    int t, k;
    cin >> t >> k;
    
    int dp[N];
    fill(dp, dp+k, 1);
    for (int i = k; i < N; ++i) {
        dp[i] = (dp[i-1] + dp[i-k]) % MOD;
    }
    
    int p[N];
    p[0] = 0;
    for (int i = 1; i < N; ++i) {
        p[i] = (p[i-1] + dp[i]) % MOD;
    }
    
    while (t--) {
        int l, r;
        cin >> l >> r;
        int ans = p[r] - p[l-1];
        if (ans < 0) {
            ans += MOD;
        }
        cout << ans << '\n';
    }
}