/**
 *     author: brownfox2k6
 *    created: Tue 22 Aug 2023 13:41:33 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
// check if [l, r] in ast[i]
bool check(vector<pair<int, int>> &asti, int l, int r) {
    int low = 0;
    int high = (int) asti.size() - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        // If [l, r] completely inside asti[mid] -> ok
        if (l >= asti[mid].first && r <= asti[mid].second) {
            return true;
        }
        // If [l, r] partially inside asti[mid] -> not ok
        if (   (asti[mid].first <= l && l <= asti[mid].second)
            || (asti[mid].first <= r && r <= asti[mid].second)) {
            return false;
        }
        // If [l, r] completely outside asti[mid]
        if (l > asti[mid].second) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> ast(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '*') {
                if (ast[i].empty()) {
                    ast[i].emplace_back(j, j);
                } else if (ast[i].back().first == -1) {
                    ast[i].back() = {j, j};
                } else {
                    ++ast[i].back().second;
                }
            } else {
                if (!ast[i].empty() && ast[i].back().first != -1) {
                    ast[i].emplace_back(-1, -1);
                }
            }
        }
        if (!ast[i].empty() && ast[i].back().first == -1) {
            ast[i].pop_back();
        }
    }
 
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < min({n-i, m-j, j+1}); ++k) {
                if (check(ast[i+k], j-k, j+k)) {
                    ++ans;
                } else {
                    break;
                }
            }
        }
    }
 
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    for (cin >> t; t--; ) {
        solve();
    }
}