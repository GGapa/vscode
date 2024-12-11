//http://124.221.194.184/contest/111/problem/553 
// 40pts
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;

int n, m, k, e, d, ans, lm;
vector<pair<int, int>> G[maxn];
int dis[maxn], fa[maxn], step[maxn];
int unable[maxn][maxn], date;
bool use = false;

int way() {
	int it = m; bool flag = false;
	int cnt = 1;	
	while(it != 1) {
		if(step[cnt] != it) flag = true, use = true;
		step[cnt] = it;
		it = fa[it];
		cnt++;
	}
	return flag ? k : 0;
}

void Dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(fa, 0, sizeof(fa));
	dis[1] = 0;
	fa[1] = 1;
	q.push(make_pair(0, 1));
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		for(auto to : G[x]) {
			if(unable[to.first][date])  continue;
			int di = dis[x] + to.second;
			if(di < dis[to.first]) {
				dis[to.first] = di;
				q.push(make_pair(di, to.first)), fa[to.first] = x;
			}
		}
	}
	ans += dis[m] + way();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k >> e;
	ans = -k;
	for(int i = 1, u, v, w; i <= e; i++) {
		cin >> u >> v >> w;
		 G[u].push_back(make_pair(v, w));
		 G[v].push_back(make_pair(u, w));
	}
	cin >> d;
	for(int i = 1, id, a, b; i <= d; i++) {
		cin >> id >> a >> b;
		for(int j = a; j <= b; j++) {
			unable[id][j] = 1;
		}
	}
	date = 1;
	while(date <= n) {
		Dijkstra();
		date++;
	}
	if(!use) ans += k;
	cout << ans << " ";
	return 0; 
}
