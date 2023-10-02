/**
 *     author: brownfox2k6
 *    created: Sun 17 Sep 2023 11:33:07 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
main() {
    int n, m;
    cin >> n >> m;
 
    string a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int ans = 0;
    for (int x1 = 0; x1 < n; ++x1) {
        for (int y1 = 0; y1 < m; ++y1) {
            for (int x2 = x1; x2 < n; ++x2) {
                for (int y2 = y1; y2 < m; ++y2) {
                    bool ok = 1;
                    for (int i = x1; i <= x2 && ok; ++i) {
                        for (int j = y1; j <= y2 && ok; ++j) {
                            ok &= a[i][j] == '0';
                        }
                    }
                    if (ok) {
                        ans = max(ans, x2-x1+1 + y2-y1+1);
                    }
                }
            } 
        }
    }
 
    cout << 2*ans;
}