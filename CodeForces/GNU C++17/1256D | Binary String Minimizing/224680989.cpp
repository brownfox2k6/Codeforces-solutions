// brownfox2k6
// 7.17 am
 
#include <iostream>
using namespace std;
 
#define int long long
 
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    int cntzero = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            int p = min(k, i - cntzero);
            swap(s[i], s[i-p]);
            cntzero++;
            k -= p;
        }
    }
    
    cout << s << '\n';
}
 
main() {
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}