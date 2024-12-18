#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;

LL qpow(LL x, LL y){
    if(x <= 0) return 0;
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
    int n, m; cin >> n >> m;
    LL ans = 0;
    rep(l, 1 ,n) rep(mn, 1, m) rep(mx, mn, (l == 1 ? mn : m)) {
        ans = add(ans, 1ll * (n - l + 1) * add(qpow(mx - mn + 1, l), 2 * -qpow(mx - mn, l)) % mod * qpow(m, n - l) % mod * mn % mod * mx % mod);
        // cout << (n - l + 1) << " " << qpow(n - l, m) << endl;
        /*
        区间在不同的位置，区间内部可能的情况，区间外部可能的情况。
        */
    }
    cout << mul(ans, inv(1ll * (n + 1) * n / 2 % mod * qpow(m, n) % mod)) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
m 的上界时 1e5，肯定直接搞是行不通的，
29/12
*/