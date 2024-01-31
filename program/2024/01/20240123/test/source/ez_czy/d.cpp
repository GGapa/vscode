#include <bits/stdc++.h>
#define PB push_back
#define EB emplace_back
using namespace std;
const int mod = 998244353;
inline int Mod(int x) { return x + ((x >> 31) & mod); }
inline int add(int x, int y) { return Mod(x + y - mod); }
inline int sub(int x, int y) { return Mod(x - y); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
int qpow(int a, int b) {
	if (!b) return 1;
	int t = qpow(a, b >> 1);
	t = mul(t, t);
	if (b & 1) return mul(t, a);
	return t;
}
const int maxn = 900, maxk = 30;
int n, m, k, p, t;
int a[maxn + 5];
struct edge { int v, w; };
vector<edge> g[maxn + 5];
int G[maxn + 5][maxn + 5];
int dfn[maxn + 5], low[maxn + 5];
int stamp;
stack<int> st;
int sq;
vector<int> ng[2 * maxn + 5];
void tarjan(int u) {
	dfn[u] = low[u] = ++stamp;
	st.push(u);
	for (const auto& [v, _] : g[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (dfn[u] == low[v]) {
				sq++;
				ng[sq].PB(u), ng[u].PB(sq);
				int s;
				do {
					s = st.top(); st.pop();
					ng[sq].PB(s), ng[s].PB(sq);
				} while (s != v);
			}
		} else low[u] = min(low[u], dfn[v]);
	}
}
int c[maxk + 5][maxk + 5];
void init() {
    for (int i = 0; i <= k; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
    }
}
struct K {
    int s[maxk + 5];
    K() { memset(s, 0, sizeof(s)); }
    K add(long long v) {
        v %= mod;
        K rs;
        for (int i = 0; i <= k; i++) {
            for (int j = 0, pw = 1; j <= i; j++, pw = mul(pw, v)) rs.s[i] = ::add(rs.s[i], mul(c[i][j], mul(s[i - j], pw)));
        }
        return rs;
    }
    K add(const K& b) {
        K rs;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= i; j++) rs.s[i] = ::add(rs.s[i], mul(c[i][j], mul(s[j], b.s[i - j])));
        }
        return rs;
    }
    void dadd(const K& b) {
        for (int i = 0; i <= k; i++) s[i] = ::add(s[i], b.s[i]);
    }
};
K F[maxn + 5][maxk + 5][2], tF[maxk + 5][2];
K H[2 * maxn + 5][maxk + 5][2][2], tH[maxk + 5][2][2];
int fir[2 * maxn + 5], lst[2 * maxn + 5];
int siz[2 * maxn + 5];
void dfs(int u, int fa) {
    if (u > n) {
        lst[u] = -1;
        for (int v : ng[u])
            if (v != fa) {
                dfs(v, u);
                if (~lst[u]) {
                    for (int i = 0; i <= p; i++) tH[i][0][0] = tH[i][0][1] = tH[i][1][0] = tH[i][1][1] = K();
                    for (int i = 0; i <= siz[u]; i++)
                        for (int j = 0; j <= siz[v] && i + j <= p; j++)
                            for (int s1 = 0; s1 < 2; s1++)
                                for (int s2 = 0; s2 < 2; s2++)
                                    for (int s3 = 0; s3 <= !s2; s3++) {
                                        if (!s2 && !s3) {
                                            tH[i + j][s1][s3].dadd(H[u][i][s1][s2].add(F[v][j][s3].add(G[lst[u]][v])));
                                            tH[i + j + 1][s1][s3].dadd(H[u][i][s1][s2].add(F[v][j][s3].add(G[lst[u]][v] + t)));
                                        } else {
                                            tH[i + j][s1][s3].dadd(H[u][i][s1][s2].add(F[v][j][s3]));
                                            tH[i + j + 1][s1][s3].dadd(H[u][i][s1][s2].add(F[v][j][s3]));
                                        }
                                    }
                    for (int i = 0; i <= p; i++) H[u][i][0][0] = tH[i][0][0], H[u][i][0][1] = tH[i][0][1], H[u][i][1][0] = tH[i][1][0], H[u][i][1][1] = tH[i][1][1];
                    siz[u] += siz[v] + 1;
                } else {
                    fir[u] = v;
                    for (int i = 0; i <= p; i++) {
                        H[u][i][0][0] = F[v][i][0];
                        H[u][i][1][1] = F[v][i][1];
                    }
                    siz[u] += siz[v];
                }
                lst[u] = v;
            }
    } else {
        siz[u] = 1;
        F[u][0][0].s[0] = 1, F[u][1][0].s[0] = 1;
        F[u][0][1].s[0] = 1, F[u][1][1].s[0] = 1;
        F[u][0][1] = F[u][0][1].add(a[u]), F[u][1][1] = F[u][1][1].add(a[u] + t);
        for (int v : ng[u])
            if (v != fa) {
                dfs(v, u);
                for (int i = 0; i <= p; i++) tF[i][0] = tF[i][1] = K();
                if (ng[v].size() == 2) {
                    for (int i = 0; i <= siz[u]; i++)
                        for (int j = 0; j <= siz[v] && i + j <= p; j++)
                            for (int c = 0; c < 2; c++) {
                                tF[i + j + c][0].dadd(F[u][i][0].add(H[v][j][0][0].add(G[u][fir[v]] + c * t)));
                                tF[i + j + c][0].dadd(F[u][i][0].add(H[v][j][1][1]));
                                tF[i + j + c][1].dadd(F[u][i][1].add(H[v][j][0][0]));
                            }
                    siz[u] += siz[v] + 1;
                } else {
                    for (int i = 0; i <= siz[u]; i++)
                        for (int j = 0; j <= siz[v] && i + j <= p; j++)
                            for (int c1 = 0; c1 < 2; c1++)
                                for (int c2 = 0; c2 < 2; c2++) {
                                    tF[i + j + c1 + c2][0].dadd(F[u][i][0].add(H[v][j][0][0].add(0LL + G[u][fir[v]] + G[u][lst[v]] + c1 * t + c2 * t)));
                                    tF[i + j + c1 + c2][0].dadd(F[u][i][0].add(H[v][j][0][1].add(G[u][fir[v]] + c1 * t)));
                                    tF[i + j + c1 + c2][0].dadd(F[u][i][0].add(H[v][j][1][0].add(G[u][lst[v]] + c2 * t)));
                                    tF[i + j + c1 + c2][0].dadd(F[u][i][0].add(H[v][j][1][1]));
                                    tF[i + j + c1 + c2][1].dadd(F[u][i][1].add(H[v][j][0][0]));
                                }
                    siz[u] += siz[v] + 2;
                }
                for (int i = 0; i <= p; i++) F[u][i][0] = tF[i][0], F[u][i][1] = tF[i][1];
            }
    }
}
int main() {
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    scanf("%d%d%d%d%d", &n, &m, &k, &p, &t);
    init();
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].PB({v, w}), g[v].PB({u, w});
        G[u][v] = G[v][u] = w;
    }
    sq = n, tarjan(1);
    dfs(1, 0);
    int ans = add(F[1][p][0].s[k], F[1][p][1].s[k]);
    int fac = 1, ifac = 1;
    for (int i = 1; i <= p; i++) fac = mul(fac, n + m + 1 - i), ifac = mul(ifac, i);
    ans = mul(ans, mul(qpow(fac, mod - 2), ifac));
    printf("%d", ans);
    // fprintf(stderr, "\n %d ms\n", 1000 * clock() / CLOCKS_PER_SEC);
}