/**
 *     author: brownfox2k6
 *    created: Tue 19 Sep 2023 00:07:14 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    int a[n];
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
 
    int ans = 0;
    for (int x : a) {
        bool ok = 0;
        for (int bit = 0; bit <= 30; ++bit) {
            int y = (1 << bit) - x;
            if (cnt.count(y) && (cnt[y] > 1 || x != y)) {
                ok = 1;
                break;
            }
        }
        ans += (!ok);
    }
 
    cout << ans;
}