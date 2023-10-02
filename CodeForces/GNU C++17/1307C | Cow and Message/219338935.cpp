/**
 *     author: brownfox2k6
 *    created: Thu 17 Aug 2023 23:19:32 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int64_t cnt1[26], cnt2[26][26], ans;
string s;
 
int main() {
    cin >> s;
 
    for (char c : s) {
        for (int i = 0; i < 26; ++i) {
            cnt2[i][c - 'a'] += cnt1[i];
        }
        ++cnt1[c - 'a'];
    }
 
    ans = *max_element(cnt1, cnt1 + 26);
    for (int i = 0; i < 26; ++i) {
        ans = max(ans, *max_element(cnt2[i], cnt2[i] + 26));
    }
 
    cout << ans;
}