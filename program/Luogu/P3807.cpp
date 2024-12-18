#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 6;
int mod;

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
 
LL fac[N], iv[N];
 
void init() {
    fac[0] = 1;
    rep(i, 1, mod - 1) fac[i] = mul(fac[i - 1], i);
    iv[mod - 1] = inv(fac[mod - 1]); 
    per(i, mod - 2, 0) iv[i] = mul(iv[i + 1], i + 1) ;
}
 
LL C(int x, int y) {
    if(x < 0 || y < 0 || y < x) return 0;
    return mul(fac[y], mul(iv[x], iv[y - x])) ;
}

LL lucas(int x, int y) {
    if(!x) return 1;
    return C(x % mod, y % mod) * lucas(x / mod, y / mod) % mod;
}

void solve() {
    int n, m; cin >> n >> m  >> mod;
    init() ;
    cout << lucas(m, n + m) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
