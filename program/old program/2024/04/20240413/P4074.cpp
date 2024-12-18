// P4074 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int N = 1e5 + 5;
vector<VI> G;

struct Que {
	int l, r, t, lca, id, ans;
};
struct OP {
	int it, v;
};

int fa[N], top[N], in[N], out[N], si[N], dep[N], hson[N];
int idx = 0;
VI dfn(1);

void dfs1(int x, int p) {
	fa[x] = p; in[x] = ++idx;
	dfn.push_back(x);
	si[x] = 1, dep[x] = dep[p] + 1;
	for(auto to : G[x]) if(to != p) {
		dfs1(to, x);
		si[x] += si[to];
		if(si[hson[x]] < si[to]) hson[x] = to;
	}
	out[x] = ++idx;
	dfn.push_back(x);
}

void dfs2(int x, int tp) {
	top[x] = tp;
	if(hson[x]) dfs2(hson[x], tp);
	for(auto to : G[x]) if(to != fa[x] && to != hson[x]) {
		dfs2(to, to);
	}
}

int LCA(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return (dep[x] < dep[y] ? x : y);
}

signed main() {
    freopen("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m, q; cin >> n >> m >> q;
	G.resize(n + 1);
	VI V(m + 10), W(n + 10), C(n + 10);
	rep(i, 1, m) cin >> V[i];
	rep(i, 1, n) cin >> W[i];
	for(int i = 1, u, v; i < n; i++) 
		cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
	rep(i, 1, n) cin >> C[i];
	dfs1(1, 1);
	dfs2(1, 1);
	vector<Que> Q(1);
	vector<OP> op(1);
	for(int i  =1, t, x, y; i <= q; i++) {
		cin >> t >> x >> y;
		if(t) {
			if(in[x] > in[y]) swap(x, y);
			int lca = LCA(x, y);
			if(lca == x) Q.push_back((Que){in[x], in[y], (int)op.size() - 1, 0, (int)Q.size(), 0});
			else Q.push_back({out[x], in[y], (int)op.size() - 1, in[lca], (int)Q.size(), 0});
		} else {
			op.push_back({x, y});
		}
	} 
	int blo = pow(n, 0.6666666);
	sort(Q.begin() + 1, Q.end(), [&](const Que&x, const Que &y) {
		int t1 = x.l / blo, t2 = y.l / blo, t3 = x.r / blo, t4 = y.r / blo;
		return (t1 == t2 ? (t3 == t4 ? x.t < y.t : t3 < t4) : t1 < t2);
	});
	int l = 1, r = 0, t = 0; 
	VI cnt(n * 2), vis(n + 10);
	int ans = 0;
	auto add = [&](int x, int c = -1, int tp = -1) {
		x = dfn[x];
		if(c == -1) c = C[x]; 
		if((vis[x] || tp == 0) && tp != 1) {
			ans -= W[cnt[c]--] * V[c];
			cout << c << endl;
		}
		 else {
			ans += W[++cnt[c]] * V[c];
		}
		if(tp == -1) vis[x] ^= 1;
	};
	auto upd = [&](int x, int l, int r) {
        if(vis[op[x].it]) {
            add(0, op[x].v, 1);
            add(0, C[op[x].it], 0);
        }
		swap(C[op[x].it], op[x].v);
	};
	// rep(i, 1, n * 2) cout << dfn[i] << " \n"[i == n * 2];
	rep(i, 1, Q.size() - 1) {
		auto &qe = Q[i];
		// cout << qe.l << " " << qe.r << '\n';
        while(t < qe.t) upd(++t, l, r);
		while(t > qe.t) upd(t--, l, r);
		while(l < qe.l) add(l++);
		while(l > qe.l) add(--l);
		while(r < qe.r) add(++r);
		while(r > qe.r) add(r--);
		if(qe.lca) add(qe.lca);
		qe.ans = ans;
		if(qe.lca) add(qe.lca);
	}
	VI oo(q + 1);
	rep(i, 1, Q.size() - 1) oo[Q[i].id] = Q[i].ans;
	rep(i, 1, Q.size() - 1) cout << oo[i] << '\n';
    return 0;
}