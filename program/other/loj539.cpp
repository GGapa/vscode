#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int INF = 1e9, N = 100 + 5;

int F[N][N * N], G[N][N][20], H[N][N * N], tmp[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, C, T; cin >> n >> m >> C >> T;
    vector<int> p(n + 1), c(n + 1) ;
    rep(i, 1, n) cin >> p[i] >> c[i], c[i] = min(c[i], C);
    rep(k, 0, 18) rep(i, 1, n) rep(j, 1, n) G[i][j][k] = H[i][j] = i == j ? 0 : -INF;
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, G[u][v][1] = max(G[u][v][1], w);
    rep(t, 1, 18) rep(i, 1, n) rep(j, 1, n) rep(k, 1, n) G[i][j][t] = max(G[i][j][t], G[i][k][t - 1] + G[k][j][t - 1]) ;
    rep(i, 1, n) rep(t, 1, 18) if(c[i] >> t - 1 & 1) {
        rep(j, 1, n) tmp[j] = H[i][j];
        rep(k, 1, n) rep(j, 1, n) H[i][j] = max(H[i][j], tmp[k] + G[k][j][t]);
    }
    rep(w, 1, n * n) rep(i, 1, n) if(p[i] <= w) 
        rep(j, 1, n) F[i][w] = max(F[i][w], F[j][w - p[i]] + H[i][j]);
    for(int s, q, d; T--; ) {
        cin >> s >> q >> d;
        cout << q - (lower_bound(F[s] + 1, F[s] + 1 + q, d) - F[s]) << '\n';
    }
    return 0;
}