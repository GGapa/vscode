#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

const int N = 2e5 + 5, INF = 1e9;
const int mod = 1e9 + 7;

vector<int> G[N];
int mx = 0;

void dfs(int x, int fa, vector<int> &dis) {
	dis[x] = dis[fa] + 1; 
	if(dis[x] > dis[mx]) mx = x;
	for(auto to : G[x]) if(to != fa) dfs(to, x, dis) ;
}

void out(vector<int> &a) {
	int t = (int)a.size() - 1;
	rep(i, 1, t) cout << a[i] << " \n"[i == t];
}

ll qpow(ll x, ll y) {
	if(y < 0) return 1;
	ll ret = 1;
	for(; y; y >>= 1) {
		if(y & 1) (ret = ret * x) %= mod;
		(x = x * x) %= mod;
	}
	return ret;
} 

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> dx(n + 1, INF), dy = dx;
	dx[0] = dy[0] = -1;
	for(int i = 1, u, v; i < n; i++) 
		cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
	dfs(1, 0, dx); 
	int sx, sy;
	fill(dx.begin() + 1, dx.end(), INF);
	sx = mx; mx = 0;
	dfs(sx, 0, dx);
	// cout << dx[mx] << '\n';
	int d = dx[mx];
	sy = mx; mx = 0;
	dfs(sy, 0, dy); 
	vector<VI> nx(n + 1), ny(n + 1);
	rep(i ,1, n) nx[dx[i]].emplace_back(i);
	rep(i ,1, n) ny [dy[i]].emplace_back(i);
	set<int> ban;
	ll ans = qpow(2, n - 2) * d % mod  % mod;

	for(bool tag = 1; --d && tag; ) {
		set<int> tmp;
 		for(auto i : nx[d + 1]) ban.insert(i), cout << i << " ";
		for(auto i : ny[d + 1]) {
			if(ban.count(i)) {tag = false; break;}
			ban.insert(i); 
			cout << i << " ";
		}
		cout << '\n';
		for(auto i : nx[d]) if(!ban.count(i)) tmp.insert(i);
		for(auto i : ny[d]) if(!ban.count(i)){
			if(tmp.count(i)) {
				tmp.clear();
				break;
			}
			else tmp.insert(i);
		}
		if(!tag) break;
		int t = tmp.size();
		// cout << n - ban.size() - t << '\n';
		(ans += (max(qpow(2, t) - 1, 1ll) * qpow(2, n - ban.size() - t)) % mod * d % mod) %= mod;
		cout << ans << '\n';
	}
	cout << ans * 2 % mod << '\n';
	return 0; 
}
 