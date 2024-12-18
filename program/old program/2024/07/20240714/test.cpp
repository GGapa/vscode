#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 2e5 + 5;
const int INF = 1e9;
const int mod = 1e9 + 7;

vector<int> G[N];
int A[N], dis[N];

int st = 0, mx = 0;

void dfs(int x, int fa) {
	dis[x] = dis[fa] + 1;
	if(dis[x] > dis[mx]) mx = x;
	for(auto to : G[x]) if(to != fa) {
		dfs(to, x);
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for(int u, v, i = 1; i < n; i++) 
		cin >> u >> v, u--, v--, G[u].push_back(v), G[v].push_back(u);
	fill(dis, dis + n, INF);
	mx = n;
	dfs(0, n) ;
	fill(dis, dis + n, INF);
	st = mx; mx = n;
	dfs(st, n);
	cout << dis[mx] << '\n';
    return 0;
}

