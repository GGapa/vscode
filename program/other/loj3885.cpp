#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 5e5, LG = __lg(N) + 1;

int n, m;
int dep[N], fa[N][LG], mx[N][LG], mn[N][LG], ans[N], st[N];
AI<3> A[N];
vector<AI<2>> G[N];

void dfs(int x, int pa, int val, int id) {
    dep[x] = dep[pa] + 1; fa[x][0] = pa; mx[x][0] = val; st[x] = id;
    rep(i, 1, __lg(n)) fa[x][i] = fa[fa[x][i - 1]][i - 1], mx[x][i] = max(mx[x][i - 1], mx[fa[x][i - 1]][i - 1]);
    for(auto i : G[x]) if(i[0] != pa) 
        dfs(i[0], x, A[i[1]][0], i[1]);
}

AI<2> lca(int x, int y) {
    int ret = 0;
    if(dep[x] < dep[y]) swap(x, y);
    per(i, __lg(n), 0) if(dep[fa[x][i]] >= dep[y]) 
        ret = max(ret, mx[x][i]), x = fa[x][i];
    if(x == y) return {x, ret};
    per(i, __lg(n), 0) if(fa[x][i] != fa[y][i]) 
        ret = max({ret, mx[x][i], mx[y][i]}), x = fa[x][i], y = fa[y][i];
    return {fa[x][0], max({ret, mx[x][0], mx[y][0]})};
}

void modify(int x, int pa, int val) {
    per(i, __lg(n), 0) if(dep[fa[x][i]] >= dep[pa]) 
        mn[x][i] = min(mn[x][i], val), x = fa[x][i];
}

void init() {
    rep(i, 1, n) rep(j, 0, __lg(n)) mx[i][j] = 0, mn[i][j] = INT_MAX;
    rep(i, 1, n) vector<AI<2>>().swap(G[i]);
}

void solve() {
    cin >> n >> m;
    init();
    for(int i = 1, u, v, l, r; i < n; i++) {
        cin >> u >> v >> l >> r;
        G[u].push_back({v, i}); G[v].push_back({u, i});
        A[i] = {l, r, i};
    }
    dfs(1, 0, 0, 0);
    for(int i = n, u, v, l, r; i <= m; i++) {
        cin >> u >> v >> l >> r;
        auto la = lca(u, v);
        modify(u, la[0], r - 1); modify(v, la[0], r - 1);
        A[i] = {max(l, la[1] + 1), r, i};
    }

    per(j, __lg(n), 1) rep(i, 2, n)  {
        mn[i][j - 1] = min(mn[i][j - 1], mn[i][j]);
        mn[fa[i][j - 1]][j - 1] = min(mn[fa[i][j - 1]][j - 1], mn[i][j]);
    }
    rep(i, 2, n) A[st[i]][1] = min(A[st[i]][1], mn[i][0]);

    sort(A + 1, A + 1 + m, [&](const auto &x, const auto &y) {
        return (x[1] == y[1] ? x[0] < y[0] : x[1] < y[1]);
    });

    set<int> s;
    rep(i, 1, m) s.insert(i);
    rep(i, 1, m) {
        auto &[l, r, id] = A[i];
        auto it = s.lower_bound(l);
        if(it != s.end() && *it <= r) 
            ans[id] = *it, s.erase(it);
        else return cout << "NO\n", void();
    }

    cout << "YES\n";
    rep(i, 1, m) cout << ans[i] << " \n"[i == m];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
} 
/*
3
5 6
4 5 1 2
1 4 6 6
1 3 3 3
2 4 4 4
2 5 2 3
3 5 4 5
5 6
4 5 6 6
3 5 2 3
2 5 2 3
1 5 1 2
1 5 5 5
2 5 4 4
4 5
1 
*/