// brownfox2k6
// 7.18 am
 
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    vector<string> v;
    for (int i = 0; i < n; i += k) {
        v.emplace_back(s.substr(i, k));
    }
 
    string col(k, '?');
    for (string x : v) {
        for (int i = 0; i < x.length(); ++i) {
            if (x[i] == '?') {
                continue;
            } else if (col[i] == '?') {
                col[i] = x[i];
            } else if (col[i] != x[i]) {
                cout << "NO\n";
                return;
            }
        }
    }
    
    int one=0, zero=0, que=0;
    for (char c : col) {
        one += (c == '1');
        zero += (c == '0');
        que += (c == '?');
    }
    
    int rem = que - abs(zero - one);
    if (rem < 0 || rem & 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
 
 
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        // cout << "\n---\n";
        solve();
    }
}