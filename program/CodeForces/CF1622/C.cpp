#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
	int n; ll k; cin >>n >> k;
	vector<int> A(n +1);
	ll sum = 0; 
	rep(i, 1, n) cin >> A[i], sum += A[i];
	sort(A.begin() + 1, A.end());
	vector<ll> S(n + 1); 
	rep(i, 1, n) S[i] = S[i - 1] + A[i];
	ll mx = min(1ll * A[1], k / n);
	ll it = n;
	sum = sum - A[1] + mx;
	for(; it && sum > k; it--) sum = sum - A[it] + mx;
	int ans = A[1] - mx + (n - it);
	int t = mx;
	while(--mx >= t - n) {
		int tmp = 0;
		sum--; sum -= (n - it);
		for(; it < n && sum + A[it + 1] - mx <= k; ) sum += A[it + 1] - mx, it++;
		tmp = A[1] - mx + (n - it);
		if(tmp <= ans) ans = tmp;
	}
	cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int T; cin >> T;
	while(T--) solve();
    return 0;
}

/*
1
10 1
1 1 4 5 1000 1000 1000 1000 1000 1000

*/