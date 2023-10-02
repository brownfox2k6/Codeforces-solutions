/**
 *     author: brownfox2k6
 *    created: Mon 21 Aug 2023 14:49:21 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    string s;
    s += '.';
    cin >> n >> s;
 
    int changes = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            for (char c : "RGB") {
                if (c != s[i-1] && c != s[i+1]) {
                    s[i] = c;
                    break;
                }
            }
            ++changes;
        }
    }
 
    cout << changes << '\n' << s;
}