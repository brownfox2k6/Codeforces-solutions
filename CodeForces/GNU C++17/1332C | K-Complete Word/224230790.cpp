// brownfox2k6
// 6.53 am
 
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    vector<string> v;
    for (int i = 0; i < n; i += k) {
        v.emplace_back(s.substr(i, k));
    }
 
    int ans = 0;
    int i = 0;
    int j = k-1;
    while (i <= j) {
        int occ[26] = {0};
        for (string x : v) {
            ++occ[x[i] - 'a'];
            if (i != j) {
                ++occ[x[j] - 'a'];
            } 
        }
        int mx = *max_element(occ, occ+26);
        if (i == j) {
            ans += n/k - mx;
        } else {
            ans += 2*n/k - mx;
        }
        ++i;
        --j;
    }
    
    cout << ans << '\n';
}
 
 
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}