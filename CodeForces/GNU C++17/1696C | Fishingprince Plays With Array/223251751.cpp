/**
 *     author: brownfox2k6
 *    created: Wed 13 Sep 2023 23:46:52 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
bool ok(int &va, int &oa, int &vb, int &ob, int &k) {
    while (va % k == 0) {
        va /= k;
        oa *= k;
    }
    while (vb % k == 0) {
        vb /= k;
        ob *= k;
    }
    if (va != vb) {
        return 0;
    }
    if (oa > ob) {
        tie(oa, ob) = make_pair(oa-ob, 0);
    } else {
        tie(oa, ob) = make_pair(0, ob-oa);
    }
    return 1;
}
 
void solve() {
    int la, k;
    cin >> la >> k;
    vector<int> a(la);
    for (int &x : a) {
        cin >> x;
    }
    int lb;
    cin >> lb;
    vector<int> b(lb);
    for (int &x : b) {
        cin >> x;
    }
 
    int pa=0, pb=0, va=0, vb=0, oa=0, ob=0;
    while (pa < la && pb < lb) {
        if (oa == 0) {
            tie(va, oa) = make_pair(a[pa], 1);
        }
        if (ob == 0) {
            tie(vb, ob) = make_pair(b[pb], 1);
        }
        if (!ok(va, oa, vb, ob, k)) {
            cout << "No\n";
            return;
        }
        if (oa == 0) {
            ++pa;
        }
        if (ob == 0) {
            ++pb;
        }
    }
 
    if (pa != la || pb != lb) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
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