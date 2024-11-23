#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
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
    using AI = array<int, 3>;
    int n; cin >> n;

    vector<AI> F(n + 1);
    rep(i, 1, n) rep(j, 0, 2) cin >> F[i][j];

    sort(F.begin() + 1, F.end(), [](const AI &x, const AI &y) {
        return 1ll * x[0] * (y[2] - y[1]) * x[2] > 1ll * y[0] * (x[2] - x[1]) * y[2];
    });
    LL p = 1, ans = 0;
    rep(i, 1, n) {
        (p *= F[i][1] * inv(F[i][2]) % mod) %= mod;
        (ans += inv(p) * F[i][0] % mod) %= mod;
    }

    cout << ans << '\n';
    return 0;
}