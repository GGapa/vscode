#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;

int n, m, s, t;
struct Human {
	int hp;
	string name;
}a[N], b[N];

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

int dinic() {
	int tmp = 0;
	while(bfs()) tmp += dfs(s, INT_MAX);
	return tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	s = 0; t = n * 2 + 1;
	rep(i, 1, n) cin >> a[i].name;
	rep(i, 1, n) cin >> b[i].name;
	rep(i, 1, n) cin >> a[i].hp;
	rep(i, 1, n) cin >> b[i].hp;
	
	int ta, tb;
	ta = tb = 0;
	rep(i, 1, n) {
		ta += (a[i].name == "YYY");
		tb += (b[i].name == "YYY");
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			if((a[i].name == "W" && (b[j].name == "E" || b[j].name == "YYY")) ||
				(a[i].name == "J" && (b[j].name == "W" || b[j].name == "HK")) ||
				(a[i].name == "E" && (b[j].name == "J" || b[j].name == "YYY")) ||
				(a[i].name == "YYY" && (b[j].name == "J" || b[j].name == "HK")) ||
				(a[i].name == "HK" && (b[j].name == "W" || b[j].name == "E"))) {
					add(i, j + n, 1);
				}
		}
	}
	rep(i, 1, n) {
		add(s, i, a[i].hp + (a[i].name == "J" ? ta : 0));
		add(i + n, t, b[i].hp + (b[i].name == "J" ? tb : 0));
	}
	
	cout << min(dinic(), m);
	
	return 0;
}


