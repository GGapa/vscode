#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353, N = 1000 + 5;

int n, m, sumx, sumy, sump, dp[N * N], sumdp, x, y, tot;
struct point { int x, y, val; } ;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}
LL add(LL &x, LL y) {
    return x = (x + y + mod) % mod;
} 
 
LL inv(int x) {return qpow(x, mod - 2); }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<point> p(1);
    rep(i, 1, n) rep(j, 1, m)  {
        int x; cin >> x;
        p.push_back({i, j, x});
    }
    int x, y; cin >> x >> y;
    sort(p.begin() + 1, p.end(), [](const point& A, const point& B) { return A.val < B.val; });
    for (int i = 1, l = 1; i <= n * m; i++) {
        dp[i] = 0;
        if (p[i].val != p[l].val)
            for (; l < i; l++) add(sumx, p[l].x), add(sumy, p[l].y), add(sump, p[l].x * p[l].x + p[l].y * p[l].y), add(sumdp, dp[l]);
        int n = l - 1;
        add(dp[i], (LL)(n) * (p[i].x * p[i].x % mod + p[i].y * p[i].y % mod) % mod);
        add(dp[i], mod - 2 * ((LL)(p[i].x) * sumx % mod + static_cast<LL> (p[i].y) * sumy % mod) % mod);
        add(dp[i], (sump + sumdp) % mod);
        dp[i] = 1ll * dp[i] * inv(n) % mod;
        if (p[i].x == x && p[i].y == y) {
            cout << dp[i] << '\n';
            return 0;
        }
    }
    return 0;
}