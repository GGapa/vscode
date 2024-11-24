#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<LL>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    vector<VI> G(n + 1, VI(n + 1, 1e18));
    vector<array<int, 3>> qe(1), e(1);
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w, G[u][v] = G[v][u] = w;
        e.push_back({u, v, w});
    }
    rep(i, 1, n) G[i][i] = 0;
    const LL INF = 1e18;
    for(int i = 1; i <= q; i++) {
        int x, y, z = 0; cin >> x >> y;
        if(x != 1) cin >> z;
        qe.push_back({x, y, z});
        if(x == 1) {
            z = e[y][1], y = e[y][0];
            G[y][z] = G[z][y] = INF;
        }
    } 
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
    vector<LL> ans;
    per(i, q, 1) {
        int x = qe[i][0], y = qe[i][1], z = qe[i][2];
        if(x == 1) {
            int w = e[y][2];
            z = e[y][1], y = e[y][0];
            G[y][z] = min(G[y][z], w);
            G[z][y] = min(G[z][y], w);
            // G[y][z] = G[z][y] = w;
            for(auto k : {z, y}) rep(i, 1, n) rep(j, 1, n) G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
        }
        else ans.emplace_back((G[y][z] >= INF ? -1 : G[y][z]));
    }
    reverse(ans.begin(), ans.end());
    for(auto a : ans) cout << a << '\n';
    return 0;
}