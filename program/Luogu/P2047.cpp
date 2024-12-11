// P2047 [NOI2007] 社交网络
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<ll>;
const ll INF = 1e11;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<VI> G(n + 1, VI(n + 1, INF)), F(n + 1, VI(n + 1));
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, G[u][v] = G[v][u] = w, F[u][v] = F[v][u] = 1;
    rep(i, 1, n) F[i][i] = 1, G[i][i] = 0;
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) {
        ll &g = G[i][j], &f = F[i][j];
        if(G[i][k] < INF && G[k][j] < INF) {
            ll d = G[i][k] + G[k][j];
            if(d < g) 
                g = d, f = F[i][k] * F[k][j];
            else if(d == g && i != k && k != j) 
                f += F[i][k] * F[k][j];
        }
    }
    vector<double> ans(n + 1);
    rep(i, 1, n) rep(j, 1, n) rep(k, 1, n) {
        if(k != i && k != j && G[i][k] + G[k][j] == G[i][j]) {
            ans[k] += (double)(F[i][k] * F[k][j]) / (double)F[i][j];
        }
    }
    rep(i, 1, n) printf("%.3f\n", ans[i]);
    return 0; 
}