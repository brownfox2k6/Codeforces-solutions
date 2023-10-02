/**
 *     author: brownfox2k6
 *    created: Tue 26 Sep 2023 22:29:22 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define mtt true
#define dbg false
 
pair<int, int> findseg(pair<int, int> a[], int k, int x) {
    int low = 0;
    int high = k - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (a[mid].first <= x && x <= a[mid].second) {
            return a[mid];
        }
        else if (x < a[mid].first) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << "????????????";
    return {-1, -1};
}
 
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    pair<int, int> a[k];
    for (int i = 0; i < k; ++i) cin >> a[i].first;
    for (int i = 0; i < k; ++i) cin >> a[i].second;
 
    int q;
 
    int pref[n+1] = {0};
 
    for (cin >> q; q--; ) {
        int x;
        cin >> x;
        int l, r;
        tie(l, r) = findseg(a, k, x);
        int L = min(x, r+l-x) - 1;
        int R = max(x, r+l-x);
        ++pref[L];
        --pref[R];
    }
    pref[0] &= 1;
    for (int i = 1; i < n; ++i) {
        pref[i] += pref[i-1];
        pref[i] &= 1;
    }
    for (auto p : a) {
        vector<int> v;
        for (int i = p.first-1; i < p.second; ++i) {
            if (pref[i]) {
                v.emplace_back(i);
            }
        }
        int l = 0;
        int r = (int)v.size()-1;
        while (l < r) {
            swap(s[v[l++]], s[v[r--]]);
        }
    }
    cout << s << '\n';
}
 
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