#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;
const int N = 120;

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
 
LL C(int x, int y) {
    if(x < 0 || y <= 0 || y - x < 0) return 0;
    return mul(fac[y], mul(iv[x], iv[y - x])) ;
}

void solve() {
    int n; cin >> n;
    vector<int> F(n + 1), G(n + 1) ;
    F[2] = 1, G[2] = 0;
    for(int i = 4; i <= n; i += 2) {
        F[i] = G[i - 2];
        F[i] = add(F[i], C(i / 2 - 1, i - 1)) ;
        G[i] = add(C(i / 2, i), -(F[i] + 1)) ;
    }
    cout << F[n] << " " << G[n] << " " << 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
情况一 Alex 拿到了最大的牌
情况二 Bob 拿到了最大的牌 Alex 没有拿到最大的牌
那么获胜的情况就是 alex n - 2 获胜的情况。
*/