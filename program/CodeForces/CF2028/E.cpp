#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 998244353, N = 2e5 + 5;

int n;
vector<int> G[N];
LL F[N], g[N], dep[N];

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}
 
LL inv(int x) {return qpow(x, mod - 2); }



void dfs1(int x, int fa) {
    if(x == 1 || G[x].size() > 1) dep[x] = n + 1;
    else dep[x] = 0;
    for(auto to : G[x]) if(to != fa) {
        dfs1(to, x);
        dep[x] = min(dep[x], dep[to] + 1);
    }
}

void dfs2(int x, int fa) {
    if(x == 1) F[x] = 1;
    else F[x] = F[fa] * inv(dep[x] + 1) % mod * dep[x] % mod;
    for(auto to : G[x]) if(to != fa) dfs2(to, x);
}

void solve() {
    cin >> n;
    fill(F + 1, F + 1 + n, 0); fill(g + 1, g + 1 + n, 0); fill(dep, dep + 1 + n, 0);
    rep(i, 0, n) vector<int>(0).swap(G[i]);
    for(int i = 1, u, v; i < n; i++)
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    dfs1(1, 0);
    dfs2(1, 0);
    rep(i, 1, n) cout << (F[i] + mod) % mod << " \n"[i == n];
}


signed main() {
    // cerr << 2 * inv(3) % mod << '\n';
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}