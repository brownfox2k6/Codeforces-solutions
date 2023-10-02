// 8.35 am
// cxxdroid
 
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
using namespace std;
 
#define N 100005
int zero[N], one[N], diff[N];
int n, a;
string s;
map<int, pair<int, int>> mp;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> s;
    for (int i = 0; i < n; ++i){
        zero[i+1] = zero[i] + (s[i] == '0');
        one[i+1] = one[i] + (s[i] == '1');
        diff[i+1] = zero[i+1] - one[i+1];
    }
    
    for (int i = 0; i <= n; ++i) {
        if (!mp.count(diff[i])) {
            mp[diff[i]] = {i, i};
        } else {
            mp[diff[i]].second = i;
            a = max(a, mp[diff[i]].second - mp[diff[i]].first);
        }
    }
    
    cout << a;
}