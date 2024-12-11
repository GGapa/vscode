#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
#define int long long

vector<int> G[maxn];
int n, m;
int dfn[maxn], si[maxn], low[maxn];
long long ans[maxn];

void dfs(int x) {
	dfn[x] = low[x] = dfn[0]++;
	long long r = n - 1;
	si[x] = 1;
	ans[x] = r;
	for(auto to : G[x]) {
		if(dfn[to] == 0) {
			dfs(to);
			low[x] = min(low[to], low[x]);
			si[x] += si[to];
			if(low[to] >= dfn[x])  ans[x] += si[to] * (n - si[to]), r -= si[to];
		}
		else low[x] = min(low[x], dfn[to]);
	}
	ans[x] += r * (n - r);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ;
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfn[0] = 1;
	dfs(1);
	for(int i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
848B
用时
672ms
内存
17.61MB
 GGapa

所属题目
P3469 [POI2008] BLO-Blockade
评测状态
Accepted
评测分数
100
提交时间
2023-10-18 19:42:19
*/