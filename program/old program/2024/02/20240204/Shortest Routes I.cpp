#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
typedef pair<int, int> pii;
const int N = 1e5 + 5;


int n, m, s = 1;
vector<pii> G[N];
ll dis[N];
bool vis[N];

void Dijkstra() {
    for(int i = 1; i <= n; i++) dis[i] = 1e18;
    priority_queue<pii, vector<pii>, greater<pii>> q;
	dis[s] = 0; 
	q.push({0, s});

	while(!q.empty()) {
		int x = q.top().second; q.pop();
        if(vis[x]) continue;            //vis数组
        vis[x] = true;
		for(auto to : G[x] ){
			if(dis[to.first] > dis[x] + to.second) {
				dis[to.first] = dis[x] + to.second;
                if(!vis[to.first])
				    q.push({dis[to.first], to.first});
				
			}
		}
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }
    Dijkstra();
    rep(i, 1, n) cout << dis[i] << " \n"[i == n];

    return 0;
}