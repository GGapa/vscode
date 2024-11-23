#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 400 + 5, mod = 998244353;

int n; 
vector<int> G[N];
int si[N];
int F[N][N][N], H[N][N];

void dfs(int x, int fa) {
    si[x] = 1;
    rep(i, 0, n) F[x][0][i] = 1;
    for(auto to : G[x]) if(to != fa) {
        dfs(to, x);
        rep(i, 0, min(si[x] + si[to], n)) rep(j, 0, n - si[x] - si[to]) H[i][j] = 0;
        rep(i, 0, si[x] - 1) rep(j, 0, n - si[x]) {
            rep(k, 0, si[to] - 1) {
                if(i + k + 1 <= n && j - k - 1 >= 0) (H[i + k + 1][j - k - 1] += 1ll * F[to][k][0] * F[x][i][j] % mod * (k + 1) % mod) %= mod;
                (H[i][j] += 1ll * F[to][k][1 + j + i] * F[x][i][j] % mod * (2 + j + i + k) % mod) %= mod;
            }
        }
        si[x] += si[to];
        rep(i, 0, si[x]) rep(j, 0, n - si[x]) F[x][i][j] = H[i][j];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n; 

    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u) ;
    
    dfs(1, 0);
    LL ans = 0;
    rep(i, 0, n) (ans += 1ll * (i + 1) * F[1][i][0] % mod) %= mod;
    cout << ans << '\n';
    return 0;
}