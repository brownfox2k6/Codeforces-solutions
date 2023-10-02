/**
 *     author: brownfox2k6
 *    created: Sat 19 Aug 2023 14:39:20 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
// int f(vector<int> a, int n) {
//     int x = 0;
//     int y = 0;
//     for (int i = 0; i < 2*n; i += 2) {
//         x += abs(a[i] - a[i+1]);
//         y += a[i] - a[i+1];
//     }
//     return x - abs(y);
// }
 
int main() {
    // cout << f({2, 1, 4, 3, 5, 6, 7, 8}, 4);
 
    int n, k;
    cin >> n >> k;
    int a[2*n];
    iota(a, a+2*n, 1);
    for (int i = 0; i < 2*k; i += 2) {
        swap(a[i], a[i+1]);
    }
    for (int x : a) {
        cout << x << ' ';
    }
}