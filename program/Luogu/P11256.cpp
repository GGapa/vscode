#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 998244353;

namespace pre {
    constexpr LL qpow(LL x, LL y){
        LL ret = 1;
        for(; y; y >>= 1) {
            if(y & 1) (ret = ret * x % mod);
            (x = x * x % mod) ;
        }
        return ret;
    }

    constexpr LL inv(LL x) {return qpow(x, mod - 2); }
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

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n + 1), cnt(n + 1), vis(n + 1);
    rep(i, 1, n) cin >> A[i];
    for(int i = 1; i <= n; i++) if(!vis[i]) {
        int res = 0;
        for(int j = i; !vis[j]; j = A[j]) vis[j] = 1, res++;
        cnt[res]++;
    }
    LL ans = 1;
    rep(i, 1, n) {
        vector<LL> F(cnt[i] + 1);
        F[0] = 1;
        rep(j, 1, cnt[i]) {
            rep(x, 1, j) if(__gcd(k, i * x) == x) {
                (F[j] += F[j - x] * C(j - 1, x - 1) % mod * qpow(i, x) % mod * binom::fac[x] % mod * inv(x * i % mod) % mod) %= mod;
            }
        }
        (ans *= F[cnt[i]]) %= mod;
    }
    cout << ans << '\n';
} 
/*
F[i][j] 代表长度为 i 的小环用了 j 个的方案数量。
__gcd(k, i * x) = x;5
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    binom::init();
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}