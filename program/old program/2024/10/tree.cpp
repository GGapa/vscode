#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 100 + 5;

int n, mod; 
vector<int> G[N];
int F[N][N][N], A[N], sz[N], f[N][N][2], g[N][N][2];
/*
F[i][j][k] 代表在 i 为根的子树内 j 个点有有 1 的贡献，k 个点有 A[i] 的贡献。

*/

void dfs(int x,int fa) {
    for(auto to : G[x]) if(to != fa) dfs(to, x);
    rep(ty, 0, 1) { // 根选不选
        memset(f, 0, sizeof (f)) ;
        f[0][0][0] = 1;
        if(ty) f[0][0][1] = A[x];
        sz[x] = ty;
        for(auto to :  G[x]) if(to != fa) {
            memset(g, 0, sizeof(g)) ;
            rep(i, 0, sz[x]) for(int j = 0; j + i <= sz[x]; j++) rep(a, 0, sz[to]) for(int b = 0; b + a <= sz[to]; b++) if(ty){
                rep(k, 0, 1){
                    (g[i + a][j + b][k] += 1ll * f[i][j][k] * F[to][a][b] % mod) %= mod;
                    if(a) (g[i + a - 1][j + b][k] += 1ll * f[i][j][k] * F[to][a][b] % mod * a % mod) %= mod;        // 选取贡献为 1 的元素，这里对方案数计数，
                }
                if(b) (g[i + a][j + b - 1][1] += 1ll * f[i][j][0] * F[to][a][b] % mod * b % mod) %= mod;            // 选取贡献为 A[i] 的元素
            }
            else {
                (g[i + a][j + b][0] += 1ll * f[i][j][0] * F[to][a][b] % mod) %= mod;
            }
            sz[x] += sz[to];
            memcpy(f, g, sizeof(g)) ;
        }
        if(ty) rep(i, 0, sz[x]) for(int j = 0; i + j <= sz[x]; j++) 
            (F[x][i][j] += f[i][j][1]) %= mod;
        else rep(i, 0, sz[x]) for(int j = 0; i + j <= sz[x]; j++) {
            (F[x][i + 1][j] += f[i][j][0]) %= mod;
            (F[x][i][j + 1] += 1ll * f[i][j][0] * A[x] % mod) %= mod;       
        }       // 到这里才是真真的计算所有方案的贡献，乘上贡献
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> mod ;
    rep(i, 1, n) cin >> A[i];
    for(int i = 1, u, v ; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    dfs(1, 0);
    cout << F[1][0][0] << '\n';
    return 0;
}
/*
这道题虽然搞懂了，但是下次碰见了可能还是不知道该怎么推到。。。

*/