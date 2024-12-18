#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 5;

int n, m;
vector<pair<int, int>> edge;
vector<int> G[N];

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

int dfn[N], mi[20][N], fa[20][N], si[N], dis[N], up[N];
 
int get(int x, int y) {
    return dfn[x] < dfn[y] ? x : y;
}
 
void dfs(int x, int f) {
    dfn[x] = ++dfn[0]; mi[0][dfn[x]] = f; fa[0][x] = f; si[x] = 1; dis[x] = dis[f] + 1; 
    for(auto to : G[x]) if(to != f) dfs(to, x), si[x] += si[to];
}
 
int lca(int x, int y) {
    if(x == y) return x;
    if((x = dfn[x]) > (y = dfn[y])) swap(x, y);
    int d = __lg(y - x++);
    return get(mi[d][x], mi[d][y - (1 << d) + 1]);
}

void dfs1(int x, int f) {
    for(auto to : G[x]) if(to != f) {
        up[to] += up[x];
        dfs1(to, x);
        // up[x] += up[to];
    }
}

void solve() {
    cin >> n >> m;

    // edge.resize(1); 
    DSU dsu(n);
    // rep(i, 1, n) vector<int>(0).swap(G[i]);
    // fill()

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        if(dsu.merge(u, v)) G[u].emplace_back(v), G[v].emplace_back(u);
        else edge.emplace_back(u, v);
    }

    dfs(1, 0);

    for(int i = 1; i <= __lg(n); i++) for(int j = 1; j + (1 << i) - 1 <= n; j++) 
        mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
    rep(i, 1, 19) rep(j, 1, n) fa[i][j] = fa[i - 1][fa[i - 1][j]];

    for(auto [u, v] : edge) {
        int l = lca(u, v);
        if(l == u || l == v) {
            if(l == u) swap(u, v);
            up[1]++; up[u]++; 
            // cerr << u << '\n';
            per(i, 19, 0) if(dis[fa[i][u]] > dis[v] && fa[i][u] != 0) u = fa[i][u];
            // cerr << u << '\n';
            up[u]--;
        }
        else {
            up[u]++; up[v]++; 
        }
    }

    // rep(i, 1, n) cerr << up[i] << " \n"[i == n];
    dfs1(1, 0);

    // rep(i, 1, n) cerr << up[i]  << " \n"[i == n];
    rep(i, 1, n) cout << (up[i] == m - n + 1) ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}
/*
最小生成树是唯一的，可以发现
4 5
8 2
*/