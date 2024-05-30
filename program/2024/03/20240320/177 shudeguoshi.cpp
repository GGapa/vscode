// shudeguoshi ZJOI2004 树的果实
// http://124.221.194.184/problem/177
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

struct BIT {
	int n;
	vector<int> T;
	BIT(int _n) : n(_n) ,T(_n + 5) {	};
	int lowbit(int x) {return x & -x;}
	void add(int x, int v) {
		for(x; x <= n; x += lowbit(x)) T[x] += v;
	}
	int ask(int x) {
		ll res = 0;									
		for(; x > 0; x -= lowbit(x)) res += T[x];
		return res;
	}
};

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
	BIT T1(n), T2(n);
	
	auto dfs = [&](auto self, int x) -> void {
		L.push_back(x); To[x] = L.size() - 1; si[x] = 1; 
		ans[x][0] = T1.ask(rk[x]); 
        ans[x][2] = -T2.ask(rk[x]);
		T1.add(rk[x], 1);  T2.add(rk[x], 1);
		for(auto to : G[x]) {
 			self(self, to);
			si[x] += si[to];
		} 
		T1.add(rk[x], -1);
        ans[x][2] += T2.ask(rk[x] - 1);
	};
	
	dfs(dfs, 1); 
	rep(i, 1, n) cout << ans[i][2] << " " << ans[i][1] - ans[i][2] << " " << ans[i][0] << '\n';
    return 0; 
}
