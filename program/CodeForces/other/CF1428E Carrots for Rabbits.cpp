#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    priority_queue<array<LL, 3>> q;
    int n, k; cin >> n >> k;
    vector<int> A(n + 1); 
	rep(i, 1, n) cin >> A[i];
	auto sqr = [](LL x) { return x * x; };
	auto f = [&](LL l, LL p) { 
        l = A[l];
        return sqr(l / p) * (p - l % p) + (l % p) * sqr(l / p + 1);
    };
    LL ans = 0;
	for (int i = 1; i <= n; i++) 
	    q.push({f(i, 1)-f(i, 2), i, 2}), ans += f(i, 1);
	for (int i = 1; i <= k - n; i++) {
	    auto c = q.top(); q.pop();
	    ans -= c[0];
	    if (c[2] < A[c[1]])
	        q.push({f(c[1], c[2]) - f(c[1], c[2] + 1), c[1], c[2] + 1});
	}
	cout << ans << '\n';
    return 0;
}