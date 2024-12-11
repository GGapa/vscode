// P4211 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int mod = 201314;


#define ls (x << 1)
#define rs ((x << 1) | 1)

struct SegTree {
	struct Node {
		ll val, tag;
	};
	vector<Node> T;
	int n;
	SegTree() {	}
	SegTree(int _n) : n(_n), T((_n << 2)  +5) {}
	void pushdown(int x, int l, int r) {
		auto &t = T[x];
		if(t.tag == 0) return ;
		int mid =  (l + r) / 2;
		(T[ls].tag += T[x].tag);
		(T[rs].tag += T[x].tag);
		(T[ls].val += 1ll * (mid - l + 1) * T[x].tag) ;
		(T[rs].val += 1ll * (r - (mid + 1) + 1) * T[x].tag ) ;
		t.tag = 0;
	}
	void modify(int L, int R, int v, int x = 1, int l = 1, int r = -1) {
		if(r == -1) r = n;
		auto &t = T[x];
		assert(x <= n << 2);
		if(L <= l && r <= R) {
			(t.tag += v) ;
			(t.val += 1ll * (r - l + 1) * v ) ;
			return ;
		}
		pushdown(x, l, r);
		int mid = (l + r) / 2;
		if(L <= mid) modify(L, R, v, ls, l, mid);
		if(R > mid) modify(L, R, v, rs, mid + 1, r);
		(T[x].val = T[ls].val + T[rs].val) ;
	}
	ll query(int L, int R, int x = 1, int l = 1, int r = -1) {
		if(r == -1) r = n;
		auto &t = T[x];
		if(L <= l && r <= R) {
			return t.val;
		}
		pushdown(x, l, r);
		int mid = (l + r) / 2;
		ll res = 0;
		if(L <= mid) res += query(L, R, ls, l, mid);
		if(R > mid) res += query(L, R, rs, mid + 1, r);
		return res;
	}
};
SegTree T;
#undef ls
#undef rs

const int N = 1e5 + 5;
int si[N], dep[N], fa[N], top[N], hs[N], re[N], dfn[N];
vector<int> G[N];

void dfs1(int x, int f) {
	si[x] = 1, dep[x] = dep[f] + 1; fa[x] = f;
	for(auto to : G[x]) if(to != f) {
		dfs1(to, x);
		si[x] += si[to];
		if(si[hs[x]] < si[to]) hs[x] = to;
	}
}

void dfs2(int x, int tp) {
	top[x] = tp;
	re[x] = ++dfn[0];
	if(hs[x]) dfs2(hs[x], tp);
	for(auto to : G[x]) if(to != fa[x] && to != hs[x]) {
		dfs2(to, to);
	}
}

int n;
void mdf(int x, int y, int v) {
    if(y == 0) return ;
    while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		T.modify(re[top[x]], re[x], v);
        // T.modify(1, n, v);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) swap(x, y);
	T.modify(re[x], re[y], v);
    // T.modify(1, n, v);
}

ll qry(int x, int y) {
    int res = 0;
    while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		res += T.query(re[top[x]], re[x]);
        // res += T.query(1, n);
		x = fa[top[x]];
    }
	if(dep[x] > dep[y]) swap(x, y);
	res += T.query(re[x], re[y]);
    return res % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m; cin >> n >> m;
    T = SegTree(n);
	for(int i = 2, x; i <= n; i++) cin >> x, x++, G[x].emplace_back(i), G[i].emplace_back(x);
    struct Node {
        int id, it, z, tag;
    };
    vector<Node> Q(1);
    for(int i = 1, l, r, z; i <= m; i++) 
        cin >> l >> r >> z, l, r++, z++, Q.push_back({i, l, z, 0}), Q.push_back({i, r, z, 1});
    sort(Q.begin() + 1, Q.end(), [](const Node &x, const Node &y) {
        return x.it < y.it;
    });
	dfs1(1, 0);
	dfs2(1, 0);
    vector<array<int, 2>> ans(m + 1);
    int nw = 0;
    rep(i, 1, 2 * m) {
        while(nw < Q[i].it) mdf(1, ++nw, 1);
        ans[Q[i].id][Q[i].tag] = qry(1, Q[i].z);
    }
    rep(i, 1, m) {
        cout << (ans[i][1] - ans[i][0] + mod) % mod << '\n';
    }
    return 0;
}
// 有一个非常妙的方法