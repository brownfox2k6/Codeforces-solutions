/**
 *     author: brownfox2k6
 *    created: Mon 28 Aug 2023 02:16:22 Hanoi, Vietnam
**/
 
// pascal sucks
 
#include <iostream>
using namespace std;
 
int main() {
    int t;
    for (cin >> t; t--; ) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int ans = 0;
        if (y1 == y2 and y1 > y3) {
            ans = abs(x1 - x2);
        } else if (y1 == y3 and y1 > y2) {
            ans = abs(x1 - x3);
        } else if (y2 == y3 and y2 > y1) {
            ans = abs(x2 - x3);
        }
        cout << ans << '\n';
    }
}