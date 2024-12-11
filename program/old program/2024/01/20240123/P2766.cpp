#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1e7 + 5;

int n, s, t, len;
int a[N], dp[N], used[N];

struct edge {
	int v, val, nxt;
}e[N];
int head[N], cur[N], tot = 1, dep[N];

void add(int u, int v, int w) {
	e[++tot] = (edge){v, w, head[u]};
	head[u] = tot;
	e[++tot] = (edge){u, 0, head[v]};
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
			 if(!dep[v] && e[i].val) {
			 	cur[v] = head[v];
			 	dep[v] = dep[u] + 1;
			 	q.push(v);
			 	if(v == t) return 1;
			 }
		}
	}
	return dep[t];
}

int dfs(int x, int sum ) {
	if(x == t || !sum) return sum;
	int k, res = 0;
	for(int& i = cur[x] ;i && sum; i = e[i].nxt) {
		int to = e[i].v;
//		cur[x] = i;
		if(e[i].val && dep[to] == dep[x] + 1) {
			k = dfs(to, min(e[i].val, sum));
			if(k == 0)  {
				dep[to] = 0;
				continue;
			}
			e[i].val -= k;
			e[i ^ 1].val += k;
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

//void dfs2(int x, int d) {
//	if(d == len) {
//		if(!used[x])add(x, t, 1);
//		used[x] = 1;
//		return;
//	}
//	rep(i, x + 1, n) 
//		if(a[x] <= a[i]) {
//			if(n - i + 1 >= len - d) add(x, i, 1);
//			dfs2(i, d + 1);
//		}
//}
//
//void dfs3(int x, int d) {
//	if(d == len) {
//		if(!used[x])
//			add(x, t, (x == n) ? 2e9 : 1);
//		used[x] = 1;
//		return;
//	}
//	rep(i, x + 1, n)  {
//		if(a[x] <= a[i]) {
//			if(n - i + 1 >= len - d) add(x, i, 1);
//			dfs3(i, d + 1);
//		}
//	}
//}
//
void work1() {
	rep(i, 1, n) dp[i] = 1;
	rep(i, 1, n) {
		rep(j ,1, i - 1) {
			if(a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	rep(i, 1, n)len = max(len, dp[i]);
	cout << len << '\n';
}
//
//void work2() {
//	rep(i, 1, n) {
//		if(i <= n - len + 1)add(s, i, 1);
//		dfs2(i, 1);
//	}
//	cout << dinic() << '\n';
//}
//
//void work3() {
//	memset(used, 0, sizeof(used));
//	memset(head, 0, sizeof(head));
//	memset(cur, 0, sizeof(cur));
//	rep(i, 1, n) {
//		if(i <= n - len + 1)
//			add(s, i, (i == 1  ? 2e9 : 1));
//		dfs3(i, 1);
//	}
//	cout << dinic() << '\n';
//}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	s = 0, t = 1e5;
	rep(i, 1, n) cin >> a[i];
	work1();
	rep(i, 1, n) {
		if(dp[i] == 1) add(s, i, 1);
		if(dp[i] == len) add(i + n, t, 1);
		add(i, i + n, 1);
	}
	rep(i, 1, n) 
		rep(j, 1, i - 1) if(dp[j] + 1== dp[i] && a[j] <= a[i]) add(j + n, i, 1);
	int ans = dinic();
	cout << ans << '\n';  
	add(1, 1 + n, 2e9); add(s, 1, 2e9);
    if(dp[n] == len)add(n, n * 2, 2e9), add(n * 2, t, 2e9);
    if(n != 1)cout << ans + dinic() << '\n';
    else cout << 1 << '\n';
//	work2();
//	work3();
	return 0;
}
