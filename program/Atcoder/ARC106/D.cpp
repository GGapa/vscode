#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 998244353;

namespace pre {
    template <typename T = LL>
    constexpr T qpow(T x, LL y){   // 因为使用了 template 所以进 qpow 的时候别忘记开 long long
        T ret = 1;
        for(; y; y >>= 1) {
            if(y & 1) (ret = ret * x % mod);
            (x = x * x % mod) ;
        }
        return ret;
    }

    template <typename T = LL>
    constexpr T inv(T x) {return qpow(x, mod - 2); }
}   
using namespace pre;

namespace binom {
    constexpr int N = 1e6 + 5;
    LL fac[N], iv[N];
 
    void init() {
        fac[0] = 1;
        rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % mod;
        iv[N - 1] = inv(fac[N - 1]); 
        per(i, N - 2, 0) iv[i] = iv[i + 1] * (i + 1) % mod;
    }
 
    LL C(int y, int x) {
        if(x < 0 || y < 0 || y - x < 0) return 0;
        return fac[y] * iv[x] % mod * iv[y - x] % mod;
    }   
}
using binom::C; 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    binom::init();
    int n, k; cin >> n >> k;
    vector<LL> sum(k + 1), A(n + 1), s2(k + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 0, k) rep(j, 1, n) (sum[i] += qpow(A[j], i)) %= mod;
    rep(i, 0, k) rep(j, 1, n) (s2[i] += qpow(2 * A[j], i)) %= mod;
    rep(x, 1, k) {
        LL ans = 0;
        rep(i, 0, x) (ans += sum[i] * sum[x - i] % mod * C(x, i) % mod) %= mod;
        ans = ((ans - s2[x]) % mod + mod) % mod;
        (ans *= inv(2ll)) %= mod;
        cout << ans << '\n';
    }
    return 0;
}