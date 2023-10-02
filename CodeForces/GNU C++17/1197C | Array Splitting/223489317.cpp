/**
 *     author: brownfox2k6
 *    created: Fri 15 Sep 2023 20:41:49 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int n, k, a[300005];
vector<int> diff;
int64_t ans;
 
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    for (int i = 0; i < n-1; ++i) {
        diff.emplace_back(a[i] - a[i+1]);
    }
    sort(diff.begin(), diff.end());
 
    ans = a[n-1] - a[0] + accumulate(diff.begin(), diff.begin()+k-1, 0LL);
    cout << ans;
}