#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 1e3 + 5, K = 6, mod = 1e9 + 7;

int n, k;
int F[N][N * K][K], g[N * K][K], ans[N * K], sz[N];
vector<int> G[N];

void dfs(int x, int fa) {
    sz[x] = 1;
    rep(i, 1, k) F[x][0][i] = 1;
    for(auto to : G[x]) if(to != fa) {
        dfs(to, x);
        rep(i, 0, sz[x] * k) rep(j, 0, k) g[i][j] = F[x][i][j], F[x][i][j] = 0;
        rep(i, 0, sz[x] * k) rep(j, 0, k) if(g[i][j]) 
            rep(a, 0, sz[to] * k) rep(b, 0, k) if(F[to][a][b]) 
                (F[x][i + a + b][max(0, j - b)] += 1ll * g[i][j] * F[to][a][b] % mod) %= mod;
        sz[x] += sz[to];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    dfs(1, 0);
    rep(i, 0, n * k) rep(j, 0, k) (ans[i + j] += F[1][i][j]) %= mod;
    rep(i, 1, n * k) cout << ans[i] << "\n";
    return 0;
}