#include <iostream>
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
 
    if (k >= 2*n) {
        cout << "YES\n";
        for (int i = 0; i < n-1; ++i) {
            cout << "2 ";
        }
        cout << k - 2*(n-1) << "\n1";
    }
    else cout << "NO";
}