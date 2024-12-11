#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define endl '\n'
typedef long long ll;
using namespace std;
const int mod = 1e9 + 7, inv2 = 500000004;
const int maxn = 1e3 + 5;


int n;
ll  X, Y;
ll a[maxn];
bool vis[maxn];
vector<int> G[maxn];

ll qpow(ll x, ll y) {
	ll ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return ans;
}

namespace B1 {
	ll cnt, ans = 0;
	void dfs(int x) {
		vis[x] = true;
		cnt++;
		for(auto to : G[x]) {
			if(vis[to] || a[to] != 1) continue;
			dfs(to);
		}
	}
	int main() {
		if(X != 1) {
			cout << 0 << endl;
			exit(0);
		}
		rep(i, 1, n) {
			if(a[i] == 1 && !vis[i]) {
				cnt = 0;
				dfs(i);
				ans = (ans + dfs(i)) % mod;
			}
		}
		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("b.in", "r", stdin);
	froepen("b.out", "w", stdout);
	cin >> n >> X >> Y;
	rep(i, 1, n) cin >> a[i];
	rep(i, 2, n) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if(Y == 1) {
		B1::main();
		return 0;
	}
	cout << mod - 1 << '\n';
	return 0;
}


