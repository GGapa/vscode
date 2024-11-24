#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
#define int long long
const int N = 2e5 + 5;

int n, m, s = 0;
vector<pair<int, int>> G[N];
long long dis[N];
int vis[N], cnt[N];

// bool spfa() {
//     queue<int> q;
//     for(int i = 1; i <= n; i++) {
//         dis[i] = 2e9;
//         vis[i] = 0;
//     }
//     q.push(0);
//     dis[0] = 0; vis[0] = 1; cnt[0] = 1;
//     while(!q.empty()) {
//         int x = q.front();
//         q.pop(); vis[x] = 0;
//         for(auto i : G[x]) {
//             int to = i.first, val = i.second;
//             if(dis[to] > dis[x] + val) {
//                 dis[to] = dis[x] + val;
//                 if(vis[to] == 0) {
//                     vis[to] = 1;
//                     q.push(to);
//                     cnt[to]++;
//                     if(cnt[to] > n + 1) return 1;
//                 }
//             }
//         }
//     }
//     return 0;
// }


// void Dijkstra() {
//     for(int i = 1; i <= n; i++) dis[i] = 1e18;
// 	using pii = pair<long long, int>;
//     priority_queue<pii, vector<pii>, greater<pii>> q;
// 	q.push({0, s}); dis[0] = 0;
// 	while(!q.empty()) {
// 		int x = q.top().second; long long w = q.top().first;
//         q.pop();
// 		if(w > dis[x]) continue;
//         for(auto i : G[x]) {
//             int to = i.first, val = i.second;
//             if(dis[to] > dis[x] + val) {
//                 dis[to] = dis[x] + val;
//                 q.push({dis[to], to});
//             }
//         }
// 	}
// }



void dfs(int x) {
    vis[x] = 1;
    for(auto i : G[x]) {
        int to = i.first, w = i.second;
        if(vis[to]) continue;
        dis[to] = dis[x] + w;
        dfs(to);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, -w));
    }
    // for(int i = 1; i <= n; i++) G[0].push_back(make_pair(i, 0));
	// Dijkstra();
    for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i);
	for(int i = 1; i <= n; i++) {
		cout << dis[i] << ' ';
	}
    return 0;
}