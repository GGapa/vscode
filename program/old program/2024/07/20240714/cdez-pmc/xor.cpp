#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e5 + 5;

unordered_map<int, vector<int>> G;
set<int> s;
unordered_map<int, int> vis;
int cnt = 0;

void dfs(int x) {
	vis[x] = 1; cnt++;
	for(auto to : G[x]) if(!vis[to]) dfs(to);
}

signed main()  {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> A(n + 1), B(n +1);
	int s1, s2; s1 = s2 = 0;
	rep(i, 1, n) cin >> A[i], s1 ^= A[i];
	rep(i ,1, n) cin >> B[i], s2 ^= B[i];
	int ans = 0;
	rep(i, 1, n) {
		int u = B[i], v = A[i];
		if(u == v) continue;
		s.insert(u), s.insert(v);
		ans++;
		G[u].emplace_back(v);
		G[v].emplace_back(u) ;
		// cout << u << " " << v << " " << ans << '\n';
	}
	for(auto i : s) if(!vis[i]) cnt = 0, dfs(i), ans += (cnt > 1);
	if(vis[s1] && vis[s2]) ans--;
	cout << ans << '\n';
	return	 0;
}