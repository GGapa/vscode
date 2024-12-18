#include<bits/stdc++.h>

#define mp make_pair
#define int long long

using namespace std;
template<class T> T gi() {
	T x = 0; bool f = 0; char c = getchar();
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	if (c == '-') f = 1, c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f ? -x : x;
}
const int N = 3010, inf = 1e18;
struct node { int to, nxt, w, v; } g[N << 1];
int lst[N], gl;
void add(int x, int y, int z, int v) { g[++gl] = (node) {y, lst[x], z, v}; lst[x] = gl; }
int dis[N][N];
void bfs(int S) {
	queue<int> q; q.push(S); dis[S][S] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = lst[u]; i; i = g[i].nxt)
			if (dis[S][g[i].to] == -1)
				dis[S][g[i].to] = dis[S][u] + g[i].w, q.push(g[i].to);
	}
}
int f[N][N], F[N], L[N], R[N], tim;
void dfs(int u, int ff) {
	L[u] = ++tim;
	for (int i = lst[u]; i; i = g[i].nxt)
		if (g[i].to != ff)
			dfs(g[i].to, u);
	R[u] = tim;
}
int n, d;
void dfs2(int u, int ff) {
	for (int i = 1; i <= n; i++)
		if (dis[u][i] > d) f[u][i] = -inf;
		else f[u][i] = 0;
	for (int i = lst[u]; i; i = g[i].nxt) {
		int v = g[i].to; if (v == ff) continue;
		dfs2(v, u);
		if(u == 1) 
				u++, u--; 
		for (int j = 1; j <= n; j++)
			if (dis[u][j] <= d) {
				if (L[v] <= L[j] && L[j] <= R[v])
					f[u][j] += f[v][j] + g[i].v;
				else f[u][j] += max(F[v], f[v][j] + g[i].v);
			}
	}
	F[u] = -inf;
	for (int i = 1; i <= n; i++)
		if (L[u] <= L[i] && L[i] <= R[u])
			F[u] = max(F[u], f[u][i]);
}
void solve() {
	n = gi<int>(), d = gi<int>();
	memset(lst, 0, sizeof(lst)); gl = 0; memset(dis, -1, sizeof(dis));
	for (int i = 1; i < n; i++) {
		int x = gi<int>(), y = gi<int>(), z = gi<int>(), v = gi<int>();
		add(x, y, z, v), add(y, x, z, v);
	}
	for (int i = 1; i <= n; i++) bfs(i);
	tim = 0; dfs(1, 0); dfs2(1, 0);
	// for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cout << dis[i][j] << " \n"[j == n];
	printf("%lld\n", F[1]);
}
signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int T = gi<int>();
	while (T--) solve();
	return 0;
}