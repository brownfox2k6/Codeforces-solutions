/**
 *     author: brownfox2k6
 *    created: Tue 19 Sep 2023 23:52:28 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int x, y;
    cin >> x >> y;
 
    double_t xtoy = y * log(x);
    double_t ytox = x * log(y);
 
    if (xtoy > ytox) cout << '>';
    if (xtoy < ytox) cout << '<';
    if (xtoy == ytox) cout << '=';
}