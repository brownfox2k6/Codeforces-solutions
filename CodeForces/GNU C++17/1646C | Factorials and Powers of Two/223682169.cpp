/**
 *     author: brownfox2k6
 *    created: Sun 17 Sep 2023 10:36:22 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
 
vector<int> fac = {6};
int t, x, ans, s, c;
 
pair<int, int> getcompo(int x) {
    int sum = 0;
    int cnt = 0;
    for (int bit = 0; x; ++bit) {
        if (x & 1) {
            sum += fac[bit];
            ++cnt;
        }
        x >>= 1;
    }
    return {sum, cnt};
}
 
main() {
    for (int i = 4; i <= 14; ++i) {
        fac.emplace_back(fac.back() * i);
    }
 
    for (cin >> t; t--; ) {
        ans = INT_MAX;
        cin >> x;
        for (int i = 0; i < 4096; ++i) {
            tie(s, c) = getcompo(i);
            ans = min(ans, c + __builtin_popcountll(x - s));
        }
        cout << ans << '\n';
    }
}