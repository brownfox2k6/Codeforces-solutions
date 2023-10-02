/**
 *     author: brownfox2k6
 *    created: Thu 07 Sep 2023 23:52:32 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define left(x) (x << 1)
#define right(x) ((x << 1) + 1)
#define mid(l, r) ((l + r) >> 1)
const int N = 2e5 + 5;
 
struct node {
    int one, zero;
} t[4*N];
 
bool lazy[4*N];
int n, q, a[N];
string s;
 
void build(int i, int tl, int tr) {
    lazy[i] = 0;
    if (tl == tr) {
        if (s[tl] == '1') {
            t[i].one = a[tl];
            t[i].zero = 0;
        } else {
            t[i].one = 0;
            t[i].zero = a[tl];
        }
        return;
    }
    int tm = mid(tl, tr);
    build(left(i), tl, tm);
    build(right(i), tm+1, tr);
    t[i].one = t[left(i)].one ^ t[right(i)].one;
    t[i].zero = t[left(i)].zero ^ t[right(i)].zero;
}
 
void push(int i, int tl, int tr) {
    if (lazy[i]) {
        swap(t[i].one, t[i].zero);
        if (tl != tr) {
            lazy[left(i)] ^= 1;
            lazy[right(i)] ^= 1;
        }
        lazy[i] = 0;
    }
}
 
void update(int i, int tl, int tr, int ql, int qr) {
    push(i, tl, tr);
    if (ql > tr || qr < tl) {
        return;
    }
    if (ql <= tl && qr >= tr) {
        lazy[i] ^= 1;
        push(i, tl, tr);
        return;
    }
    int tm = mid(tl, tr);
    update(left(i), tl, tm, ql, qr);
    update(right(i), tm+1, tr, ql, qr);
    t[i].one = t[left(i)].one ^ t[right(i)].one;
    t[i].zero = t[left(i)].zero ^ t[right(i)].zero;
}
 
int query(int x) {
    push(1, 1, n);
    if (x == 0) {
        return t[1].zero;
    }
    return t[1].one;
}
 
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> s;
    s = '.' + s;
 
    build(1, 1, n);
    for (cin >> q; q--; ) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l, r);
        } else {
            int g;
            cin >> g;
            cout << query(g) << ' ';
        }
    }
    cout << '\n';
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int tc;
    for (cin >> tc; tc--; ) {
        solve();
    }
}