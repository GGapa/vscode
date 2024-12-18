#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5, mod = 998244353;

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
    int n; cin >> n;
    vector<int> cnt(n + 1);
    for(int i = 1, x; i <= n; i++) 
        cin >> x, cnt[x]++;

    vector<int> suf(n + 3);
    suf[n] = 1;
    per(i, n, 1) (suf[i - 1] = 1ll * suf[i] * qpow(2, cnt[i ]) % mod) %= mod;

    LL ans = 0;
    auto g = cnt;
    vector<int> F(n + 1);
    int it = 0;
    per(k, n, 1) {
        while(it < n && cnt[it] >= k) it++;
        int res = 1;
        rep(i, 0, it - 1) {
            while(g[i] >= k) {
                (F[i] += C(cnt[i], g[i])) %= mod;
                g[i]--;
            }
            res = 1ll * res * F[i] % mod;
            (ans += 1ll * res * suf[i] % mod) %= mod;
        }
        // cerr << it << '\n';
    }
    cout << ans << '\n';
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

*/