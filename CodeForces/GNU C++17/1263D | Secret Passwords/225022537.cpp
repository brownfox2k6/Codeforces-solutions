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
    
    vector<int> sizeallpars() {
        set<int> st;
        for (int i = 0; i < 26; ++i) {
            st.emplace(findpar(i));
        }
        vector<int> v;
        for (int x: st) {
            if (used[x]) {
                v.emplace_back(size[x]);
            }
        }
        return v;
    }
    
    void use(int v) {
        used[v] = 1;
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
        for (char c : st) {
            ds.use(c-'a');
        }
        vector<char> v(st.begin(), st.end());
        int sz = v.size();
        for (int i = 0; i < sz - 1; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                ds.unionbysize(v[i]-'a', v[j]-'a');
            }
        }
    }
    
    vector<int> v = ds.sizeallpars();
    sort(v.begin(), v.end(), greater<int>());
    int sz = v.size();
    // cout << accumulate(v.begin(), v.begin()+sz-1, 0) << '\n';
    // for (int x : v) cout << x << ' ';
    cout << sz << '\n';
}