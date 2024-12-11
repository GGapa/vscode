#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<LL>> F(n + 1, vector<LL>(n + 1));
    rep(i, 1, n) F[i][i] = 1;
    rep(i, 2, n) {
        rep(j, 1, i - 1) rep(k, i - j, i - 1) 
            (F[i][j] += F[k][min(j, k)]) %= mod;
        F[i][i] += F[i][i - 1];
    }
    per(i, n, 1) F[n][i] = (F[n][i] - F[n][i - 1] + mod) % mod;
    LL ans = 0;
    rep(i, 1, n) rep(j, 1, n) if(i * j < k) 
      (ans += F[n][i] * F[n][j] % mod)  %= mod;
    cout << (ans << 1) % mod << '\n';
    return 0;
}
/*
我们可以注意到只需要关注一行 + 一列就可以确定整个正方体
*/
