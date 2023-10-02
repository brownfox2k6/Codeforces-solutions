/**
 *     author: brownfox2k6
 *    created: Sun 24 Sep 2023 13:02:44 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define m 1000000007
 
int main() {
    string s;
    cin >> s;
    vector<int> v = {0};
 
    for (char c : s) {
        if (c == 'a') {
            ++v.back();
        } else if (c == 'b' && v.back()) {
            v.emplace_back(0);
        }
    }
 
    int64_t ans = 1;
    for (int x : v) {
        ans = ans * (x+1) % m;
    }
 
    if (--ans == -1) {
        ans += m;
    }
 
    cout << ans;
}