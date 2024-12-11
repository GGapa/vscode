#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 800 + 10, mod = 1e9 + 7;
int n, m, q, T, f[2][N], ed[2][N], len[2][N];
vector<int> G[2][N];
void dfs(int u, bool t) {
    for (auto v : G[t][u]) dfs(v, t);
    if (G[t][u].size() == 1) {
        int v = G[t][u][0];
        ed[t][u] = ed[t][v], len[t][u] = len[t][v] + 1;
    } else {
        ed[t][u] = u, len[t][u] = 1;
    }
}
int dp[N][N], C[N][N];
int dfs2(int u0, int u1) {
    int x = ed[0][u0], y = ed[1][u1];
    if (G[0][x].size() != G[1][y].size()) {
        return 0;
    }
    ll ans = dp[len[0][u0]][len[1][u1]];
    for (int i = 0; i < G[0][x].size(); i++) {
        ans *= dfs2(G[0][x][i], G[1][y][i]);
        ans %= mod;
    }
    return ans;
}
void add(int x) {
    for (int i = n; i >= 1; i--) {
        for (int j = x; j <= m; j++) {
            for (int k = 1; k <= i && k * x <= j; k++) {
                (dp[i][j] += dp[i - k][j - k * x] * C[i][k] % mod);
                (dp[i][j] >= mod) && (dp[i][j] -= mod);
            }
        }
    }
}
void del(int x) {
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= x; j--) {
            for (int k = min(i, j / x); k >= 1; k--) {
                (dp[i][j] += mod - dp[i - k][j - k * x] * C[i][k] % mod);
                (dp[i][j] >= mod) && (dp[i][j] -= mod);
            }
        }
    }
}
int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    T = max(n, m);
    for (int i = 0; i <= T; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    for (int i = 2; i <= n; i++) cin >> f[0][i], G[0][f[0][i]].push_back(i);
    for (int i = 2; i <= m; i++) cin >> f[1][i], G[1][f[1][i]].push_back(i);
    dfs(1, 0), dfs(1, 1);
    dp[0][0] = 1;
    cin >> q;
    for (int i = 1, op, x; i <= q; i++) {
        cin >> op >> x;
        if (op == 1) add(x);
        else del(x);
        cout << dfs2(1, 1) << '\n';
    }
    cerr << clock();
    return 0;
}