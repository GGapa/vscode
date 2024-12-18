#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<LL>;

const int mod = 1e9 + 7;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}
 
LL inv(int x) {return qpow(x, mod - 2); }

LL add(const LL x, const LL y) {
    return (x + y + mod) % mod;
} 
 
LL mul(const LL x, const LL y) {
    return (x * y % mod + mod) % mod;
}

int iv = inv(10000);

LL F[2][2], of[2][2];

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), p(n + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> p[i], p[i] = 1ll * p[i] * iv % mod;
    LL ans = 0;
    rep(i, 0, 10) rep(j, i, 10) {
        rep(x, 0, 1) rep(y, 0, 1) F[x][y] = 0;
        F[0][0] = 1;
        rep(k, 1, n) {
            rep(x, 0, 1) rep(y, 0, 1) of[x][y] = F[x][y], F[x][y] = 0;
            rep(x, 0, 1) rep(y, 0, 1) {
                (F[x ^ (A[k] >> i & 1)][y ^ (A[k] >> j & 1)] += 1ll * of[x][y] * p[k] % mod) %= mod;
                (F[x][y] += 1ll * of[x][y] * add(1, -p[k]) % mod) %= mod;
            }
        }
        (ans += F[1][1] * (1 << i + j) % mod * (i == j ? 1 : 2) % mod) %= mod;
        // if(i <= 1 && j <= 1) cerr << ans << " " << F[1][1] << '\n';
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cerr << inv(4) << '\n';
    int T; cin >> T;
    while(T--) solve();
    return 0;
}