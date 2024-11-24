namespace Math {
    namespace pre {
        template <typename T>
        constexpr T qpow(T x, int y){
            T ret = 1;
            for(; y; y >>= 1) {
                if(y & 1) (ret = ret * x) %= mod;
                (x = x * x) %= mod;
            }
            return ret;
        }
 
        template <typename T>
        constexpr T inv(T x) {return qpow(x, mod - 2); }
    }   
    using namespace pre;
 
    constexpr LL add(const LL x, const LL y) {return (x + y + mod) % mod; }
    constexpr LL mul(const LL x, const LL y) {return (x * y % mod + mod) % mod; }
 
    LL fac[N], iv[N];
 
    void init() {
        fac[0] = 1;
        rep(i, 1, N - 1) fac[i] = mul(fac[i - 1], i);
        iv[N - 1] = inv(fac[N - 1]); 
        per(i, N - 2, 0) iv[i] = mul(iv[i + 1], i + 1) ;
    }
 
    LL C(int y, int x) {
        if(x < 0 || y < 0 || y - x < 0) return 0;
        return mul(fac[y], mul(iv[x], iv[y - x])) ;
    }   
}
using Math::C; 
using namespace Math::pre;