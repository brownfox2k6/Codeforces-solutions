/**
 *     author: brownfox2k6
 *    created: Sun 24 Sep 2023 10:23:04 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    cin >> n >> m;
 
    if (n == 2 && m == 1) {
        cout << "2 2\n1 2 2";
        return 0;
    } else {
        cout << "2 998244353\n";
    }
 
    cout << "1 " << n << " 2\n";
    for (int i = 2; i <= n-2; ++i) {
        cout << "1 " << i << " 2\n";
    }
    cout << "1 " << n-1 << ' ' << 998244353 - 2*(n-2) << '\n';
 
    m -= n - 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (m == 0) {
                return 0;
            }
            cout << i << ' ' << j << ' ' << 1000000000 << '\n';
            --m;
        }
    }
}