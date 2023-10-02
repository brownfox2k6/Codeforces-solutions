/**
 *     author: brownfox2k6
 *    created: Sun 24 Sep 2023 11:26:57 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, k;
    cin >> n >> k;
 
    map<int, int> index;
    int pos[k];
    for (int i = 0; i < k; ++i) {
        cin >> pos[i];
        index[--pos[i]] = i;
    }
 
    priority_queue<pair<int, int>> right;
    int temp[k];
    for (int i = 0; i < k; ++i) {
        cin >> temp[i];
        temp[i] += pos[i];
        right.emplace(-temp[i], pos[i]);
    }
 
    priority_queue<pair<int, int>> left;
    for (int i = 0; i < n; ++i) {
        while (!right.empty() && i > right.top().second) {
            pair<int, int> item = right.top();
            right.pop();
            item.first = - (temp[index[item.second]] - pos[index[item.second]] + 1 - i);
            left.emplace(item);
        }
        int mn = INT_MAX;
        if (!right.empty()) {
            mn = min(mn, -right.top().first - i);
        }
        if (!left.empty()) {
            mn = min(mn, -left.top().first + i);
        }
        cout << mn << ' ';
    }
    cout << '\n';
}
 
 
 
 
 
#define mtt true
#define dbg false
 
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