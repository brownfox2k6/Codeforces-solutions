// brownfox2k6
// 8.55 am
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    int x = min(n, m);
    
    cout << x + 1 << '\n';
    for (int i = 0; i <= x; ++i) {
        cout << i << ' ' << x - i << '\n';
    }
}