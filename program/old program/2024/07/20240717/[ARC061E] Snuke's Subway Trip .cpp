#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N =  1e5 + 5;

int n, m;  
unordered_map<int, int> id[N]; 
vector<array<int, 2>> G[N * 10];
int idx = 0;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> m;
    idx = n;
	auto add = [&](int u, int v, int w) { G[u].push_back({v, w}); };
    auto newnode = [&](int u, int c) { id[u][c] = ++idx, add(u, id[u][c], 1), add(id[u][c], u, 0);};
	for(int i = 1, u, v, c; i <= m; i++) {
		cin >> u >> v >> c;
		if(id[u][c] == 0) newnode(u, c);
        // cout << u << " " << id[u][c] << '\n';
		if(id[v][c] == 0) newnode(v, c);
        add(id[u][c], id[v][c], 0); add(id[v][c], id[u][c], 0);
    }
    const int INF = 1e9;
    vector<int> dis(idx + 1, INF);
    int S = 1;
    using AI = array<int, 2>;
    priority_queue<AI, vector<AI>, greater<AI>> q;
    dis[S] = 0; q.push({0, S});
    while(!q.empty()) {
        int x = q.top()[1], w = q.top()[0]; q.pop();
        if(dis[x] < w) continue;
        for(auto i : G[x]) {
            int to = i[0], co = i[1];
            // cout << x << " " << to << " " << co << '\n';
            if(dis[to] > dis[x] + co) {
                dis[to] = dis[x] + co;
                q.push({dis[to], to});
            }
        }
    }
    // rep(i ,1, n + 1) cout << dis[i] << " \n"[i == n];
    cout << (dis[n] >= INF ? -1 : dis[n]) << '\n';
    return 0;
}
