/**
 *     author: brownfox2k6
 *    created: Wed 13 Sep 2023 21:58:03 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
struct node {
    int mul, sub;
} a[50000];
vector<int> dep(50000, -1);
int n, m;
queue<int> q;
 
int main() {
    for (int i = 1; i < 20005; ++i) {
        a[i] = {i*2, i-1};
    }
 
    cin >> n >> m;
    dep[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (dep[a[x].mul] == -1) {
            dep[a[x].mul] = dep[x] + 1;
            q.push(a[x].mul);
        }
        if (dep[a[x].sub] == -1) {
            dep[a[x].sub] = dep[x] + 1;
            q.push(a[x].sub);
        }
    }
 
    cout << dep[m];
}