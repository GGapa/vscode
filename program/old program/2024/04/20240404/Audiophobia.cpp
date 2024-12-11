// Audiophobia UVA10048
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<ll>;
const ll INF = 1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int n, m, q, ca = 1; cin >> n >> m >> q && n; ca++) {
        if(ca > 1) cout << '\n';
        cout << "Case #" << ca << '\n';
        vector<VI> G(n + 1, VI(n + 1, INF));
        rep(i, 1, n) G[i][i] = 0;
        for(int u, v, w, i = 1 ; i <= m; i++) 
            cin >> u >> v >> w, G[u][v] = G[v][u] = min(G[u][v], 1ll * w);
        rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) 
            if(G[i][k] != INF && G[k][j] != INF) 
                G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
        for(int i = 1, x, y; i <= q; i++) {
            cin >> x >> y;
            if(G[x][y] == INF) cout << "no path\n";
            else cout << G[x][y] << '\n';
        }
    } 
    return 0;
}
