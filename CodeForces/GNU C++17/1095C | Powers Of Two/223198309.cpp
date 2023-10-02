/**
 *     author: brownfox2k6
 *    created: Wed 13 Sep 2023 17:35:08 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
 
    priority_queue<int> v;
    for (int b = 0; b < 31; ++b) {
        if (n & (1 << b)) {
            v.push(1 << b);
        }
    }
 
    if (v.size() > k) {
        cout << "NO";
        return 0;
    }
 
    while (v.size() != k && v.top() % 2 == 0) {
        v.push(v.top() >> 1);
        v.push(v.top() >> 1);
        v.pop();
    }
 
    if (v.size() != k) {
        cout << "NO";
        return 0;
    }
 
    cout << "YES\n";
    while (!v.empty()) {
        cout << v.top() << ' ';
        v.pop();
    }
}