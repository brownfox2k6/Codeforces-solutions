/**
 *     author: brownfox2k6
 *    created: Wed 27 Sep 2023 20:41:51 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
vector<int> tree(524288, 1);
int k;
string s;
 
void merge(int i) {
    if (s[i] == '?') {
        tree[i] = tree[2*i+1] + tree[2*i+2];
    } else if (s[i] == '1') {
        tree[i] = tree[2*i+1];
    } else {
        tree[i] = tree[2*i+2];
    }
}
 
void build() {
    cin >> k >> s;
    reverse(s.begin(), s.end());
    for (int i = (1 << k) - 2; i >= 0; --i) {
        merge(i);
    }
}
 
void update(int p, char c) {
    p = (1 << k) - 1 - p;
    s[p] = c;
    while (p) {
        merge(p);
        p = (p - ((p + 1) & 1)) >> 1;
    }
    merge(0);
}
 
int main() {
    build();
 
    int q;
    for (cin >> q; q--; ) {
        int p;
        char c;
        cin >> p >> c;
        update(p, c);
        cout << tree[0] << '\n';
    }
}