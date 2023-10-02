// brownfox2k6
// 8.23 am
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    pair<int, int> lastq1[n];
    for (int i = 0; i < n; ++i) {
        cin >> lastq1[i].first;
        lastq1[i].second = 0;
    }
    
    int m;
    cin >> m;
    int lastq2[m+1];
    memset(lastq2, 128, sizeof lastq2);
    for (int i = 1; i <= m; ++i) {
        int t, p, x;
        cin >> t;
        if (t == 1) {
            cin >> p >> x;
            lastq1[p-1] = {x, i};
        } else {
            cin >> x;
            lastq2[i] = x;
        }
    }
    
    for (int i = m-1; i >= 0; --i) {
        lastq2[i] = max(lastq2[i+1], lastq2[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        cout << max(lastq1[i].first, lastq2[lastq1[i].second]) << ' ';
    }
}