#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;

#define int long long

struct Node {
	int to, val;
};

int n, m, b, l, r;
int f[maxn], dis[maxn], used[maxn];
vector<Node> G[maxn];

bool Dijkstra(int sp) {
    if(f[1] > sp) return 0;
	priority_queue <pair<int ,int>, vector<pair<int ,int> >, greater<pair<int ,int> > > q;
	for(int i = 1; i <= n; i++) dis[i] = 1e9;
	memset(used, 0, sizeof(used));
	q.push(make_pair(0, 1));
	dis[1] = 0;
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		if(used[x]) continue;
		used[x] = true;
		for(auto i : G[x]) {
			int to = i.to, w = i.val;
			if(dis[x] + w < dis[to] && f[to] <= sp && !used[to]) {
				dis[to] = dis[x] + w;
				q.push(make_pair(dis[to], to));
			}
		}
	}
    if(dis[n] <= b) return 1;
    return 0;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("AKIOI.in", "r", stdin);
	//freopen("AKIOI.out", "w", stdout);
	cin >> n >> m >> b;
	for(int i = 1; i <= n; i++) cin >> f[i];
	for(int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		G[u].push_back(Node{v, w});
		G[v].push_back(Node{u, w});
		r += w;
	}
	if(!Dijkstra(r * 2)) {
		cout << "AFK\n";
		return 0;
	}
	while(l != r) {
		int mid = (l + r) >> 1;
		if(Dijkstra(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l << "\n";
	return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
1.35KB
用时
2.90s
内存
3.72MB
 GGapa

所属题目
P1462 通往奥格瑞玛的道路
评测状态
Accepted
评测分数
100
提交时间
2023-10-20 00:03:13
*/