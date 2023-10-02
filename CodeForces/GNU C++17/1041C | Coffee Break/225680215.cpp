/**
 *     author: brownfox2k6
 *    created: Thu 28 Sep 2023 22:57:12 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<int, int>
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int n, m, d;
    cin >> n >> m >> d;
 
    pair<int, int> a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
 
    int ans[n];
    ans[a[0].second] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.emplace(a[0].first, 0);
 
    for (int i = 1; i < n; ++i) {
        int last, tno;
        tie(last, tno) = pq.top();
        if (a[i].first - last <= d) {
            ans[a[i].second] = pq.size();
            pq.emplace(a[i].first, pq.size());
        } else {
            pq.pop();
            pq.emplace(a[i].first, tno);
            ans[a[i].second] = tno;
        }
    }
 
    cout << pq.size() << '\n';
    for (int x : ans) {
        cout << x + 1 << ' ';
    }
}