// brownfox2k6
// 7.35 am
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, k;
    cin >> n >> k;
 
    pair<int, int> p[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p, p+n);
    
    priority_queue<int> pq;
    int64_t cur=0, ans=0;
    for (int i = n-1; i >= 0; --i) {
        cur += p[i].second;
        pq.push(-p[i].second);
        if (pq.size() > k) {
            cur += pq.top();
            pq.pop();
        }
        ans = max(ans, cur * p[i].first);
    }
    
    cout << ans;
}