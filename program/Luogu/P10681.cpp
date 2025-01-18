#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 1e9 + 7;

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
using binom::fac;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    binom::init();

    int n, m; cin >> n >> m;
    
    LL ans = 0;
    rep(a, 0, n) {
        int b, c, d; 
        b = n - a;
        d = a + b * 2 - m; 
        c = m - d;
        // cerr << a << " " << b << " " << c << " " << d << '\n';
        if(c < 0 || d < 0 || a + 2 * b != c + 2 * d) continue;
         
        LL res = 0;
        rep(k, 0, min(b, d)) {
            LL tp = (k & 1 ? mod - 1 : 1);
            (tp *= C(b, k) * C(d, k) % mod * fac[k] % mod) %= mod;
            (tp *= fac[c + 2 * d - k * 2]) %= mod;
            (tp *= inv(qpow(2, b + d - k)) % mod) %= mod;
            (res += tp) %= mod;
        }
        (ans += C(n, a) * C(m, c) % mod * res % mod) %= mod;
        // c + 2d == a + 2b  c + d = m 
    }

    cout << ans << '\n';

    return 0;
}
/*
0 2 0 2
1 1 1 1
2 0 2 0
*/
/*
500000005
1000000006
500000004
500000005
500000003
2
*/