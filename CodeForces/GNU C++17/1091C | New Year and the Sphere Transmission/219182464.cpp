#include <iostream>
#include <vector>
#include <algorithm>
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
 
 vector<int> st;
 st.emplace_back(1);
 for (int i = 2; i*i <= n; ++i) {
  if (n % i == 0) {
   st.emplace_back(getsum(n, i));
   if (n/i != i) {
       st.emplace_back(getsum(n, n/i));
   }
  }
 }
 st.emplace_back(n * (n+1) >> 1);
 
 sort(st.begin(), st.end());
 for (int x: st) {
  cout << x << ' ';
 }
}