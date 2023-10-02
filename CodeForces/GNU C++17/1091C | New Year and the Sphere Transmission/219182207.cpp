#include <iostream>
#include <set>
using namespace std;
 
#define int long long
 
int getsum(int x, int d) {
 int l = 1;
 int r = (x - 1) / d * d + 1;
 int n = (r - l) / d + 1;
 return ((r + l) * n) >> 1;
}
 
signed main() {
 int n;
 cin >> n;
 
 set<int> st;
 st.emplace(1);
 for (int i = 2; i*i <= n; ++i) {
  if (n % i == 0) {
   st.emplace(getsum(n, i));
   st.emplace(getsum(n, n/i));
  }
 }
 st.emplace(n * (n+1) >> 1);
 
 for (int x: st) {
  cout << x << ' ';
 }
}