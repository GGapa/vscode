#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 3>;
const int N = 3000 + 5;
const LL INF = 1e18;

int n, D;
vector<AI> G[N];
int dfn[N], si[N];
LL dis[N][N], F[N][N], mx[N];

void dfs(int x, int fa) {
    dfn[x] = ++dfn[0]; si[x] = 1;
    for(auto i : G[x]) {
        int to = i[0], w = i[1];
        if(to == fa) continue;
        dfs(to, x); 
        si[x] += si[to];
    }
}

void gdis(int x, int fa, LL *ds) {
    for(auto i : G[x]) {
        int to = i[0], w = i[1];
        if(to == fa) continue;
        ds[to] = ds[x] + w;
        gdis(to, x, ds);
    }
}

void dp(int x, int fa) {
    for(auto tmp : G[x]) {
        int to = tmp[0], v = tmp[2];
        if(to == fa) continue;
        dp(to, x);
        rep(i, 1, n) if(F[x][i] >= 0){  // F[x][i] 当前这个节点，属于的特殊点是 i，分两种情况考虑
            LL t = F[to][i] + v;
            if(!(dfn[to] <= dfn[i] && dfn[i] < dfn[to] + si[to])) t = max(t, mx[to]);
            F[x][i] += t;
        }
    } 
    mx[x] = - INF;
    rep(j, 1, n) if((dfn[x] <= dfn[j] && dfn[j] < dfn[x] + si[x])) mx[x] = max(mx[x], F[x][j]);    
}

void solve() {
    cin >> n >> D;
    rep(i, 1, n) vector<AI>(0).swap(G[i]);
    memset(mx, 0, sizeof(mx));
    for(int i = 1, u, v, w, val; i < n; i++) 
        cin >> u >> v >> w >> val, G[u].push_back({v, w, val}), G[v].push_back({u, w, val});
    dfn[0] = 0;
    dfs(1, 0);
    rep(i, 1, n) dis[i][i] = 0, gdis(i, 0, dis[i]);
    fill_n(F[0], N * N, 0);
    rep(i, 1, n) rep(j, 1, n) if(dis[i][j] > D) F[j][i] = -INF;
    dp(1, 0);
    // rep(i, 1, n) rep(j, 1, n) cout << dis[i][j] << " \n"[j == n];
    cout << mx[1] << '\n';
}

signed main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}