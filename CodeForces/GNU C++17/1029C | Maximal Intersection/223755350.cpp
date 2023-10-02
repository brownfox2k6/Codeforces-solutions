/**
 *     author: brownfox2k6
 *    created: Sun 17 Sep 2023 23:38:09 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define N 300005
int L[N], R[N], prefL[N], prefR[N], sufL[N], sufR[N];
int ans;
 
main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n;
    cin >> n;
 
    for (int i = 1; i <= n; ++i) {
        cin >> L[i] >> R[i];
    }
 
    prefL[0] = 0;
    prefR[0] = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        prefL[i] = max(prefL[i-1], L[i]);
        prefR[i] = min(prefR[i-1], R[i]);
    }
 
    sufL[n+1] = 0;
    sufR[n+1] = INT_MAX;
    for (int i = n; i >= 1; --i) {
        sufL[i] = max(sufL[i+1], L[i]);
        sufR[i] = min(sufR[i+1], R[i]);
    }
 
    // for (int i = 0; i < n+2; ++i) cout << prefL[i] << " \n"[i == n+1];
    // for (int i = 0; i < n+2; ++i) cout << sufL[i] << " \n"[i == n+1];
    // for (int i = 0; i < n+2; ++i) cout << prefR[i] << " \n"[i == n+1];
    // for (int i = 0; i < n+2; ++i) cout << sufR[i] << " \n"[i == n+1];
 
    // max of L, min of R on the 1st part: prefL, prefR
    // max of L, min of R on the 2nd part: sufL, sufR
 
    // try to remove the i-th segment
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, min(prefR[i-1], sufR[i+1]) - max(prefL[i-1], sufL[i+1]));
    }
 
    cout << ans;
}