/**
 *     author: brownfox2k6
 *    created: Fri 15 Sep 2023 21:11:48 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    for (int i = a*10; i <= a*10+9; ++i) {
        if (i % b == 0) {
            cout << i << string(n-1, '0');
            return;
        }
    }
    cout << -1;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}