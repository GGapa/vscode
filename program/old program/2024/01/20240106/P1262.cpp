#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int maxn = 3000 + 5;
#define int long long

int low[maxn], dfn[maxn], cost[maxn], vis[maxn], scc[maxn], val[maxn], in[maxn];
int n, p, r, idx, t;
vector<int> G[maxn];
stack<int> stk;

void tarjan(int x) {
	dfn[x] = low[x] = ++dfn[0];
	stk.push(x);
	vis[x] = true;
	for(auto to : G[x]) {
		if(!dfn[to]) {
			tarjan(to);
			low[x] = min(low[x], low[to]);
		}
		else if(vis[to]) 
			low[x] = min(low[x], dfn[to]);
	}
	if(dfn[x] == low[x]) {
		idx++;
		while(stk.top() != x) {
			scc[stk.top()] = idx;
			vis[stk.top()] = false;
			val[idx] = min(cost[stk.top()], val[idx]);
			stk.pop();
		}
		scc[stk.top()] = idx;
		vis[stk.top()] = false;
		val[idx] = min(cost[stk.top()], val[idx]);
		stk.pop();
	}
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    cin >> p;
    rep(i, 1, maxn - 1) cost[i] = INT_MAX;
	rep(i, 1, maxn - 1) val[i] = INT_MAX;
    rep(i, 1, p) {
    	int u, v;
    	cin >> u >> v;
    	cost[u] = v;
	}
    cin >> t;
    rep(i, 1, t) {
    	int u, v;
    	cin >> u >> v;
    	G[u].push_back(v);
	}
	rep(x, 1, n) 
		if(!dfn[x] && cost[x] != INT_MAX) tarjan(x);
	rep(i, 1, n) if(!dfn[i]) {
		cout << "NO\n";
		cout << i << '\n';
		return 0;
	}
	rep(x, 1, n) {
		for(auto to : G[x]) 
			if(scc[to] != scc[x]) in[scc[to]]++;
	}
	int ans = 0;
	cout << "YES\n";
	rep(i, 1, idx) {
		if(in[i] == 0) ans += val[i];
	}
	cout << ans << '\n';
	
    return 0;
}