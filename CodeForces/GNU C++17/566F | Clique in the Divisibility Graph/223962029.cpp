// 7.24 am
// cxxdroid
 
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
 
int dp[1000001];
int n, a;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for (cin >> n; n--; ) {
        int x;
        cin >> x;
        ++dp[x];
        a = max(a, dp[x]);
        for (int i = 2*x; i <= 1000000; i += x) {
            dp[i] = max(dp[i], dp[x]);
        }
    }
    
    cout << a;
}