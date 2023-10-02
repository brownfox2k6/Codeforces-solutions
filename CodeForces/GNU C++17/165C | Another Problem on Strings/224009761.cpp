/**
 *     author: brownfox2k6
 *    created: Tue 19 Sep 2023 15:25:10 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int k;
    string s;
    cin >> k >> s;
 
    vector<int> v = {1};
    for (char c : s) {
        if (c == '1') {
            v.emplace_back(1);
        } else {
            ++v.back();
        }
    }
 
    int64_t ans = 0;
 
    if (k == 0) {
        for (int x : v) {
            ans += (int64_t) x * (x-1) >> 1LL;
        }
    } else {
        for (int i = 0; i < (int)v.size()-k; ++i) {
            ans += (int64_t) v[i] * v[i+k];
        }
    }
        
    cout << ans;
}