/**
 *     author: brownfox2k6
 *    created: Tue 26 Sep 2023 22:29:22 Hanoi, Vietnam
**/
 
#include <bits/stdc++.h>
using namespace std;
 
#define N 200005
int a[N], tree[4*N];
 
void build(int i, int tl, int tr) {
    if (tl == tr) {
        tree[i] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(2*i+1, tl, tm);
    build(2*i+2, tm+1, tr);
    tree[i] = tree[2*i+1] & tree[2*i+2];
}
 
int query(int i, int tl, int tr, int ql, int qr) {
    if (ql <= tl && qr >= tr) // completely in
        return tree[i];
    if (ql > tr || qr < tl)  // completely out
        return INT_MAX;
    int tm = (tl + tr) >> 1;
    int left = query(2*i+1, tl, tm, ql, qr);
    int right = query(2*i+2, tm+1, tr, ql, qr);
    return left & right;
}
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build(0, 0, n-1);
 
    int q;
    for (cin >> q; q--; ) {
        int l, k;
        cin >> l >> k;
        int low = l - 1;
        int high = n - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (query(0, 0, n-1, l-1, mid) >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << ans + (ans >= 0) << ' ';
    }
    cout << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}