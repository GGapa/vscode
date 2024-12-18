#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int tp = (1 << n) - 1;
    const int INF = 1e9 ;

    vector<VI> G(n + 1, VI(n + 1, -INF));
    rep(i, 0, n - 1) G[i][i] = 0;
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w,  G[u][v] = w;
    
    vector<VI> F(tp + 1, VI(n + 1, -INF));
    F[1][0] = 0;
    int ans = 0;
    rep(s, 0, tp) rep(i, 0, n - 1) if((s >> i) & 1) {
        rep(j, 0, n - 1) if(!((s >> j) & 1)) {
            int t = s | (1 << j);
            F[t][j] = max(F[t][j], F[s][i] + G[i][j]);
        }
        // cout << s << " " << i << " " << F[s][i] << '\n';
        if(i == n - 1) ans = max(ans,  F[s][i]);
    }
    cout << ans << '\n';
    return 0; 
}