// 8.05 am
// cxxdroid
 
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
 
int C(int i, int j) {
    return (i + j - 1) / j;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int a, c, d, m, n, k;
    cin >> c >> d >> n >> m >> k;
 
    int need = n*m - k;
    
    // take only main
    int f = c * C(need, n);
    
    // take main and additional
    int rem = need % n;
    int s = c * (need / n) + d*rem;
    
    // take only additional
    int t = d * need;
    
    
    // cout << min({f, s, t});
    cout << max(0, min(f, min(s, t)));
}