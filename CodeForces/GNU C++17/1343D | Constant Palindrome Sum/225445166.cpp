// brownfox2k6
// 7.40 am
 
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int pref[2*k+5] = {0};
    int l = 0;
    int r = n-1;
    while (l <= r) {
        int zero = a[l] + a[r];
        int oneL = 1 + min(a[l], a[r]);
        int oneR = k + max(a[l], a[r]);
        // change 0: [zero, zero]
        // change 1: [oneL, zero-1] + [zero+1, oneR]
        // change 2: [2, oneL-1], [oneR+1, 2k]
        if (oneL <= zero-1) {
            ++pref[oneL];
            --pref[zero];
        }
        if (zero+1 <= oneR) {
            ++pref[zero+1];
            --pref[oneR+1];
        }
        if (2 <= oneL-1) {
            pref[2] += 2;
            pref[oneL] -= 2;
        }
        if (oneR+1 <= 2*k) {
            pref[oneR+1] += 2;
            pref[2*k+1] -= 2;
        }
        ++l;
        --r;
    }
    for (int i = 2; i <= 2*k; ++i) {
        pref[i] += pref[i-1];
    }
    cout << *min_element(pref+2, pref+2*k+1) << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    for (cin >> t; t--; ) {
        solve();
    }
}