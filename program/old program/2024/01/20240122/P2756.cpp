#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1e6;

int n, m, s, t;

struct edge {
	int u, v, val, nxt;
}e[N];
int tot = 1, head[N], cur[N];
int dep[N];

void add(int u, int v, int w) {
	e[++tot] = (edge){u, v, w, head[u]};
	head[u] = tot;
	e[++tot] = (edge){v, u, 0, head[v]};
	head[v] = tot;
}

bool bfs() {
	memset(dep, 0, sizeof(dep));
	queue<int> q;
	q.push(s);
	dep[s] = 1;
	cur[s] = head[s];
	while(!q.empty()) {
		int u = q.front() ;q.pop();
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if(e[i].val && !dep[v]) {
				cur[v] = head[v];
				dep[v] = dep[u] + 1;
				q.push(v);
				if(v == t) return 1;
			}
		}
	}
	return dep[t];
}

int dfs(int u, int sum) {
	if(!sum || u == t) return sum;
	int k, res = 0;
	for(int i = cur[u]; i && sum; i = e[i].nxt) {
		int v = e[i].v;
		cur[u] = i;
		if(e[i].val && dep[v] == dep[u] + 1) {
			k = dfs(v, min(sum, e[i].val));
			if(k == 0) dep[v] = 0;
			e[i].val -= k;
			e[i^1].val += k;
			sum -= k;
			res += k; 
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	s = 0, t = m + 1;
	rep(i, 1, n) 
		add(s, i, 1);
	rep(i, n + 1, m) 
		add(i, t, 1);
	int t1, t2;
	while(1){
		cin >> t1 >> t2;
		if(t1 == -1) break;
		add(t1, t2, 1);
	}
	int ans = 0;
//	memcpy(cur, head, sizeof(cur));
	while(bfs()) ans += dfs(s, INT_MAX);
	cout << ans << '\n';

	for(int i = 3; i <= tot; i += 2) {
		if(e[i].u != t && e[i].v != s && e[i].val == 1) cout << e[i].v << ' ' << e[i].u << '\n';
	}
	
	return 0;
}


