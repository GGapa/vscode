#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 30;

vector<short> G[N];
int vis[N], F[(1 << 26) - 1], DL[(1 <<26) - 1];
short n, m; 
vector<short> nd[N], wt; 


bool check(int s)  {
	if(DL[s]) return 1;
	fill(vis, vis + n, 0);
	rep(i, 0, n - 1) if((s >> i) & 1) {
		vis[i] = 1;
		for(auto to : G[i]) {
			if(vis[to] == 1) return false;
			if(vis[to] != 2) nd[i].push_back(to);
			vis[to] = 2;
		}
	} 
	DL[s] = 1;
	return true;
}

int nn, t;

void dfs(int s, short st) {
	F[s] = t;
	if(st >= n) return ;
	dfs(s, st + 1);
	
	if(vis[st] == 1)
	for(auto j : nd[st]) {
		dfs(s | (1 << j), st + 1);
	}
}

signed main() {
//	freopen("set.in", "r", stdin);
//	freopen("set.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) 
    	cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
	int tp = (1 << n) - 1;
	rep(s, 1, tp) if(!F[s]){
		rep(i, 0, n - 1) vector<short>(0).swap(nd[i]);
		if(!check(s)) continue;
		t = __builtin_popcount(s);
		dfs(s, 0);
//		if(s % 100000 == 0) cout << s << endl;
	}
	int ans = 0;
	rep(s, 1, tp) if(F[s] == 0) {
		for(int i = (s - 1); i; i = (i - 1) & s) if(DL[i]) F[s] = max(F[s], F[i]);
	}
	rep(s, 0, tp) ans += F[s];
	cout << ans << '\n';
    return 0;
}
/*
0
1
10
11
100
101
*/
