#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 2e4 + 5;
#define _for(i, a, b) for(int i = (a); i <= (b); i++)

int n, m;
vector<int> G[maxn];
int dfn[maxn], low[maxn];
bool iscut[maxn];
int cutsum = 0;
int root;

void dfs(int x) {
	dfn[x] = low[x] = dfn[0]++;
	int son = 0;
	for(auto to : G[x]) {
		if(!dfn[to]) {
			son++;
			dfs(to);
			low[x] = min(low[x], low[to]);						//处理 
			if(low[to] >= dfn[x] && x != root) cutsum += !iscut[x], iscut[x] = true; //这个的目的顺便去一下重 
		}
		else 													//如果是父亲没有意义，此时是回退边 
			low[x] = min(low[x], dfn[to]);
	}
	if(son >= 2 && x == root) cutsum += !iscut[x], iscut[x] = true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ;
	cout.tie(0);
	//freopen("AKIOI.in", "r", stdin);
	//freopen("AKIOI.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfn[0] = 1;
	_for(i, 1, n) if(dfn[i] == 0) root = i, dfs(i);
	cout << cutsum << "\n" ;
	_for(i, 1, n) if(iscut[i]) cout << i << " \n"[i == n];
	return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.09KB
用时
231ms
内存
3.06MB
 GGapa

所属题目
P3388 【模板】割点（割顶）
评测状态
Accepted
评测分数
100
提交时间
2023-10-18 10:48:42
*/