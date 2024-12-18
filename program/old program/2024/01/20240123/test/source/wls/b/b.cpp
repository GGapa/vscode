#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 800 + 10, mod = 1e9 + 7;
int n, m, q, T, ed[2][N], len[2][N], dp[N][N], qr0[N], qr1[N], qrc;
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
bool fail;
int nn, mm;
void dfs2(int u0, int u1) {
    int x = ed[0][u0], y = ed[1][u1];
    if (G[0][x].size() != G[1][y].size()) return fail = 1, void();
    qr0[++qrc] = len[0][u0], qr1[qrc] = len[1][u1];
    nn = max(nn, len[0][u0]), mm = max(mm, len[1][u1]);
    for (int i = 0; i < G[0][x].size(); i++) {
        dfs2(G[0][x][i], G[1][y][i]);
    }
}
vector<int> st;
void work() {
    dp[0][0] = 1;
    for (int i = 1; i <= nn; i++) {
        for (int j = 1; j <= mm; j++) {
            dp[i][j] = 0;
            for (auto x : st) {
                if (x > j) break;
                dp[i][j] += dp[i - 1][j - x];
                (dp[i][j] >= mod) && (dp[i][j] -= mod);
            }
        }
    }
}
signed main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    T = max(n, m);
    for (int i = 2, f; i <= n; i++) cin >> f, G[0][f].push_back(i);
    for (int i = 2, f; i <= m; i++) cin >> f, G[1][f].push_back(i);
    dfs(1, 0), dfs(1, 1);
    dfs2(1, 1);
    cin >> q;
    for (int i = 1, op, x; i <= q; i++) {
        cin >> op >> x;
        if (fail) {
            cout << "0\n";
            continue;
        }
        if (n == m) {
            cout << "1\n";
            continue;
        }
        if (op == 1) st.insert(lower_bound(st.begin(), st.end(), x), x);
        else st.erase(lower_bound(st.begin(), st.end(), x));
        work();
        int ans = 1;
        for (int j = 1; j <= qrc; j++) (ans *= dp[qr0[j]][qr1[j]]) %= mod;
        cout << ans << '\n';
    }
    // cerr << clock();
    return 0;
}