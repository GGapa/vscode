#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x, n; cin >> x >> n;
    double p; cin >> p;
    p /= 100;
    vector<vector<double>> F(n + 1, vector<double>(n + 1)) ;
    rep(i, 0, n) F[0][i] = __builtin_ctz(x + i);
    rep(i, 1, n) rep(j, 0, n) {
        if((j << 1) <= n) F[i][j << 1] += (F[i - 1][j] + 1) * p;
        if(j) F[i][j - 1] += F[i - 1][j] * (1 - p);
    }
    cout << fixed << setprecision(10) << F[n][0] << '\n';
    return 0;
}