/**
 *     author: brownfox2k6
 *    created: Tue 29 Aug 2023 22:23:33 Hanoi, Vietnam
**/
#include <iostream>
#include <vector>
using namespace std;
 
#define int long long
 
vector<int> primeFactor(int x) {
    vector<int> pf;
    for (int i = 2; i*i <= x; ++i) {
        if (x % i == 0) {
            pf.emplace_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        pf.emplace_back(x);
    }
    return pf;
}
 
int solve() {
    int p, q;
    cin >> p >> q;
 
    if (p % q) {
        return p;
    }
    
    int ans = 0;
    for (int x : primeFactor(q)) {
        int pp = p;
        while (pp % x == 0) {
            pp /= x;
            if (pp % q) {
                ans = max(pp, ans);
                break;
            }
        }
    }
 
    return ans;
}
 
signed main() {
    int t;
    for (cin >> t; t--; ) {
        cout << solve() << '\n';
    }
}