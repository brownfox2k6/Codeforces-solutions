/**
 *     author: brownfox2k6
 *    created: Wed 13 Sep 2023 22:12:18 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    pair<int, int> p[n];
    for (auto &P : p) {
        cin >> P.first >> P.second;
    }
    sort(p, p+n);
 
    int current = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i].second >= current) {
            current = p[i].second;
        } else {
            current = p[i].first;
        }
    }
    cout << current;
}