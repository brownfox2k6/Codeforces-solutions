// brownfox2k6
// 8.25 am
 
#include <bits/stdc++.h>
using namespace std;
 
int tree[400000];
string s;
 
void build(int i, int tl, int tr) {
    if (tl == tr) {
        tree[i] = 1 << (s[tl] - 'a');
        return;
    }
    int tm = (tl + tr) >> 1;
    build(2*i+1, tl, tm);
    build(2*i+2, tm+1, tr);
    tree[i] = tree[2*i+1] | tree[2*i+2];
}
 
void update(int i, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[i] = 1 << val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(2*i+1, tl, tm, pos, val);
    } else {
        update(2*i+2, tm+1, tr, pos, val);
    }
    tree[i] = tree[2*i+1] | tree[2*i+2];
}
 
int query(int i, int tl, int tr, int ql, int qr) {
    if (ql <= tl && tr <= qr) {
        return tree[i];
    }
    if (qr < tl || ql > tr) {
        return 0;
    }
    int tm = (tl + tr) >> 1;
    int left = query(2*i+1, tl, tm, ql, qr);
    int right = query(2*i+2, tm+1, tr, ql, qr);
    return left | right;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> s;
    int n = s.length();
    
    build(0, 0, n-1);
    
    int t;
    for (cin >> t; t--; ) {
        int q;
        cin >> q;
        if (q == 1) {
            int pos;
            char val;
            cin >> pos >> val;
            update(0, 0, n-1, pos-1, val-'a');
        } else {
            int l, r;
            cin >> l >> r;
            int ans = query(0, 0, n-1, l-1, r-1);
            cout << __builtin_popcount(ans) << '\n';
        }
    }
}