/**
 *     author: brownfox2k6
 *    created: Wed 20 Sep 2023 18:52:47 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int n, k, z;
vector<int> a;
map<tuple<int, int, int, bool>, int> dp;
 
int f(int ind=0, int moves=k+1, int leftmoves=z, bool cangoleft=0) {
    if (moves == 0) {
        return 0;
    }
    if (dp.count({ind, moves, leftmoves, cangoleft})) {
        return dp[{ind, moves, leftmoves, cangoleft}];
    }
    int goleft = INT_MIN;
    if (ind && leftmoves && cangoleft) {
        goleft = a[ind] + f(ind-1, moves-1, leftmoves-1, 0);
    }
    int goright = INT_MIN;
    if (ind < n) {
        goright = a[ind] + f(ind+1, moves-1, leftmoves, 1);
    }
    return dp[{ind, moves, leftmoves, cangoleft}] = max(goleft, goright);
}
 
void solve() {
    cin >> n >> k >> z;
 
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    cout << f() << '\n';
    dp.clear();
}
 
 
 
#define mtt true
#define dbg false
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    if (mtt) {
        cin >> t;
    }
    for (int i = 1; i <= t; ++i) {
        if (dbg) {
            cout << "Testcase #" << i << '\n';
        }
        solve();
        if (dbg) {
            cout << '\n';
        }
    }
}