/**
 *     author: brownfox2k6
 *    created: Tue 22 Aug 2023 13:26:46 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
bool p[100001];
 
int main() {
    int n;
    cin >> n;
 
    for (int i = 2; i*i <= n+1; ++i) {
        if (!p[i]) {
            for (int j = i*2; j <= n+1; j += i) {
                p[j] = 1;
            }
        }
    }
 
    if (n <= 2) {
        cout << "1\n";
    } else {
        cout << "2\n";
    }
 
    for (int i = 2; i < n+2; ++i) {
        cout << (p[i]? 2 : 1) << ' ';
    }
}