#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
typedef long long lld;
using namespace std;
const int N = 910, M = 1810;
const int mod = 998244353;
inline int qpow(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = 1ll * a * a % p)
		if (b & 1) ret = 1ll * ret * a % p;
	return ret;
}
int n, m, k, p, t;
int a[N];
vector<int> G[N];
int W[N][N], us[M], vs[M], ws[M];
bool vis[N];
int sum2, sum, ans, cnt;
inline void dfs(int u) {
	if (u > n) {
		sum2 = (sum2 + qpow(sum, k, mod)) % mod;
		return;
	}
	dfs(u + 1);
	for (int v : G[u]) if (vis[v]) { return; }
	vis[u] = 1;
	sum = (sum + a[u]) % mod;
	for (int v : G[u]) sum = (sum + mod - W[u][v]) % mod;
	dfs(u + 1);
	for (int v : G[u]) sum = (sum + W[u][v]) % mod;
	sum = (sum + mod - a[u]) % mod;
	vis[u] = 0;
}
inline void dfs(int u, int res) {
	if (u > n + m) {
		if (!res) {
			sum2 = sum = 0;
			for (int i = 1; i <= m; ++ i) sum = (sum + ws[i]) % mod;
//			for (int i = 1; i <= n; ++ i) printf("%d ", a[i]); puts("");
//			for (int i = 1; i <= n; ++ i, puts(""))
//				for (int j = 1; j <= n; ++ j)
//					printf("%d ", W[i][j]);
			dfs(1);
			ans = (ans + sum2) % mod;
			++ cnt;
		}
		return;
	}
	if (u <= n) {
		dfs(u + 1, res);
		if (res) {
			a[u] = (a[u] + t) % mod;
			dfs(u + 1, res - 1);
			a[u] = (a[u] + mod - t) % mod;
		}
	} else {
		dfs(u + 1, res);
		if (res) {
			ws[u - n] = (ws[u - n] + t) % mod;
			W[us[u - n]][vs[u - n]] = W[vs[u - n]][us[u - n]] = ws[u - n];
			dfs(u + 1, res - 1);
			ws[u - n] = (ws[u - n] + mod - t) % mod;
			W[us[u - n]][vs[u - n]] = W[vs[u - n]][us[u - n]] = ws[u - n];
		}
	}
}
int main() {
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &m, &k, &p, &t);
	for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
	for (int i = 1, u, v, w; i <= m; ++ i) {
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back(v);
		G[v].push_back(u);
		W[u][v] = W[v][u] = w;
		us[i] = u, vs[i] = v, ws[i] = w;
	}
	dfs(1, p);
	printf("%lld\n", 1ll * ans * qpow(cnt, mod - 2, mod) % mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
