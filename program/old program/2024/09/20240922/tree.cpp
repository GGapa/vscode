#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 4>;
const int N = 3000 + 5;
const LL INF = 1e18;
vector<pair<int,int>> G[N];
LL F[N][3], nxt[N];

void dfs(int x, int fa) {
    F[x][0] = F[x][1] = F[x][2] = 0;
    for(auto i : G[x]) {
        int to = i.first, w = i.second;
        if(to == fa) continue;
        dfs(to, x);
        if(F[to][0] + w >= F[x][0]) {
            nxt[x] = to;
            F[x][1] = F[x][0];
            F[x][0] = F[to][0] + w;
        }
        else if(F[to][0] + w > F[x][1]) F[x][1] = F[to][0] + w;
    }
}

void dfs2(int x, int fa) {
    for(auto i : G[x]) {
        int to = i.first, w = i.second;
        if(to == fa) continue;
        dfs(to, x);
        if(nxt[x] == to) F[to][2] = w + max(F[x][1], F[x][2]);
        else F[to][2] = w + max(F[x][0], F[x][2]);
        dfs2(to, x);
    }
}   //debug 换根 DP 假了。

void solve() {
    int n, D; cin >> n >> D;
    rep(i, 1, n) vector<pair<int, int>>(0).swap(G[i]);
    vector<AI> ed(n - 1);
    vector<LL> mn(n + 1), fa(n + 1);
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](int x) {
        while(fa[x] != x) x = fa[x] = fa[fa[x]];
        return x;
    };

    for(auto &e : ed) cin >> e[0] >> e[1] >> e[2] >> e[3];
    sort(ed.begin(), ed.end(), [&](const AI &x, const AI &y) {
        return x[3] > y[3];
    });

    LL ans = 0;
    for(auto e : ed) {
        int u = e[0], v = e[1], wei = e[2], val = e[3];
        int ou = u, ov = v;
        G[u].emplace_back(v, wei), G[v].emplace_back(u, wei);   //debug:加边不能够在并查集之后
        u = find(u), v = find(v);
        rep(i, 1, n) F[i][0] = F[i][1] = F[i][2] = 0;
        dfs(v, 0);
        dfs2(v, 0);
        int od = mn[v];
        mn[v] = INF;
        rep(i, 1, n) if(F[i][0] > 0 || F[i][2] > 0) mn[v] = min(mn[v], max(F[i][0], F[i][2]));
        if(mn[v] > D) { 
            G[ou].pop_back(); G[ov].pop_back();     //debug 删边也不能够给在并查集之后。
            mn[v] = od;
            continue;
        }   // debug 这里判断能否加入这条边的顺序不对。
        fa[u] = v;
        ans += val; 
    }
    cout << ans << '\n';
}

signed main() {
    freopen("tree1.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}