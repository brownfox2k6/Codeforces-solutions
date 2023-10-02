/**
 *     author: brownfox2k6
 *    created: Wed 27 Sep 2023 22:22:33 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define N 200005
#define l first
#define r second
 
struct node {
    pair<int, int> sl, sr;
    int64_t cnt;
} tree[4*N];
 
int a[N];
 
int64_t noofsegs(pair<int, int> seg) {
    int len = seg.r - seg.l + 1;
    return (int64_t) len * (len+1) / 2;
}
 
node merge(node left, node right) {
    if (left.cnt == -1) {
        return right;
    }
    if (right.cnt == -1) {
        return left;
    }
    if (a[left.sr.r] > a[right.sl.l]) {
        return {left.sl, right.sr, left.cnt + right.cnt};
    }
 
    pair<int, int> leftpart = left.sl;
    pair<int, int> midpart = {left.sr.l, right.sl.r};
    pair<int, int> rightpart = right.sr;
    pair<int, int> sl, sr;
 
    if (midpart.l == leftpart.l && midpart.r == rightpart.r) {
        sl = midpart;
        sr = midpart;
    } else if (midpart.l == leftpart.l) {
        sl = midpart;
        sr = rightpart;
    } else if (midpart.r == rightpart.r) {
        sl = leftpart;
        sr = midpart;
    } else {
        sl = leftpart;
        sr = rightpart;
    }
 
    return {sl, sr, left.cnt + right.cnt - noofsegs(left.sr) - noofsegs(right.sl) + noofsegs(midpart)};
}
 
void build(int i, int tl, int tr) {
    if (tl == tr) {
        tree[i] = {{tl, tl}, {tl, tl}, 1};
        return;
    }
    int tm = (tl + tr) >> 1;
    build(2*i+1, tl, tm);
    build(2*i+2, tm+1, tr);
    tree[i] = merge(tree[2*i+1], tree[2*i+2]);
}
 
void update(int i, int pos, int val) {
    if (tree[i].sl.l == tree[i].sr.r) {
        return;
    }
    if (pos <= tree[2*i+1].sr.r) {
        update(2*i+1, pos, val);
    } else {
        update(2*i+2, pos, val);
    }
    tree[i] = merge(tree[2*i+1], tree[2*i+2]);
}
 
node query(int i, int ql, int qr) {
    if (ql <= tree[i].sl.l && tree[i].sr.r <= qr) {
        return tree[i];
    }
    if (qr < tree[i].sl.l || ql > tree[i].sr.r) {
        return {{0, 0}, {0, 0}, -1};
    }
    node left = query(2*i+1, ql, qr);
    node right = query(2*i+2, ql, qr);
    return merge(left, right);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    build(0, 0, n-1);
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            a[x-1] = y;
            update(0, x-1, y);
        } else {
            cout << query(0, x-1, y-1).cnt << '\n';
        }
    }
}