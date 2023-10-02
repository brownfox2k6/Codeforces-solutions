// brownfox2k6
// 8.57 am
 
#include <bits/stdc++.h>
using namespace std;
 
#define N 1001
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int C[N][N];
    C[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % 1000000007;
        }
    }
    
    int n;
    int64_t ans = 1;
    int total = 0;
    for (cin >> n; n--; ) {
        int x;
        cin >> x;
        total += x;
        ans *= C[total-1][x-1];
        ans %= 1000000007;
    }
    
    cout << ans;
}