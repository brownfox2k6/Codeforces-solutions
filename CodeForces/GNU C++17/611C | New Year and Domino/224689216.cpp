// brownfox2k6
// 10.05 am
 
// 2D prefix sum
 
#include <iostream>
using namespace std;
 
#define N 505
string s[N];
int hor[N][N], ver[N][N];
int n, m, q, x1, y1, x2, y2;
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            hor[i+1][j+1] = hor[i+1][j] + hor[i][j+1] - hor[i][j];
            ver[i+1][j+1] = ver[i+1][j] + ver[i][j+1] - ver[i][j];
            if (s[i][j] == '.') {
                if (i != n-1 && s[i+1][j] == '.') {
                    ++hor[i+1][j+1];
                }
                if (j != m-1 && s[i][j+1] == '.') {
                    ++ver[i+1][j+1];
                }
            }
        }
    }
    
    for (cin >> q; q--; ) {
        cin >> x1 >> y1 >> x2 >> y2;
        --x1;
        --y1;
        int ans = 0;
        ans += hor[x2-1][y2] - hor[x1][y2] - hor[x2-1][y1] + hor[x1][y1];
        ans += ver[x2][y2-1] - ver[x1][y2-1] - ver[x2][y1] + ver[x1][y1];
        cout << ans << '\n';
        
    }
}