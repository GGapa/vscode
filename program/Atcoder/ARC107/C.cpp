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

constexpr int mod = 998244353;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<VI> A(n + 1, VI(n + 1));
    rep(i, 1, n) rep(j, 1, n) cin >> A[i][j];

    DSU dsu(n + 1);

    rep(i, 1, n) rep(j, i + 1, n) if(i != j){
        bool tag = 1;
        rep(k, 1, n) if(A[i][k] + A[j][k] > m) 
            {tag = 0; break; }
        if(tag) 
            dsu.merge(i, j);
    }

    LL ans = 1;

    vector<int> vis(n + 1), fac(n + 1);
    fac[0] = 1;
    rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod, vis[dsu.find(i)]++;
    rep(i, 1, n) (ans *= fac[vis[i]]) %= mod;

    dsu.init(n + 1);
    fill(vis.begin(), vis.end(), 0);

    rep(i, 1, n) rep(j, i + 1, n) {
        bool tag = 1;
        rep(k, 1, n) if(A[k][i] + A[k][j] > m) {tag = 0; break;}
        if(tag) dsu.merge(i, j);
    }


    fac[0] = 1;
    rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod, vis[dsu.find(i)]++;
    rep(i, 1, n) (ans *= fac[vis[i]]) %= mod;

    cout << ans << '\n';
    
    return 0;
}