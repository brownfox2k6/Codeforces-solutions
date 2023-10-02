// brownfox2k6
// 9.08 am
 
#include <bits/stdc++.h>
using namespace std;
 
class dsu {
private:
    int size[26], par[26];
    bool used[26];
public:
    dsu() {
        fill(size, size+26, 1);
        fill(used, used+26, 0);
        iota(par, par+26, 0);
    }
    
    void use(int v) {
        used[v] = 1;
    }
    
    int findpar(int u) {
        if (u == par[u]) {
            return u;
        }
        return par[u] = findpar(par[u]);
    }
    
    void unionbysize(int u, int v) {
        used[u] = used[v] = 1;
        u = findpar(u);
        v = findpar(v);
        if (u == v) {
            return;
        } else if (size[u] > size[v]) {
            par[v] = u;
            size[u] += size[v];
        } else {
            par[u] = v;
            size[v] += size[u];
        }
    }
    
    int components() {
        set<int> st;
        for (int i = 0; i < 26; ++i) {
            st.emplace(findpar(i));
        }
        int cnt = 0;
        for (int x: st) {
            cnt += used[x];
        }
        return cnt;
    }
};
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    dsu ds;
    int n;
    for (cin >> n; n--; ) {
        string s;
        cin >> s;
        set<char> st(s.begin(), s.end());
        vector<char> v(st.begin(), st.end());
        int sz = v.size();
        for (int i = 0; i < sz; ++i) {
            ds.use(v[i] - 'a');
            for (int j = i+1; j < sz; ++j) {
                ds.unionbysize(v[i]-'a', v[j]-'a');
            }
        }
    }
    
    cout << ds.components();
}