/**
 *     author: brownfox2k6
 *    created: Mon 18 Sep 2023 23:44:11 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int a[200001];
int n;
string s;
map<pair<int, int>, int> dp;
 
int f(int ind, int left) {
    if (ind == n) {
        return 0;
    }
    if (dp.count({ind, left})) {
        return dp[{ind, left}];
    }
    int cut = 0;
    int notCut = 0;
    if ((a[ind] - a[left-1]) % 3 == 0) {
        cut = 1 + f(ind+1, ind+1);
    } else {
        cut = f(ind+1, ind+1);
        notCut = f(ind+1, left);
    }
    return dp[{ind, left}] = max(cut, notCut);
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    n = s.length() + 1;
    for (int i = 0; i < n-1; ++i) {
        a[i+1] = a[i] + s[i] - '0';
    }
    cout << f(1, 1);
}