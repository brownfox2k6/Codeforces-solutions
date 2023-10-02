// brownfox2k6
// 7.30 am
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define vtiii vector<tuple<int, int, int>>
#define N 500003
 
int tree[4*N];
int n, a[N];
 
vtiii v;
vtiii ans;
int curmax = LLONG_MIN;
 
 
void Build(int i=0, int tl=0, int tr=n-1) {
    if (tl == tr) {
        tree[i] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    Build(2*i+1, tl, tm);
    Build(2*i+2, tm+1, tr);
    tree[i] = min(tree[2*i+1], tree[2*i+2]);
}
 
pair<int, int> Query(int i, int tl, int tr, int ql, int qr) {
    if (ql > tr || qr < tl) {
        return {INT_MAX, -1};
    }
    if (tl == tr) {
        return {tree[i], tl};
    }
    int tm = (tl + tr) >> 1;
    pair<int, int> left = Query(2*i+1, tl, tm, ql, qr);
    pair<int, int> right = Query(2*i+2, tm+1, tr, ql, qr);
    return min(left, right);
}
 
 
void f(int l=0, int r=n-1, int totval=0) {
    if (l > r) {
        if (totval >= curmax) {
            ans = v;
            curmax = totval;
        }
        return;
    }
    int imin = Query(0, 0, n-1, l, r).second;
    v.emplace_back(l, imin, a[imin]);
    f(imin+1, r, totval + a[imin]*(imin-l+1));
    v.pop_back();
    v.emplace_back(imin, r, a[imin]);
    f(l, imin-1, totval + a[imin]*(r-imin+1));
    v.pop_back();
}
 
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    Build();
    f();
    
    for (auto [L, R, V] : ans) {
        for (int i = L; i <= R; ++i) {
            a[i] = V;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}