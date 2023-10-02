/**
 *     author: brownfox2k6
 *    created: Thu 07 Sep 2023 21:36:00 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
void solve() {
    float a, b, c;
    cin >> a >> b >> c;
 
    if (a > b) {
        swap(a, b);
    }
 
    int cnt = 0;
    while (a != b) {
        float p = min(c, (b-a) / 2);
        a += p;
        b -= p;
        cnt++;
    }
 
    cout << cnt << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    if (mtt) {
        cin >> t;
    }
    for (int i = 1; i <= t; ++i) {
        if (dbg) {
            cout << "Testcase #" << i << '\n';
        }
        solve();
        if (dbg) {
            cout << '\n';
        }
    }
}