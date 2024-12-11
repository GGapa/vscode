#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<ll>;
const ll INF = 2e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<VI> G(n + 1, VI(n + 1, INF));
    rep(i, 1, n) G[i][i] = 0;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        G[u][v] = G[v][u] = w;
    }
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) 
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    if(G[1][n] >= INF) return cout << "inf\n", 0;
    vector<ll> A;
    rep(i, 1, n) if(G[1][i] <= G[1][n])  A.emplace_back(G[1][i]);
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    int t = A.size();
    cout << G[1][n] << " " << t - 1 << '\n';
    rep(i, 0, t - 2) {
        rep(j, 1, n) cout << (bool)(G[1][j] <= A[i]);
        cout << " " << A[i + 1] - A[i] << '\n';
    }
    return 0; 
}
