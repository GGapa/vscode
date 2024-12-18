#include <bits/stdc++.h>
#define fi first
#define se second
#define PB push_back
#define EB emplace_back
using namespace std;
const int mod = 1000000007;
inline int Mod(int x) { return x + ((x >> 31) & mod); }
inline int add(int x, int y) { return Mod(x + y - mod); }
inline int sub(int x, int y) { return Mod(x - y); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
const int N = 800;
int n1, n2, q;
vector<int> g1[N + 5], g2[N + 5];
vector<pair<int, int>> g1n[N + 5], g2n[N + 5];
pair<int, int> dfs1(int u) {
    if (u < n1 && g1[u].size() == 1) {
        auto rs = dfs1(g1[u][0]);
        rs.se++;
        return rs;
    }
    for (int v : g1[u]) {
        auto rs = dfs1(v);
        g1n[u].PB(rs);
    }
    return {u, 1};
}
pair<int, int> dfs2(int u) {
    if (u < n2 && g2[u].size() == 1) {
        auto rs = dfs2(g2[u][0]);
        rs.se++;
        return rs;
    }
    for (int v : g2[u]) {
        auto rs = dfs2(v);
        g2n[u].PB(rs);
    }
    return {u, 1};
}
vector<pair<int, int>> tr;
bool chk(int u1, int u2) {
    if (g1n[u1].size() != g2n[u2].size()) return 0;
    for (int i = 0; i < g1n[u1].size(); i++) {
        if (!chk(g1n[u1][i].fi, g2n[u2][i].fi)) return 0;
        tr.EB(g1n[u1][i].se, g2n[u2][i].se);
    }
    return 1;
}
int pw[35][N + 5];
void pmul(int c[], const int a[], const int b[], int sz = n2) {
    for (int i = 0; i <= sz; i++)
        for (int j = 0; i + j <= sz; j++) c[i + j] = add(c[i + j], mul(a[i], b[j]));
}
int nw[N + 5], tmp[N + 5];
int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d%d", &n1, &n2);
    for (int i = 2, f; i <= n1; i++) {
        scanf("%d", &f);
        g1[f].PB(i);
    }
    for (int i = 2, f; i <= n2; i++) {
        scanf("%d", &f);
        g2[f].PB(i);
    }
    g1[++n1].PB(1), g2[++n2].PB(1);
    dfs1(n1), dfs2(n2);
    bool flg = chk(n1, n2);
    scanf("%d", &q);
    vector<int> S;
    for (int i = 1; i <= q; i++) {
        int op, x;
        scanf("%d%d", &op, &x);
        if (op == 1) pw[0][x] = 1;
        else pw[0][x] = 0;
        int ans = 1;
        if (flg) {
            for (int j = 1; j <= 9; j++) {
                memset(pw[j], 0, sizeof(pw[j]));
                pmul(pw[j], pw[j - 1], pw[j - 1]);
            }
            for (const auto& [fr, to] : tr) {
                memset(nw, 0, sizeof(nw));
                nw[0] = 1;
                for (int j = 0; j <= 9; j++)
                    if ((fr >> j) & 1) {
                        memset(tmp, 0, sizeof(tmp));
                        pmul(tmp, nw, pw[j], to);
                        memcpy(nw, tmp, sizeof(nw));
                    }
                ans = mul(ans, nw[to]);
            }
            printf("%d\n", ans);
        } else puts("0");
    }
    // fprintf(stderr, "%d ms\n", 1000 * clock() / CLOCKS_PER_SEC);
}