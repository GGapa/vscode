#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct DSU {
    vector<int> fa;
    DSU() {}
    DSU(int n) {init(n); }
    void init(int n) {
        fa.resize(n + 1); 
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        fa[x] = y;
        return true;    
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    DSU dsu(n);
    vector<int> a(m + 1), d(m + 1), k(m + 2);
    rep(i, 1, m) cin >> a[i] >> d[i] >> k[i];
    int ans = n;
    rep(nw, 1, 10) {
        vector<int> F(n + 3);
        rep(i, 1, m) if(d[i] == nw) F[a[i]]++, F[a[i] + (k[i]) * d[i]]--;
        rep(i, nw, n) F[i] += F[i - nw];
        rep(i, 1, n - nw) if(F[i]) 
            ans -= dsu.merge(i, i + nw);   
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}