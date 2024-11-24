#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int mod = 998244353;

ll qpow(ll x, ll y) {
    ll ret = 1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<VI> F(n + 1, VI(x + 1));
    vector<VI> C(n + 1, VI(n + 1));
    rep(i, 0, n) C[i][0] = 1;
    rep(i, 1, n) rep(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    // rep(i, 1, x) F[1][i] = i; 
    rep(i, 2, n) rep(j, 1, x) {
        if(i > j) {F[i][j] = (qpow(j, i) - qpow(j - 1, i) + mod) % mod; continue;}
        rep(k, 1, i) (F[i][j] += 1ll * C[i][k] * qpow(i - 1, i - k) % mod * F[k][j - i + 1] % mod) %= mod;
    }
    int ans = 0;
    rep(i ,1, x) (ans += F[n][i]) %= mod;
    cout << ans % mod << '\n';
    return 0;
}
/*
F[i][j] 前 [1, i] 个英雄，最大血量为 x 的方案数
*/