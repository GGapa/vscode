#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long

typedef long long ll;
typedef pair<ll, ll> pll;
const int maxn = 1e4 + 5;
const int maxk = 100 + 5;


int n, m, k;
vector<pll> G[maxn];
ll dis[maxn][maxk], vis[maxn][maxk];
void dijkstra() {
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pll, vector<pll>, greater<pll>> q;
	q.push({0, 1});
	dis[1][0] = 0;	
	while(!q.empty()) {
		ll x = q.top().second, val = q.top().first;
		q.pop();
		if(vis[x][val % k]) continue;
		vis[x][val % k] = 1;
		for(auto i : G[x]) {
			int limit = i.second, to = i. first, t = (val + 1) % k;
			if(val >= limit) t = val;
			else t = ((limit - val + k - 1) / k) * k + val;
			auto& di = dis[to][(t + 1) % k];
			if(di > t + 1) {
				di = t + 1;
				q.push({t + 1, to});
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("test.in", "r", stdin);
#endif
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		G[u].push_back({v, w});
	}
	dijkstra();
	if(!vis[n][0]) {
		cout << -1;
		return 0;
	}
	cout << dis[n][0];
	return 0;
}
