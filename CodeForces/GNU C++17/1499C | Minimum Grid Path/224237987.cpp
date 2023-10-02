// brownfox2k6
// 8.32 am
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll int64_t
 
void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    int mne = 0;
    int mno = 1;
    ll ans = (ll) n * (a[0] + a[1]);
    ll curs = (ll) a[0] + a[1];
    int no = 1;
    int ne = 1;
    for (int i = 2; i < n; ++i) {
        curs += a[i];
        if (i & 1) {
            if (a[i] < a[mno]) {
                mno = i;
            }
            ++no;
        } else {
            if (a[i] < a[mne]) {
                mne = i;
            }
            ++ne;
        }
        ans = min(ans, curs + (ll) a[mno]*(n-no) + (ll) a[mne]*(n-ne));
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