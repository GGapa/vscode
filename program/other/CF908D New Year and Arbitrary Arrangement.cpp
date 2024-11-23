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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL k, pa, pb; cin >> k >> pa >> pb;
    LL A = pa * inv((pb + pa) % mod) % mod;
    LL B = pb * inv((pb + pa) % mod) % mod;
    LL C = pa * inv(pb) % mod;
    vector<VI> F(k + 2, VI(k + 2));
    per(i, k, 1) per(j, k, 0) {
        if(i + j >= k) F[i][j] = (i + j + C) % mod;
        else (F[i][j] = A * F[i + 1][j] % mod + B * F[i][j + i] % mod) %= mod;
    }
    cout << F[1][0] << '\n';
    return 0;
}