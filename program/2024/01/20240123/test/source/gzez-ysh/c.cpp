#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
inline int read() {
	int s = 0,f = 1;char ch = getchar();
	while (!isdigit(ch)) f = ch == '-' ? -1 : 1, ch = getchar();
	while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
	return s * f;
}
const int mod = 998244353;
ll f[N + 10],a[N + 10];
int qpow(int a,int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		b >>= 1, a = 1ll * a * a % mod;
	}
	return res;
}
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int n = read(),m = read(),T = read();
//	f[0] = f[1] = 0;
	for (int i = 1;i < m;i ++ ) {
		ll x1 = (n - 1ll) * m % mod * m % mod - 1ll * (m - i) * ((n - 2ll) * m % mod + i + i) % mod;
		x1 = (x1 % mod + mod) % mod;
		ll x2 = 1ll * i * ((n - 2ll) * m % mod + i) % mod,x3 = 1ll * (m - i) * (m - i) % mod;
		ll cs = (n - 1ll) * m % mod * i % mod;
		f[i + 1] = ((1ll * f[i] * x1 - 1ll * f[i - 1] * x2 - cs) % mod + mod) * qpow(x3,mod - 2) % mod;
	}
	for (int tt = 1;tt <= T;tt ++ ) {
		int s = 0;
		for (int i = 1;i <= n;i ++ ) s = (s + f[read()]) % mod;
//				for (int i = 1,x;i <= n;i ++ ) x = read(), s = (s + f[x]) % mod;
		int res = 0;
		res = ((s - f[m] - (n - 1ll) * f[0]) % mod + mod) % mod;
		printf("%d\n",res);
	}
	return 0;
}
/*
6 7 1
1 1 1 2 2 0

*/
