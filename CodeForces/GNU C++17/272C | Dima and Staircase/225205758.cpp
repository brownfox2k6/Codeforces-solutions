// brownfox2k6
// 11.19 am
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
main() {
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int m, la=0, lh=0;
    for (cin >> m; m--; ) {
        int w, h;
        cin >> w >> h;
        int ans = max(a[w-1], la+lh);
        cout << ans << '\n';
        tie(la, lh) = {ans, h};
    }
}