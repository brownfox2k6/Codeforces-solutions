/**
 *     author: brownfox2k6
 *    created: Sun 17 Sep 2023 10:59:32 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
main() {
    string s;
    cin >> s;
    int n = s.length();
    
    vector<int> prefa={0}, prefb={0};
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            prefa.emplace_back(prefa.back() + 1);
            prefb.emplace_back(prefb.back());
        } else {
            prefa.emplace_back(prefa.back());
            prefb.emplace_back(prefb.back() + 1);
        }
    }
 
    int ans = INT_MIN;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int first = prefa[i] - prefa[0];
            int second = prefb[j] - prefb[i];
            int third = prefa[n] - prefa[j];
            ans = max(ans, first + second + third);
        }
    }
 
    cout << ans << '\n';
}