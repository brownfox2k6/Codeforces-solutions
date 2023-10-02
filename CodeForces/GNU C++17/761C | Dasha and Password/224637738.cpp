/**
 *     author: brownfox2k6
 *    created: Fri 22 Sep 2023 21:41:57 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define inf 1000000
 
struct line {
    int digit = inf;
    int letter = inf;
    int special = inf;
};
 
int main() {
    int n, m;
    cin >> n >> m;
 
    line a[n], b[n];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if ('0' <= s[j] && s[j] <= '9') {
                a[i].digit = min(a[i].digit, j);
                b[i].digit = min(b[i].digit, m - j);
            } else if ('a' <= s[j] && s[j] <= 'z') {
                a[i].letter = min(a[i].letter, j);
                b[i].letter = min(b[i].letter, m - j);
            } else {
                a[i].special = min(a[i].special, j);
                b[i].special = min(b[i].special, m - j);
            }
        }
    }
 
    int ans = inf;
    for (int takeDigit = 0; takeDigit < n; ++takeDigit) {
        for (int takeLetter = 0; takeLetter < n; ++takeLetter) {
            if (takeLetter == takeDigit) {
                continue;
            }
            for (int takeSpecial = 0; takeSpecial < n; ++takeSpecial) {
                if (takeSpecial == takeLetter || takeSpecial == takeDigit) {
                    continue;
                }
                ans = min(ans,    min(a[takeDigit].digit, b[takeDigit].digit)
                                + min(a[takeLetter].letter, b[takeLetter].letter)
                                + min(a[takeSpecial].special, b[takeSpecial].special));
            }
        }
    }
 
    cout << ans;
}