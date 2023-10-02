/**
 *     author: brownfox2k6
 *    created: Fri 15 Sep 2023 21:11:48 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll n;
ll coe[3], a[100005];
pair<bool, ll> memo[100005][3];
 
ll f(int ind, int taken) {
    if (ind == n) {
        return LLONG_MIN;
    }
    if (taken == 3) {
        return 0;
    }
    if (memo[ind][taken].first) {
        return memo[ind][taken].second;
    }
    ll take = coe[taken]*a[ind] + f(ind, taken+1);
    ll notTake = f(ind+1, taken);
    memo[ind][taken] = {true, max(take, notTake)};
    return memo[ind][taken].second;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
 
    cin >> n >> coe[0] >> coe[1] >> coe[2];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    cout << f(0, 0);
}