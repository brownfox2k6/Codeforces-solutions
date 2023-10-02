// brownfox2k6
// 9.11 am
 
#include <bits/stdc++.h>
using namespace std;
 
#define finp 0
#define memo dp[fleft][hleft][curf][successive]
#define MOD 100000000
 
int nf, nh, maxf, maxh;
int dp[101][101][2][11];
 
int f(int fleft, int hleft, bool curf, int successive) {
    // Base cases
    if (successive > (curf? maxf : maxh)) return 0;
    if (fleft < 0 || hleft < 0) return 0;
    if (!fleft && !hleft) return 1;
    if (memo != -1) return memo;
    // Recurrence
    int takeh = f(fleft-1, hleft, 1, curf? successive+1 : 1);
    int takef = f(fleft, hleft-1, 0, curf? 1 : successive+1);
    return memo = (takeh + takef) % MOD;
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    if (finp) {
        freopen("inp.txt", "r", stdin);
 }
 
 cin >> nf >> nh >> maxf >> maxh;
 
 memset(dp, -1, sizeof dp);
 int firstf = f(nf-1, nh, 1, 1);
 int firsth = f(nf, nh-1, 0, 1);
 cout << (firstf + firsth) % MOD;
}