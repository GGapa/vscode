#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e6 + 5;

vector<int> G[N];
int si[N], top[N], hson[N], fa[N], dep[N];
 
void dfs1(int x, int f) {
    si[x] = 1; dep[x] = dep[f] + 1; fa[x] = f;
    for(auto to : G[x]) {
        if(to == f) continue;
        dfs1(to, x);
        si[x] += si[to];
        if(si[to] > si[hson[x]]) hson[x] = to;
    }
}
 
void dfs2(int x, int tp) {
    top[x] = tp;
    if(!hson[x]) return ;
    dfs2(hson[x], tp);
    for(auto to : G[x]) {
        if(to == fa[x] || to == hson[x]) continue;
         dfs2(to, to);       
    }
}
 
int lca(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);   
        x = fa[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);
}

int n, q ;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i = 1, u, v; i < n; i++) 
		cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
	dfs1(1, 0); dfs2(1, 0);
	for(int t, lc; q--; ) {
		cin >> t;
		vector<int> A(t + 1);
		int mx = 0;
		rep(i, 1, t) {
			cin >> A[i];
			if(dep[A[i]] > dep[mx]) mx = A[i];
		}
		int ans = 0;
		rep(i, 1, t) {
			int l = lca(mx, A[i]);
			ans = max(ans, dep[A[i]] - dep[l]);
		}
		cout << (ans <= 1 ? "YES" : "NO") << '\n';
	}
    return 0;
}