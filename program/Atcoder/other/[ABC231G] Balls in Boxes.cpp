#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}
 
LL inv(int x) {return qpow(x, mod - 2); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    vector<VI> F(n + 1, VI(n + 1)) ;
    LL iv = inv(n);
    F[0][0] = 1;
    rep(i, 1, n) rep(j, 0, n) {
        (F[i][j] += 1ll * F[i - 1][j] * A[i] % mod) %= mod;
        if(j < n) (F[i][j + 1] += 1ll * F[i - 1][j] * (k - j) % mod * iv % mod) %= mod;
    } 
    LL ans = 0;
    rep(i, 0, n) (ans += F[n][i]) %= mod;
    cout << ans << '\n';
    return 0;
}