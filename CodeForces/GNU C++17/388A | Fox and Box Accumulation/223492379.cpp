/**
 *     author: brownfox2k6
 *    created: Fri 15 Sep 2023 20:51:46 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
#define inf 1000
int n, a[105], piles;
 
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
 
    for (int i = 0; i < n; ++i) {
        if (piles * (a[i] + 1) <= i) {
            ++piles;
        }
    }
 
    cout << piles;
}