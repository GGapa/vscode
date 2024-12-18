#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1e7 + 5;

int n, m, s, t, sum = 0, it = 1;

struct edge {
	int v, nxt, val;
}e[N];
int head[N], cur[N], tot = 1;
int dep[N];

void add(int u, int v, int w) {
	e[++tot] = (edge){v, head[u], w};
	head[u] = tot;
	e[++tot] = (edge){u, head[v], 0};
	head[v] = tot;
}

bool bfs() {
	memset(dep, 0, sizeof(dep));
	queue<int> q;
	dep[s] = 1;
	cur[s] = head[s];
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if(e[i].val && !dep[v]) {
				q.push(v);
				cur[v] = head[v];
				dep[v] = dep[u] + 1;
				if(t == v) return 1;
				
			}
		}
	}
	return dep[t];
}

int dfs(int x, int sum) {
	if(x == t || sum == 0) return sum;
	int k, res = 0;
	for(int i = cur[x]; i && sum ; i = e[i].nxt) {
		int v = e[i].v;
		cur[x] = i;
		if(e[i].val && dep[v] == dep[x] + 1) {
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
	while(bfs()) tmp += dfs(s, INT_MAX);
	return tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	s = 0, t = 1e6;
	rep(i, 1, n) {
		int a;
		cin >> a;
		add(s, i, a);
		sum += a;
	}
	rep(i, 1, n) {
		int a;
		cin >> a;
		add(i, t, a);
		sum += a;
	}
	cin >> m;
	rep(i, 1, m) {
		int k;
		cin >> k;
		int c1, c2;
		cin >> c1 >> c2;
		sum += c1 + c2;
		add(s, n + it, c1);
		add(n + it + 1, t, c2);
		rep(i, 1, k) {
			int ki;
			cin >> ki;
			add(n + it, ki, 2e9);
			add(ki, n + it + 1, 2e9);
		}
		it += 2;
	}
//	cout << sum << endl;
	cout << sum - dinic() << '\n';
	
	return 0;
}


