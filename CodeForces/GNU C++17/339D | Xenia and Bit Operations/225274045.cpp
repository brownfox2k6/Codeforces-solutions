/**
 *     author: brownfox2k6
 *    created: Tue 26 Sep 2023 21:05:26 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int tree[524300];
int n, m;
 
void build() {
    cin >> n >> m;
    for (int i = (1 << n) - 1; i < (1 << (n+1)) - 1; ++i) {
        cin >> tree[i];
    }
    for (int row = n; row >= 1; --row) {
        for (int i = (1 << row) - 1; i < (1 << (row+1)) - 1; i += 2) {
            if ((n - row) & 1) {
                tree[i >> 1] = tree[i] ^ tree[i+1];
            } else {
                tree[i >> 1] = tree[i] | tree[i+1];
            }
        }
    }
}
 
void update(int p, int x) {
    p = (1 << n) + p - 2;
    tree[p] = x;
    for (int row = n; row >= 1; --row) {
        if (p % 2 == 0) {
            --p;
        }
        if ((n - row) & 1) {
            tree[p >> 1] = tree[p] ^ tree[p+1];
        } else {
            tree[p >> 1] = tree[p] | tree[p+1];
        }
        p >>= 1;
    }
}
 
int main() {
    build();
 
    while (m--) {
        int p, x;
        cin >> p >> x;
        update(p, x);
        cout << tree[0] << '\n';
    }
}