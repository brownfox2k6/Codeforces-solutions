// brownfox2k6
// 10.08 am
 
#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
 
void solve() {
    int n;
    cin >> n;
 
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    
    int pref[n+1];
    pref[0] = 0;
    for (int i = 0; i < n; ++i) {
        pref[i+1] = pref[i] + v[i].first;       
    }
    
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        int x = v[i].first;
        int power = ((x+1)*i - pref[i]) + 1 + (pref[n]-pref[i+1] - (x-1)*(n-i-1));
        ans[v[i].second] = power;
    }
    
    for (int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
 
 
 
 
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        // cout << "\n---\n";
        solve();
    }
}