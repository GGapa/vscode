#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 10000 + 5, INF = 1e9 + 1;
const int  ML = 14;

int n, m;
struct Edge {
	int v, w;
};
vector<Edge> G[N];
int A[N], dep[N];
int F[22][N], mn[22][N], fa[N];

int find(int x) {
    return (x == fa[x] ? x : fa[x] = find(fa[x]));
}

void dfs(int x, int fa) {
	dep[x] = dep[fa] + 1;
	F[0][x] = fa;
	for(auto i : G[x]) if(i.v != fa) {
		mn[0][i.v] = i.w;
		dfs(i.v, x);
	}
}

int LCA(int x, int y) {
	int mi = 0;
	if(dep[x] < dep[y]) swap(x, y);
	per(i, ML, 0) if(dep[F[i][x]] >= dep[y]) {
		mi = max(mi, mn[i][x]);
		x = F[i][x];
	}
	if(x == y) return mi;
	per(i, ML, 0) if(F[i][x] != F[i][y]) {
		mi = max({mi, mn[i][x], mn[i][y]}); 
		x = F[i][x]; y = F[i][y];
	}
	mi = max({mi, mn[0][x], mn[0][y]}); 
	return mi;
}

void solve() {
    cin >> n >> m;
	rep(i, 0, 21) rep(j, 0, N - 5) mn[i][j] = 0;
    rep(i, 1, n) G[i].clear();
    iota(fa, fa + 1 + n, 0);
    vector<array<int, 3>> E(1);
    vector<int> vis(m + 1);
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, E.push_back({w, u, v});
    sort(E.begin() + 1, E.end());
    int cnt = 1, sum = 0;
    rep(i, 1, m) {
        int x = E[i][1], y = E[i][2];
        int xx = find(x), yy = find(y);
        if(xx == yy) continue;
        fa[xx] = yy;
        sum += E[i][0];
        vis[i] = true;
        G[x].push_back({y, E[i][0]}), G[y].push_back({x, E[i][0]});
        cnt++;
        if(cnt == n) break;
    }
    if(cnt != n) return cout << -1 << '\n', void();
    dfs(1, 0);
    	rep(i, 1, 20) rep(x, 1, n){
		F[i][x] = F[i - 1][F[i - 1][x]];
		mn[i][x] = max(mn[i - 1][x], mn[i - 1][F[i - 1][x]]);
	}
    int ans = INT_MAX;
    rep(i, 1, m) if(!vis[i]) {
        int x = E[i][1], y = E[i][2];
        if(x == y) continue;
        int t = LCA(x, y);
        // cout << x << " " << y << " " << t << '\n';
        if(t >= INF) continue;
        ans = min(ans, sum + E[i][0] - t);
    }
    if(ans >= INF) ans = -1;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}