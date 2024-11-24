// Cycle Finding 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const ll INF = 1e19;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
	int n, m, s; cin >> n >> m >> s;
	struct Edge {
		int v; ll w;
	};
	vector<vector<Edge>> G(n + 1);
	for(int i = 1, u, v, w; i <= m; i++) 
		cin >> u >> v >> w, G[u].push_back({v, w});
	vector<int> cnt(n + 1), vis(n + 1), tag(n + 1);
    vector<ll> D(n + 1, INF);
	queue<int> q;
	q.push(s), D[s] = 0, vis[s] = 1;
    function<void(int)> dfs = [&](int x) {
        tag[x] = 1;
        for(auto i : G[x]) if(!tag[i.v]) 
            dfs(i.v);
    };
	while(!q.empty()) {
        int x = q.front();
        q.pop(); vis[x] = 0;
        for(auto i : G[x]) if(!tag[i.v]){
            if(D[x] + i.w < D[i.v]) {
                D[i.v] = D[x] + i.w;
                if(++cnt[i.v] > n) {
                    D[i.v] = -INF;
                    dfs(i.v);
                }
                if(!vis[i.v]) {
                    q.push(i.v), vis[i.v] = true;
                }
            }    
        }
	}
    rep(i ,1, n) {
        if(tag[i] || D[i] <= -INF) cout << "-\n";
        else if(D[i] >= INF) cout << "*\n";
        else cout << D[i] << '\n';
    }
    return 0;
}
