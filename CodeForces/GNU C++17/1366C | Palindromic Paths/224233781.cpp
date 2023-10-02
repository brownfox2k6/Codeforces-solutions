// brownfox2k6
// 7.56 am
 
#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int zero, one;
};
 
void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<node> v(n+m-1, {0, 0});
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                ++v[i+j].one;
            } else {
                ++v[i+j].zero;
            }
        }
    }
    
    int i = 0;
    int j = n+m-2;
    int ans = 0;
    while (i < j) {
        ans += min(v[i].one + v[j].one,
                   v[i].zero + v[j].zero);
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
        // cout << "\n---\n";
        solve();
    }
}