// 7.36 am
// cxxdroid
 
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
 
int n, x;
vector<int> v;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    for (cin >> n; n--; ) {
        cin >> x;
 
        if (v.empty() or x > v.back()) {
            v.push_back(x);
        } else {
            *lower_bound(v.begin(), v.end(), x) = x;
        }
    }
    
    cout << v.size();
}