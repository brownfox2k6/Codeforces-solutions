// brownfox2k6
// 6.50 am
 
#include <bits/stdc++.h>
using namespace std;
 
#define N 300000
struct node {
    pair<int, int> sl, sr;
    int cnt;
} tree[4*N];
string s;
 
int noofop(pair<int, int> &a) {
    return a.second - a.first;
}
 
node merge(node &a, node &b) {
    if (a.sl.first == -1) {
        return b;
    } else if (b.sl.first == -1) {
        return a;
    }
    if (b.sl.first - a.sr.second != 1) {
        return {a.sl, b.sr, a.cnt + b.cnt};
    }
    pair<int, int> leftpart = a.sl;
    pair<int, int> midpart = {a.sr.first, b.sl.second};
    pair<int, int> rightpart = b.sr;
    pair<int, int> sl, sr;
    if (midpart.first == leftpart.first && midpart.second == rightpart.second) {
        sl = midpart;
        sr = midpart;
    } else if (midpart.first == leftpart.first) {
        sl = midpart;
        sr = rightpart;
    } else if (midpart.second == rightpart.second) {
        sl = leftpart;
        sr = midpart;
    } else {
        sl = leftpart;
        sr = rightpart;
    }
    int cnt = a.cnt + b.cnt - noofop(a.sr) - noofop(b.sl) + noofop(midpart);
    return {sl, sr, cnt};
}
 
void build(int i, int tl, int tr) {
    if (tl == tr) {
        tree[i].cnt = 0;
        if (s[tl] == '.') {
            tree[i].sl = tree[i].sr = {tl, tl};
        } else {
            tree[i].sl = tree[i].sr = {-1, -1};
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    build(2*i+1, tl, tm);
    build(2*i+2, tm+1, tr);
    tree[i] = merge(tree[2*i+1], tree[2*i+2]);
}
 
void update(int i, int tl, int tr, int pos, char val) {
    if (tl == tr) {
        if (val == '.') {
            tree[i].sl = tree[i].sr = {tl, tl};
        } else {
            tree[i].sl = tree[i].sr = {-1, -1};
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(2*i+1, tl, tm, pos, val);
    } else {
        update(2*i+2, tm+1, tr, pos, val);
    }
    tree[i] = merge(tree[2*i+1], tree[2*i+2]);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m >> s;
    
    build(0, 0, n-1);
    while (m--) {
        int pos;
        char val;
        cin >> pos >> val;
        update(0, 0, n-1, pos-1, val);
        cout << tree[0].cnt << '\n';
    }
}