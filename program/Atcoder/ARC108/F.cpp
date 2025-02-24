#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
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
	int d = dx[mx];
	sy = mx; mx = 0;
	dfs(sy, 0, dy); 
	ll ans = 0;
	vector<int> nd(n + 1);
	rep(i, 1, n) if(i != sx && i != sy)  nd[max(dx[i], dy[i])]++;
	rep(i ,1, n) nd[i] += nd[i - 1];
	int L = 0;
	rep(i, 1, n) L = max(L, min(dx[i], dy[i]));
	rep(i, L, d) {
		ll f1 = qpow(2, nd[i]);
		ll f0 = qpow(2, nd[i - 1]);
		if(i == L) f0 = 0;
		(ans += i *((f1 - f0 + mod) % mod) % mod) %= mod;
	} 
	(ans += qpow(2, n - 2) * d % mod) %= mod;
	(ans *= 2) %= mod;
	cout << ans % mod<< '\n';
	return 0; 
}
 