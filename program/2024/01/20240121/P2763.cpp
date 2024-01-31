#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int k, n, m, s, t;
int dep[N];

struct edge {
	int v, nxt, val;
}e[N];
int tot = 1, head[N];


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
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if(e[i].val > 0 && !dep[v]) {
				q.push(v);
				dep[v] = dep[u] + 1;
			}
		}
	}
	return dep[t];
}


int dfs(int u, int sum) {
	if(u == t || !sum) return sum;
	int k, res = 0;
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(e[i].val > 0 && dep[v] == dep[u] + 1) {
			k = dfs(v, min(sum, e[i].val));
			if(k == 0) dep[v] = 0;
			e[i].val -= k;
			e[i^1].val += k;
			res += k;
			sum -= k;
			if(res == sum) return res;
		}
	}
	return res;
}

int dinic() {
	int tmp = 0;
	while(bfs()) tmp += dfs(s, INT_MAX);
	return tmp;
}

void print(int u){
	for(int i = head[u]; i; i = e[i].nxt){
		int v = e[i].v;
		if(e[i].val && v <= n){
			cout << v << " ";
		}
	}
	cout << '\n';
}

int main()  {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> k >> n;
	s = n + k + 1;
	t = s + 1;
	rep(i, 1, k) {
		int w;
		cin >> w;
		m += w;
		add(n + i, t, w);
	}
	rep(i, 1, n) {
		int p;
		cin >> p;
		add(s, i, 1);
		rep(j, 1, p) {
			int v;
			cin >> v;
			add(i, v + n, 1);
		}
	}
	if(dinic() == m) {
		rep(i, 1, k) {
			cout << i << ": ";
			print(i + n);
		}
	}
	else cout << "No Solution!\n";
	return 0;
}

