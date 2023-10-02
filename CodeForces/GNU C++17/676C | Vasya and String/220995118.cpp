/**
 *     author: brownfox2k6
 *    created: Tue 29 Aug 2023 22:56:01 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
 
    int ans = 1;
    int l = 0;
    int r = 1;
    int ca = (s[0] == 'a');
    int cb = (s[0] == 'b');
 
    while (r < n) {
        ca += (s[r] == 'a');
        cb += (s[r] == 'b');
        while (min(ca, cb) > k) {
            ca -= (s[l] == 'a');
            cb -= (s[l] == 'b');
            ++l;
        }
        ans = max(ans, r-l+1);
        ++r;
    }
 
    cout << ans;
}