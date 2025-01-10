#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

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
    constexpr int N = 1e6 + 5;
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

constexpr int N = 3000 + 5;

int n;
int F[N][N];    // F[x][i] 在以 x 为根节点的子树中，大小排名为 i（相对关系对我们来说非常重要）
int sz[N], sum[N], g[N];
vector<int> G[N];

void dfs(int x, int fa, bool tag) {
    sz[x] = F[x][1] = 1;
    for(auto to : G[x]) if(to != fa) {
        dfs(to, x, tag ^ 1);
        rep(i, 1, sz[to]) sum[i] = (sum[i - 1] + F[to][i]) % mod;
        fill(g, g + 1 + sz[x] + sz[to], 0);
        rep(i, 1, sz[x]) {
            rep(j, i, i + sz[to]) {
                if(tag) (g[j] += 1ll * F[x][i] * (sum[sz[to]] - sum[j - i] + mod) % mod * C(j - 1, i - 1) % mod * C(sz[x] + sz[to] - j, sz[x] - i) % mod) %= mod;
                else (g[j] += 1ll * F[x][i] * sum[j - i] % mod * C(j - 1, i - 1) % mod * C(sz[x] + sz[to] - j, sz[x] - i) % mod) %= mod;
            }
        }
        sz[x] += sz[to];
        rep(i, 0, sz[x]) F[x][i] = g[i];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    binom::init();
    cin >> n;
    for(int i = 1, u, v; i < n; i++)    
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    dfs(1, 0, 0);
    int sum = 0;
    rep(i, 1, n) (sum += F[1][i]) %= mod;
    cout << sum * 2 % mod;
    return 0;
}