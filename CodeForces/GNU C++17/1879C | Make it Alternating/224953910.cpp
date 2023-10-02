/**
 *     author: brownfox2k6
 *    created: Sun 24 Sep 2023 21:51:57 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define mtt 1
#define dbg 0
#define mod 998244353
#define N 200005
 
int fac[N];
 
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> v = {1};
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) {
            v.emplace_back(1);
        } else {
            ++v.back();
        }
    }
 
    if (dbg) {
        for (int x : v) cout << x << ' ';
        cout << '\n';
    }
 
    int m = v.size();
    int noofop = 0;
    int ans = 1;
    for (int i = 0; i < m; ++i) {
        if (v[i] > 1) {
            noofop += v[i] - 1;
            ans = ans * v[i] % mod;
        }
    }
 
    ans = ans * fac[noofop] % mod;
 
    cout << noofop << ' ' << ans << '\n';
}
 
void prep() {
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i < N; ++i) {
        fac[i] = fac[i-1] * i % mod;
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    prep();
 
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