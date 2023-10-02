// brownfox2k6
// 8.24 am
 
#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int abc, acb, bac, bca, cab, cba;
} dp[200005];
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    string s;
    cin >> n >> m >> s;
    
    dp[0] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < n; ++i) {
        dp[i+1].abc = dp[i].abc + (s[i] == "abc"[i % 3]);
        dp[i+1].acb = dp[i].acb + (s[i] == "acb"[i % 3]);
        dp[i+1].bac = dp[i].bac + (s[i] == "bac"[i % 3]);
        dp[i+1].bca = dp[i].bca + (s[i] == "bca"[i % 3]);
        dp[i+1].cab = dp[i].cab + (s[i] == "cab"[i % 3]);
        dp[i+1].cba = dp[i].cba + (s[i] == "cba"[i % 3]);
    }
    
    while (m--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int maxmatch = max({
            dp[r].abc - dp[l-1].abc,
            dp[r].acb - dp[l-1].acb,
            dp[r].bac - dp[l-1].bac,
            dp[r].bca - dp[l-1].bca,
            dp[r].cab - dp[l-1].cab,
            dp[r].cba - dp[l-1].cba
        });
        cout << len - maxmatch << '\n';
    }
}