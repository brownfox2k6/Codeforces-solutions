/**
 *     author: brownfox2k6
 *    created: Sun 27 Aug 2023 10:51:20 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    for (cin >> t; t--; ) {
        int n;
        cin >> n;
        vector<int> ans = {n};
        int p2;
        for (int b = 0; ; ++b) {
            if ((n >> b) & 1) {
                if (n == (1 << b)) {
                    p2 = b;
                    break;
                }
                n -= 1 << b;
                ans.emplace_back(n);
            }
        }
        while (p2) {
            n -= 1 << --p2;
            ans.emplace_back(n);
        }
        cout << ans.size() << '\n';
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}