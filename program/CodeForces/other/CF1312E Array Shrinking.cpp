#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int N = 500 + 5;
int F[N][1010];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for(int i = 1, x; i <= n; i++) cin >> x, F[i][x] = i + 1;
    rep(v, 2, 1010 - 1) rep(i ,1, n) {
        auto &f = F[i][v], f1 = F[i][v - 1] ;
        if(f == 0 && f1 && f1 <= n + 1) f = F[f1][v - 1];
    }
    vector<int> G(n + 10, 1e9) ;
    G[n + 1] = 0;
    per(i, n, 1) rep(v, 1, 1010 - 1) {
        auto &f = F[i][v];
        if(F[i][v]) G[i] = min(G[i], G[F[i][v]] + 1);
    }
    cout << G[1] << '\n';
    return 0;
}