#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353, N = 3e5 + 5;

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
    rep(i, 1, N - 1) fac[i] = mul(fac[i - 1], i);
    iv[N - 1] = inv(fac[N - 1]); 
    per(i, N - 2, 0) iv[i] = mul(iv[i + 1], i + 1) ;
}
 
LL C(int y, int x) {
    if(x < 0 || y < 0 || y - x < 0) return 0;
    return mul(fac[y], mul(iv[x], iv[y - x])) ;
}

void solve() {
    init();
    int n; cin >> n;
    n /= 3;
    LL ans = 1;
    int tp = 2;
    rep(ttt, 1, n) {
        vector<int> A(3);
        for(auto &a : A) cin >> a;
        int mx = 0, cnt = 0;
        rep(s, 1, 7) if(__builtin_popcount(s) == tp){
            int sum = 0;
            rep(i, 0, 2) {
                int j = (i + 1) % 3;
                if((s >> i & 1) != (s >> j & 1)) sum += A[i];
            }
            if(sum == mx) cnt++;
            else if(sum > mx) mx = sum, cnt = 1;
        }
        tp = 3 - tp;
        (ans *= cnt) %= mod;
    }
    cout << ans * C(n, n / 2) % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    while(T--) solve();
    return 0;
}