// brownfox2k6
// 8.32 am
 
#include <bits/stdc++.h>
using namespace std;
 
#define finp 0
#define N 105
#define MOD 1000000007
 
int dp[N][2];
int n, k, d;
 
int f(int target, bool ok) {
 if (target == 0 && ok) return 1;
 if (target < 0) return 0;
 if (dp[target][ok] != -1) {
  return dp[target][ok];
 }
 int ans = 0;
 for (int i = 1; i <= k; ++i) {
  ans += f(target - i, ok || i >= d);
  ans %= MOD;
 }
 return dp[target][ok] = ans;
}
 
int main() {
 cin.tie(0)->sync_with_stdio(0);
 if (finp) {
  freopen("inp.txt", "r", stdin);
 }
 
 memset(dp, -1, sizeof dp);
 
 cin >> n >> k >> d;
 cout << f(n, 0);
}