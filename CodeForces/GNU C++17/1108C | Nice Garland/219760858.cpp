/**
 *     author: brownfox2k6
 *    created: Mon 21 Aug 2023 14:56:07 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    string s;
    cin >> n >> s;
 
    int ans = 10000000;
    string strans;
    for (string t : {"RGB", "RBG", "GRB", "GBR", "BGR", "BRG"}) {
        int changes = 0;
        for (int i = 0; i < n; ++i) {
            changes += s[i] != t[i % 3];
        }
        if (changes < ans) {
            ans = changes;
            strans = t;
        }
    }
 
    cout << ans << '\n';
    for (int i = 0; i < n; ++i) {
        cout << strans[i % 3];
    }
}