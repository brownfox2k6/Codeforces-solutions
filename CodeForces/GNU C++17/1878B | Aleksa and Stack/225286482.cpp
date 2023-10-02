/**
 *     author: brownfox2k6
 *    created: Tue 26 Sep 2023 21:39:59 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
vector<int> a(200005);
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    a[0] = 1;
    a[1] = 3;
    for (int i = 2; i < 200005; ++i) {
        for (int j = a[i-1] + 1; ; ++j) {
            if (3 * j % (a[i-1] + a[i-2])) {
                a[i] = j;
                break;
            }
        }
    }
 
    int t;
    for (cin >> t; t--; ) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}