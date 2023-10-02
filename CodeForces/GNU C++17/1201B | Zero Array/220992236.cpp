/**
 *     author: brownfox2k6
 *    created: Tue 29 Aug 2023 22:42:39 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
bool isEven(int x) {
    return x % 2 == 0;
}
 
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a+n);
 
    long long s = accumulate(a, a+n-1, 0ll);
    if (isEven(s + a[n-1]) && a[n-1] <= s) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}