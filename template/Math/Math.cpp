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

namespace pre {
    template <typename T>
    constexpr T qpow(T x, LL y){
        T ret(1);
        for(; y; y >>= 1) {
            if(y & 1) (ret = ret * x );
            (x = x * x  ) ;
        }
        return ret;
    }

    template <typename T>
    constexpr T inv(T x) {return qpow(x, mod - 2); }
}   
using namespace pre;

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