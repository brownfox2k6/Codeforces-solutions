// 10.31 am
// cxxdroid
 
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;
const int M = 1000000007;
 
ll bp(ll n, ll k) {
    ll ans = 1;
    while (k) {
        if (k & 1LL) {
            ans = ans * n % M;
        }
        n = n * n % M;
        k >>= 1LL;
    }
    return ans;
}
 
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    ll n, m;
    cin >> n >> m;
    cout << bp(bp(2, m) - 1, n);
}