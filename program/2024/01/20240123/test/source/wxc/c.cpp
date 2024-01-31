#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 10;
const int mod = 998244353;

int f[maxn], a[maxn], n, m, t; 
int qpow(int a, int b) {
	int ret = 1;
	while(b) {
		if(b & 1) ret = (ret * a) % mod;
		a = (a * a) % mod, b >>= 1;
	}
	return ret;
}
int dp(int x) {
	f[m] = 1;
	for(int i = m; i >= a[x]; i--) {
		f[i] += f[i+1]*(m-i)*(qpow(m, mod-2))%mod*(m-i)*(qpow((n-1)*m, mod-2))%mod;
		f[i] %= mod;
	}
	return f[a[x]];
}

signed main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	cin >> n >> m >> t;
	while(t--) {
		for(int i = 1; i <= n; i++)
		  cin >> a[i];
		int ans = 1e12;
		for(int i = 1; i <= n; i++)
		  ans = min(ans, dp(i));
		if(ans == 1) cout << 0 << '\n';
		else cout << ans << '\n';
	}
	return 0;
}
