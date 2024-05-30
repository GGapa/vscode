#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;


struct BIT {
	int n;
	vector<ll> T;
	BIT(int _n) : n(_n) ,T(_n + 5) {	};
	int lowbit(int x) {return x & -x;}
	void add(int x, int v) {
		for(x; x <= n; x += lowbit(x)) T[x] += v;
	}
	ll ask(int x) {
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
    vector<int> A(n + 1), B(n + 1), ans(n + 1);
    using VI = vector<int> ;
    vector<VI> G(n  +1);
    rep(i, 1, n) cin >> A[i];
    BIT T(n + 1);
    for(int i = 2, x; i <= n; i++) 
        cin >> x, G[x].push_back(i);

    B = A;
    sort(B.begin(), B.end());
    unique(B.begin() + 1, B.end());
    rep(i, 1, n) 
        A[i] = lower_bound(B.begin() + 1, B.end(), A[i]) - B.begin(), A[i] = n - A[i] + 1;
    // rep(i, 1, n) cout << A[i] << " " << B[A[i]] << '\n';

    auto dfs = [&](auto self, int x, int fa) -> void {
        T.add(A[x], 1);
        ans[x] = -T.ask(A[x]);
        for(auto to : G[x]) if(to != fa) {
            self(self, to, x);
        }
        ans[x] += T.ask(A[x]);
    };

    dfs(dfs, 1, 0);
    rep(i, 1, n) cout << ans[i] << '\n';
    return 0;
}