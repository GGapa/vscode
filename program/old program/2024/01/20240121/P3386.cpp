#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1000 + 5;

int n, m, e;
vector<int> G[N];
int mch[N], vis[N];

bool dfs(int u, int tag) {
	if(vis[u] == tag) return false;
	vis[u] = tag;
	for(auto v : G[u]) if(mch[v] == 0 || dfs(mch[v], tag)) {
		mch[v] = u;
		return true;
	}
	return false;
}

int main()  {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> e;
	rep(i, 1, e)	 {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	int ans = 0;
	rep(i, 1, n) if(dfs(i, i)) ans++;
	cout << ans << '\n';
	return 0;
}

