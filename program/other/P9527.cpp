#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 2e5 + 50;
int mod, n;

vector<int> G[N];
int pa[N];
LL A[N];
LL F[N][41]; int dep[N];

void dfs(int x, int fa) {
    pa[x] = fa; dep[x] = dep[fa] + 1;
    int t = G[x].size() + 1;
    for(auto to : G[x]) if(to != fa) dfs(to, x);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> mod;
    rep(i, 1, n + 41) fill(F[i], F[i] + 41, 1);
    for(int i = 1, u, v; i < n; i ++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
    rep(i, 1, 39) G[i + n].emplace_back(i + n + 1), G[n + i + 1].emplace_back(i + n);
    G[1].emplace_back(n + 1), G[n + 1].emplace_back(1);
    rep(i, 1, n) cin >> A[i];
    int q; cin >> q;
    dfs(n + 40, 0);
    for(int op, x, d, w; q--; ) {
        cin >> op >> x;
        if(op == 1) {
            cin >> d >> w;
            rep(i, 0, d) {
                (F[x][d - i] *= w) %= mod;
                if(d - i - 1 >= 0) (F[x][d - i - 1] *= w) %= mod;
                x = pa[x];
                if(x == 0) break;
            }
        }
        else {
            LL ret = A[x];
            for(int i = 0; i <= 40 && x; i++) {
                (ret *= F[x][i]) %= mod;
                x = pa[x];
            }
            cout << ret << '\n';
        }
    }
    return 0;
}
