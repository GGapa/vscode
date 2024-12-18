// Inspector's Dilemma
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e3 + 5;

int V, E, T;


void solve() {
	vector<VI> G(V + 1);
	vector<int> vis(V + 1);

	for(int i = 1, u, v; i <= E; i++) 
		cin >> u >> v, G[u].push_back(v), G[v].push_back(u); 
	function<void(int, int&)>dfs = [&](int x, int &cnt) {
		cnt += (G[x].size() % 2 == 1) ; vis[x] = 1;
		for(auto to : G[x]) if(!vis[to])
			dfs(to, cnt);
	};
	int cc = 0, ans = E;
	rep(i, 1, V) if(!vis[i] && !G[i].empty()) {
		cc++;
		int p = 0;
		dfs(i, p);
		if(p > 2) ans += (p - 2) / 2;
	}
	cout << (ans + max(0, cc - 1)) * T << '\n';
}

signed main() {
	// freopen("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	for(int ca = 1; cin >> V >> E >> T && V; ca++) {
		cout << "Case " << ca << ": " ;
		solve();
	}
    return 0;
}