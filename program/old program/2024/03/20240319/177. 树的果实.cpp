// http://124.221.194.184/problem/177
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
//#define int long long

struct BIT {
	int n;
	vector<int> T;
	BIT(int _n) : n(_n) ,T(_n + 5) {	};
	int lowbit(int x) {return x & -x;}
	void add(int x, int v) {
		for(x; x <= n; x += lowbit(x)) T[x] += v;
	}
	int ask(int x) {
		ll res = 0;									// 不赋初值见祖宗！！！！！ 
		for(; x > 0; x -= lowbit(x)) res += T[x];
		return res;
	}
};
#define mid ((l + r) >> 1)
#define ls (x << 1)
#define rs (x << 1 | 1)
struct SegTree {
	int n; 
	vector<int> T;
	SegTree(int _n) : n(_n), T((_n << 2) + 5) { }
	void modify(int L, int R, int v, int x = 1, int l = 1, int r = -1) {
		if(r == -1) r = n;
		if(L <= l && r <= R) {
			T[x] += v;	
			return ;
		}
		if(L <= mid) modify(L, R, v, ls, l, mid);
		if(R > mid) modify(L, R, v, rs, mid + 1, r);
		T[x] = T[ls] + T[rs];							// 忘记pushup表现：查询一直为 0 但是有值被成功更新 
	}
	int query(int L, int R, int x = 1, int l = 1, int r = -1) {
		if(r == -1) r = n;
		if(L <= l && r <= R) {
			return T[x];
		}
		int res = 0;
		if(L <= mid) res += query(L, R, ls, l, mid);
		if(R > mid) res += query(L, R, rs, mid + 1, r);
		return res;
		
	}
};
#undef ls
#undef rs
#undef mid

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n; cin >> n;
	using VI = vector<int> ;
	vector<VI> G(n + 1);
	vector<array<int, 3>> A(n + 1);
	vector<int> rk(n + 1), L{0}, To(n + 1), si(n + 1);
	vector<array<int, 3>> ans(n + 1);
	for(int i = 2, x; i <= n; i++) 
		cin >> x, G[x].push_back(i);

	rep(i, 1, n) cin>> A[i][0], A[i][1] = i;
	sort(A.begin() + 1, A.end(), greater<array<int, 3>>()) ;
	rep(i, 1, n) ans[A[i][1]][1] = i - 1, rk[A[i][1]] = i;
	BIT B(n);
	
	auto dfs = [&](auto self, int x) -> void {
		L.push_back(x); To[x] = L.size() - 1; si[x] = 1; 
		ans[x][0] = B.ask(rk[x]); 
		B.add(rk[x], 1);
		for(auto to : G[x]) {
			self(self, to);
			si[x] += si[to];
		} 
		B.add(rk[x], -1);
	};
	
	dfs(dfs, 1); 
	SegTree T(n);
	rep(i, 1, n) {
		int id = A[i][1], to = To[id];
		ans[id][2] = T.query(to, to + si[id] - 1);
		int t = T.query(to, to + si[id] - 1);
		T.modify(to, to, 1);
	}
	rep(i, 1, n) cout << ans[i][2] << " " << ans[i][1] - ans[i][2] << " " << ans[i][0] << '\n';
    return 0; 
}
