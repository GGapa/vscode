// Earn to Advance
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const ll INF = 1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    using AI = array<ll, 2>;
    using VI = vector<ll> ;
    vector<VI> P(n + 1, VI(n + 1)), R = P, D = P;
    rep(i, 1, n) rep(j, 1, n) cin >> P[i][j];
    rep(i, 1, n) rep(j, 1, n - 1) cin >> R[i][j];
    rep(i, 1, n - 1) rep(j, 1, n) cin >> D[i][j];
    vector<vector<AI>> F(n + 1, vector<AI>(n + 1, {INF, 0})); //最小步数  当前钱数。
    F[1][1] = {0, 0};  
    rep(i, 1, n) rep(j, 1, n) {
        vector<VI> dis(n + 1, VI(n + 1, INF));
        dis[i][j] = 0;
        rep(x, i, n) rep(y, j, n) {
            auto &d = dis[x][y];
            d = min(d, dis[x - 1][y] + D[x - 1][y]);
            d = min(d, dis[x][y - 1] + R[x][y - 1]);
        }
        rep(x, i, n) rep(y, j, n) {
            if(x != n && y != n && P[x][y] < P[i][j]) continue;
            auto[os, om] = F[i][j];
            ll nc = max(0ll, (dis[x][y] + P[i][j] - 1) / P[i][j]);  // 计算需要在这里赚多少个小时的兼职
            ll ns = os + nc + x - i + y - j;                        // 新的步数
            ll nm = om + nc * P[i][j] - dis[x][y];                  // 新的钱数
            if(ns < F[x][y][0] || (ns == F[x][y][0] && nm > F[x][y][1])) 
                F[x][y] = {ns, nm};
        }
    }
    cout << F[n][n][0] << '\n';
    return 0;
}