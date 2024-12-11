#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
const int N = 1e5 + 10, mod = 998244353;
int n, m, T, a[N], f[N], inv[N];
int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int qpow(int a, int k) {
	int res = 1;
	while(k) {
		if(k & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		k >>= 1;
	}
	return res;
}
int main() {
	n = read(), m = read(), T = read();
	inv[1] = 1;
	for(int i = 2; i <= 1e5; i++)
		inv[i] = mod - 1ll * mod / i * inv[mod % i] % mod;
	int t1 = 1ll * inv[m] * inv[n - 1] % mod;
	for(int i = 1; i < m; i++) {
		int f1 = 1ll * (m - i) * t1 % mod * i % mod * inv[m] % mod;
		f1 = add(f1, 1ll * (mod + 1 - 1ll * (m - i) * t1 % mod) * (mod + 1 - 1ll * i * inv[m] % mod) % mod);
		int f2 = 1ll * i * inv[m] % mod * (mod + 1 - 1ll * (m - i) * t1 % mod) % mod;
		int f3 = 1ll * (mod + 1 - 1ll * i * inv[m] % mod) * (m - i) * t1 % mod;
		f[i + 1] = qpow(f3, mod - 2);
		int s = 1ll * (mod + 1 - f1) * f[i] % mod;
		s = add(s, mod - 1ll * f2 * f[i - 1] % mod);
		s = add(s, 1ll * i * inv[m] % mod);
		f[i + 1] = 1ll * f[i + 1] * s % mod;
	}
	while(T--) {
		int s = 0;
		for(int i = 1; i <= n; i++)
			a[i] = read(), s = add(s, f[a[i]]);
		printf("%d\n", add(f[m], mod - s));
	}
	return 0;
}
