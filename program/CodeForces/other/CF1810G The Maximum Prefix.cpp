#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 1e9 + 7;

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

void solve() {
    int n; cin >> n;
    vector<int> p(n + 1);
    for(int i = 1, x, y; i <= n; i++) 
        cin >> x >> y, p[i] = mul(x, inv(y)) ;
    vector<VI> F(n + 1, VI(n + 1)) ;
    rep(i, 0, n) cin >> F[0][i] ;
    rep(i, 1, n) rep(j, 0, n)   
        F[i][j] = add(mul(p[i], F[i - 1][j + 1]), mul((1 - p[i] + mod) % mod, F[i - 1][max(j - 1, 0)])) ;
    rep(i, 1, n) cout << F[i][0] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}