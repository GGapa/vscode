#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1e7;

int r, c, d, s, t;
struct edge {
	int v, val, nxt;
}e[N];
int head[N], cur[N], tot = 1;
int dep[N];
int mp[100][100];

void add(int u, int v, int w) {
	e[++tot] = (edge){v, w, head[u]};
	head[u] = tot;
	e[++tot] = (edge){u, 0, head[v]};
	head[v] = tot;
}

bool bfs() {
	queue<int> q;
	memset(dep, 0, sizeof(dep));
	cur[s] = head[s];
	dep[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int u = q.front() ; q.pop();
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if(!dep[v] && e[i].val) {
				cur[v] = head[v];
				q.push(v);
				dep[v] = dep[u] + 1;
				if(t == v) return 1;
			}
		}
	}
	return dep[t];
}
int dfs(int u, int sum) {
//	cout << u << endl;
	if(u == t || sum == 0) return sum;
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

double dis(int x1, int y1, int x2, int y2) {
	return (pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int ha1(int x, int y) {
	return (x - 1) * c + y;
}
int ha2(int x, int y){
	return (x - 1) * c + y + r * c;
}


int main()  {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c >> d;
	s = 0, t = r * c * 3 + 1;
	rep(i, 1, r) 
		rep(j, 1, c) {
			char ch;
			cin >> ch;
			mp[i][j] = ch - '0';
//			cout << i << " " << j << endl;
			if(mp[i][j]) {
				if(i <= d || j <= d || r - i < d || c - j < d) add(ha2(i, j), t, 2e9);
				add(ha1(i, j), ha2(i, j), mp[i][j]);
			}
		}
	rep(i, 1, r) rep(j, 1, c)
		rep(x, 1, r) rep(y, 1, c) {
			if(d * d >= dis(i, j, x, y)){
				add(ha2(i, j), ha1(x, y), 2e9);
			}
		}
	int sum = 0;
	rep(i, 1, r) 
		rep(j, 1, c) {
			char ch;
			cin >> ch;
			if(ch == 'L') {
				sum++;
				add(s, ha1(i, j), 1);
			}
		}
	cout << sum - dinic() << '\n';
	return 0;
}
