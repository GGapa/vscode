#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e6 + 5, mod = 1e8 + 7; 

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int pw2 = 1;
    rep(i, 1, n) pw2 = mul(pw2, 2) ;
    pw2 = (pw2 - 1 + mod) % mod;
    vector<int> F(m + 1), A(m + 1);

    A[0] = 1;
    LL mx = 1;
    rep(i, 1, m) A[i] = mul(A[i - 1], ((pw2 - i + 1 + mod) % mod)), mx = mul(mx, i);

    F[F[1] = 0] = 1;
    rep(i, 2, m) F[i] = add(add(A[i - 1], -F[i - 1]), -1 * mul((pw2 - i + 2 ), mul(F[i - 2], i - 1)));

    cout << mul(F[m], inv(mx)) << '\n';
    return 0;
}