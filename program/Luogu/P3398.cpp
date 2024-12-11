#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;

int n, q, si[maxn], dep[maxn], hson[maxn], fa[maxn], top[maxn];
vector<int> G[maxn];

void dfs1(int x, int f) {
    fa[x] = f;
    dep[x] = dep[f] + 1;
    si[x] = 1;
    for(auto to : G[x]) {
        if(to == f) continue;
        dfs1(to, x);
        si[x] += si[to];
        if(si[hson[x]] < si[to]) hson[x] = to;
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

int LCA(int x, int y)  {
	while(top[x] != top[y])	{
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) return x;
	return y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("rp++.in", "r", stdin);
    //freopen("rp++.out", "w", stdout);
    cin >> n >> q;
    for(int i = 2, u, v; i <= n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int s = LCA(a, b), t = LCA(c, d);
        if(dep[s] < dep[t]) {
            swap(s, t);
            swap(a, c);
            swap(b, d);
        }
        if(LCA(s, c) == s || LCA(s, d) == s) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}