#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 60000 + 5, M = 50000 + 5;
#define int long long

int n, m, s, t;
int tot = 1, head[M], cur[M];
int dep[M];
ll ans;

struct edge {
	int v, nxt;
	ll val;
}e[M * 2];

void add(int u, int v, ll w) {
	e[++tot].v = v;
	e[tot].val = w;
	e[tot].nxt = head[u];
	head[u] = tot;
	
	e[++tot].v = u;
	e[tot].val = 0;
	e[tot].nxt = head[v];
	head[v] = tot;
}

int bfs() {
	queue<int> q;
	memset(dep, 0, sizeof(dep));
	q.push(s);
	dep[s] = 1;
	cur[s] = head[s];
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if(e[i].val > 0 && !dep[v]) {
				q.push(v);
				cur[v] = head[v];
				dep[v] = dep[u] + 1;
				if(v == t) return 1;
			}
		}
	}
	return dep[t];
}

int dfs(int u, ll sum) {
	if(u == t || !sum) return sum;
	ll k, res = 0;
	for(int i = cur[u]; i && sum; i = e[i].nxt) {
		int v = e[i].v;
		cur[u] = i;
		if(e[i].val > 0 && dep[v] == dep[u] + 1) {
			k = dfs(v, min(sum, e[i].val));
			if(k == 0) dep[v] = 0;
			e[i].val -= k;
			e[i^1].val += k;
			res += k;
			sum -= k;
		}
	}
	return res;
}

signed main()  {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	s =  0; t = n + 1;
	rep(i, 1, n) {
		int op;
		cin >> op;
		if(op) add(s, i, 1);
		else add(i, t, 1);
	}
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		add(u, v, 1);
		add(v, u, 1);
	}
	while(bfs()) {
		ans += 	dfs(s, LLONG_MAX);
	}
	cout << ans << '\n';
	return 0;
}
