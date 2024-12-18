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

namespace catalan {
    constexpr int N = 1e6 + 5;
    LL iv[N], C[N];
    void init() {
        iv[1] = 1;
        rep(i, 2, N - 1) iv[i] = 1ll * (mod - mod / i) * iv[mod % i] % mod;
        C[0] = C[1] = 1;
        rep(i, 2, N - 2) C[i] = C[i - 1] * 2 * (2 * i - 1) % mod * iv[i + 1] % mod;
    }
}using catalan::C;