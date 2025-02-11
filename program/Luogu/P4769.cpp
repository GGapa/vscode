#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int mod = 998244353;

namespace pre {
    constexpr LL qpow(LL x, LL y){
        LL ret = 1;
        for(; y; y >>= 1) {
            if(y & 1) (ret = ret * x % mod);
            (x = x * x % mod) ;
        }
        return ret;
    }

    constexpr LL inv(LL x) {return qpow(x, mod - 2); }
}   
using namespace pre;

namespace binom {
    constexpr int N = 4e6 + 5;
    LL fac[N], iv[N];
 
    void init() {
        fac[0] = 1;
        rep(i, 1, N - 1) fac[i] = fac[i - 1] * i % mod;
        iv[N - 1] = inv(fac[N - 1]); 
        per(i, N - 2, 0) iv[i] = iv[i + 1] * (i + 1) % mod;
    }
 
    LL C(int y, int x) {
        if(x < 0 || y < 0 || y - x < 0) return 0;
        return fac[y] * iv[x] % mod * iv[y - x] % mod;
    }  
}
using binom::C; 

void solve() {
    int n; cin >> n;
    auto F = [&](int i, int j) {
        return i <= n && j <= n ? (C(2 * n - i - j - 1, n - i - 1) - C(2 * n - i - j - 1, n - j - 2) + mod) % mod : 0;
    };
    int ans = 0;
    vector<int> vis(n + 1);
    for(int i = 1, x, tag = 0, mx = 0, mn = 1; i <= n; i++) {
        cin >> x;
        if(tag) continue;
        (ans += F(i - 1, max(mx, x) + 1)) %= mod;
        if(mn < x && x < mx) tag = 1;
        mx = max(mx, x);
        vis[x] = 1;
        while(vis[mn]) mn++;
    }
    cout << ans << '\n';
}

signed main() {
    binom::init();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}