#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}
 
LL inv(int x) {return qpow(x, mod - 2); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<LL> p(n + 1), F = p;
    rep(i, 1, n) {
        int x, y; cin >> x >> y; x = y - x;
        F[i] = (F[i - 1] + 1) * y % mod * inv(x) % mod;
    }
    cout << F[n] << '\n';
    return 0;
}