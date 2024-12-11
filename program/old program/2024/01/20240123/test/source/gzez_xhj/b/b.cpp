#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <set>
typedef long long lld;
using namespace std;
#define fir first
#define sec second
const int mod = 1e9 + 7;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int base = 1453;
const int N = 810;
inline int qpow(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = 1ll * a * a % p)
		if (b & 1) ret = 1ll * ret * a % p;
	return ret;
}
int n, m;
struct tree {
	vector<int> G[N], ch[N];
	int cnt[N];
	inline void addedge(int u, int v) {
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int fa[N], dep[N], siz[N];
	inline void dfs0(int u, int f) {
		dep[u] = dep[fa[u] = f] + (siz[u] = 1);
		if (f) ch[f].push_back(u);
		for (int v : G[u]) if (v != f) dfs0(v, u), siz[u] += siz[v];
	}
	pair<int, int> hash[N];
	inline pair<int, int> hash_tree(int u) {
		pair<int, int> ret = make_pair(siz[u], siz[u]), res;
		for (int v : ch[u]) {
			res = hash_tree(v);
			ret.fir = (1ll * ret.fir * base % mod1 + res.fir) % mod1;
			ret.sec = (1ll * ret.sec * base % mod2 + res.sec) % mod2;
		}
		return hash[u] = ret;
	}
} T1, T2, t1, t2;
inline void build(const tree &T, tree &t, int u, int tp) {
	++ t.cnt[tp];
	if (T.ch[u].size()) {
		if (T.ch[u].size() == 1) build(T, t, T.ch[u][0], tp);
		else for (int v : T.ch[u]) build(T, t, v, v), t.addedge(tp, v);
	}
}
int to[N];
inline bool calcto(int u, int v) {
	if (t1.ch[u].size() != t2.ch[v].size()) return 0;
	to[u] = v;
	for (int i = 0; i < t1.ch[u].size(); ++ i)
		if (!calcto(t1.ch[u][i], t2.ch[v][i])) return 0;
	return 1;
}
set<int> s; vector<int> v;
int f[N][N]; int vis[N][N];
inline int calc(int i, int j, int t) {
	if (!i) return !j;
	if (i > j) return 0;
	if (vis[i][j] == t) return f[i][j];
	vis[i][j] = t;
	int ret = 0;
	for (int k : v)
		if (k > j) break;
		else ret = (ret + calc(i - 1, j - k, t)) % mod;
	return f[i][j] = ret;
}
int main() {
//	freopen("ex_b3.in", "r", stdin);
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 2, p; i <= n; ++ i) scanf("%d", &p), T1.addedge(i, p);
	for (int i = 2, p; i <= m; ++ i) scanf("%d", &p), T2.addedge(i, p);
	T1.dfs0(1, 0), T2.dfs0(1, 0);
	build(T1, t1, 1, 1), t1.dfs0(1, 0);
	build(T2, t2, 1, 1), t2.dfs0(1, 0);
	int q;
	scanf("%d", &q);
	if (!calcto(1, 1)) {
		for (; q --; ) puts("0");
		return 0;
	}
	int mx1 = 0, mx2 = 0;
	for (int i = 1; i <= n; ++ i) mx1 = max(mx1, t1.cnt[i]);
	for (int i = 1; i <= n; ++ i) mx2 = max(mx2, t2.cnt[to[i]]);
	for (int op, x, cs = 1; cs <= q; ++ cs) {
		scanf("%d%d", &op, &x);
		if (op == 1) s.insert(x); else s.erase(x);
		v.clear(); for (int i : s) v.push_back(i);
		int ans = 1;
		for (int i = 1; i <= n; ++ i) {
			ans = 1ll * ans * calc(t1.cnt[i], t2.cnt[to[i]], cs) % mod;
			if (!ans) break;
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
