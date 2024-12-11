#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int M = 1e7;

int T, s, t, n, m, cnt;
int a[N], b[N], p[N], vis[M], dep[N];

struct edge {
	int v, nxt, val;
}e[N];
int head[N], cur[N], tot = 1;

void add(int u, int v, int w) {
	e[++tot] = (edge){v, head[u], w};
	head[u] = tot;
	e[++tot] = (edge){u, head[v], 0};
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

int dfs(int u, int sum) {
	if(u == t || !sum) return sum;
	int k, res = 0;
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

int dinic() {
	int tmp = 0;
	while(bfs()) tmp += dfs(s, INT_MAX) ;
	return tmp;
}

void cnnt1(int x, int id) {
	for(int i = 1; p[i] <= x; i++) {
		if(x % p[i] == 0) {
			add(id, n + m + i, 2e9);
			t = max(t, n + m + i);
			while(x % p[i] == 0) x /= p[i];
		}
	}
}

void cnnt2(int x, int id) {
	for(int i = 1; p[i] <= x; i++) {
		if(x % p[i] == 0) {
			add(n + m + i, id, 2e9);
			t = max(t, n + m + i);
			while(x % p[i] == 0) x /= p[i];
		}
	}
}


void solve() {
	cin >> n >> m;
	rep(i, 1, n) {
		cin >> a[i];
		cnnt1(a[i], i);
	}	
	rep(i, 1, m) {
		cin >> b[i];
		cnnt2(b[i], i + n);
	}
	s = 0; t++;
	rep(i, 1, n) add(s, i, 1);
	rep(i, 1, m) add(i + n, t, 1);
	cout << dinic() << endl;
}

void init() {
	tot = 1;
	memset(cur, 0, sizeof(cur));
	memset(e, 0, sizeof(e));
	memset(head, 0, sizeof(head));
	
}

void getprime() {
    for (int i = 2; i <= M; i++) {
        if (!vis[i]) p[++p[0]] = i;
        for (int j = 1; j <= p[0] && i * p[j] <= M; j++) {
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

int main()  {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	getprime();
	cin >> T;
	while(T--) {
		init();
		solve();
	}
	return 0;
}
