/**
 *     author: brownfox2k6
 *    created: Thu 28 Sep 2023 00:49:27 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define maxn 300000
#define maxa 1000001
 
int a[maxn], pf[maxa];
struct node {int64_t sum; int max;} tree[4*maxn];
 
void prep() {
    iota(pf, pf + maxa, 0);
    for (int i = 2; i*i < maxa; ++i) {
        if (pf[i] == i) {
            for (int j = i*i; j < maxa; j += i) {
                pf[j] = i;
            }
        }
    }
}
 
int divisors(int x) {
    map<int, int> cnt;
    while (x != 1) {
        ++cnt[pf[x]];
        x /= pf[x];
    }
    int ans = 1;
    for (auto p : cnt) {
        ans *= p.second + 1;
    }
    return ans;
}
 
node merge(node a, node b) {
    return {a.sum + b.sum, max(a.max, b.max)};
}
 
void build(int i, int tl, int tr) {
    if (tl == tr) {
        tree[i] = {a[tl], a[tl]};
        return;
    }
    int tm = (tl + tr) >> 1;
    build(2*i+1, tl, tm);
    build(2*i+2, tm+1, tr);
    tree[i] = merge(tree[2*i+1], tree[2*i+2]);
}
 
void modify(int i, int tl, int tr, int ql, int qr) {
    if (tree[i].max <= 2 || ql > tr || tl > qr) {
        return;
    }
    if (tl == tr) {
        int x = divisors(tree[i].sum);
        tree[i] = {x, x};
        return;
    }
    int tm = (tl + tr) >> 1;
    modify(2*i+1, tl, tm, ql, qr);
    modify(2*i+2, tm+1, tr, ql, qr);
    tree[i] = merge(tree[2*i+1], tree[2*i+2]);
}
 
int64_t query(int i, int tl, int tr, int ql, int qr) {
    if (ql <= tl && tr <= qr) {
        return tree[i].sum;
    }
    if (ql > tr || tl > qr) {
        return 0;
    }
    int tm = (tl + tr) >> 1;
    int64_t left = query(2*i+1, tl, tm, ql, qr);
    int64_t right = query(2*i+2, tm+1, tr, ql, qr);
    return left + right;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    prep();
    build(0, 0, n-1);
    while (m--) {
        int t, l, r;
        cin >> t >> l >> r;
        --l; --r;
        if (t == 1) {
            modify(0, 0, n-1, l, r);
        } else {
            cout << query(0, 0, n-1, l, r) << '\n';
        }
    }
}