// brownfox2k6
// 9.24 am
 
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, b, a;
    cin >> n >> b >> a;
    int maxa = a;
    
    auto use_battery = [&](int exposed) -> void {
        if (exposed) {
            a = min(a+1, maxa);
        }
        --b;
    };
    
    auto use_accumulator = [&]() -> void {
        --a;
    };
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a == 0 && b == 0) {
            break;
        }
        int exposed;
        cin >> exposed;
        if (a == 0) {
            use_battery(exposed);
        } else if (b == 0) {
            use_accumulator(); 
        } else if (exposed && a < maxa) {
            use_battery(exposed);
        } else {
            use_accumulator();
        }
        ++ans;
    }
    
    cout << ans;
}