//君本凌云客，何故喜蓬蒿？
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
    vector<VI> F(n + 1, VI(m + 1, 1e9));
    rep(i, 1, min(n, m)) F[i][i] = 0;
    rep(i, 1, n) rep(j, 1, m) {
        auto &f = F[i][j];
        rep(k, 1, i - 1) f = min(f, F[k][j] + F[(i - k)][j] + 1);
        rep(k, 1, j - 1) f = min(f, F[i][k] + F[i][j - k] + 1);
    }
    // rep(i ,1, n) rep(j, 1, m) cout << F[i][j] << " \n"[j == m];
    cout << F[n][m] << '\n';
    return 0;
}