#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
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
    int n, m, ax, ay, bx, by, p; cin >> n >> m >> ax >> ay >> bx >> by >> p;
    int pp = mul(100 - p, inv(100));
    p = mul(p, inv(100));
    int u = 0, v = 1;
    int dx, dy; dx = dy = -1;
    rep(i, 1, 4 * (n - 1) * (m - 1)) {
        if(ax + dx > n || ax + dx < 1) dx = -dx;
        if(ay + dy > m || ay + dy < 1) dy = -dy;
        ax += dx; ay += dy;
        u = (u + 1) % mod;
		if(ax == bx || ay == by) u = u * pp % mod, v = v * pp % mod;
    }
    cout << mul(u, inv(1 - v + mod)) << '\n';   
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}