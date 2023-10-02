/**
 *     author: brownfox2k6
 *    created: Fri 15 Sep 2023 20:22:23 Hanoi, Vietnam
**/
#include <bits/stdc++.h>
using namespace std;
 
const string OPEN = "<{[(";
const string CLOSE = ">}])";
string s;
stack<char> st;
int ans;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
 
    for (char c : s) {
        if (OPEN.find(c) != string::npos) {
            st.push(c);
        } else {
            if (st.empty()) {
                cout << "Impossible";
                return 0;
            }
            if (OPEN.find(st.top()) != CLOSE.find(c)) {
                ++ans;
            }
            st.pop();
        }
    }
 
    if (st.empty()) {
        cout << ans;
    } else {
        cout << "Impossible";
    }
}