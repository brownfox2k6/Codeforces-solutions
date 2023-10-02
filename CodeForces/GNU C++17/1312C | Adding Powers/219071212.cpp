/**
 *     author: brownfox2k6
 *    created: Wed 16 Aug 2023 14:13:23 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
const int limit = 1e16;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
 
    vector<int> stock = {1};
    while (true) {
        int x = stock.back() * k;
        if (x > limit) {
            break;
        }
        stock.emplace_back(x);
    }
    
    vector<bool> taken(stock.size(), false);
    for (int &x : a) {
        while (x) {
            int p = lower_bound(stock.begin(), stock.end(), x+1) - stock.begin() - 1;
            if (taken[p]) {
                cout << "NO\n";
                return;
            }
            x -= stock[p];
            taken[p] = true;
        }
    }
    cout << "YES\n";
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    for (cin >> t; t--; ) {
        solve();
    }
}