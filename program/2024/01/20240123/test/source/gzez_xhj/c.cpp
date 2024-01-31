#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
typedef long long lld;
using namespace std;
const int mod = 998244353;
const int N = 5010;
const int M = 100010;
inline int qpow(int a, int b, int p) {
	int ret = 1;
	for (; b; b >>= 1, a = 1ll * a * a % p)
		if (b & 1) ret = 1ll * ret * a % p;
	return ret;
}
inline void print(int x) {
	int mni = 1, mn = x;
	for (int i = 2; i <= 5000; ++ i)
		if (1ll * x * i % mod < mn)
			mni = i, mn = 1ll * x * i % mod;
	printf("%d/%d=%.2lf ", mn, mni, 1.0 * mn / mni);
}
int n, m, t;
int a[N];
namespace sub3 {
	int f[M];
	int vfi[M], vfip1[M], vfc[M];
	inline bool check() {
		return n == 2;
	}
	inline void solve() {
		int inv = qpow(1ll * m * m % mod, mod - 2, mod);
		for (int i = 1; i < m; ++ i) {
			int v1 = 1ll * i * i % mod * inv % mod, v2 = 1ll * (m - i) * (m - i) % mod * inv % mod;
			vfi[i] = (mod - 1ll * v1 * vfip1[i - 1] % mod + v1 + v2) % mod;
			vfip1[i] = 1ll * v2 * qpow(vfi[i], mod - 2, mod) % mod;
			vfc[i] = (1ll * v1 * vfc[i - 1] % mod + 1) % mod * qpow(vfi[i], mod - 2, mod) % mod;
		}
		f[m - 1] = vfc[m - 1]; for (int i = m - 2; i; -- i) f[i] = (1ll * vfip1[i] * f[i + 1] % mod + vfc[i]) % mod;
//		for (int i = 0; i <= m; ++ i) printf("%d ", f[i]); puts("");
		for (int a, b; t --; ) {
			scanf("%d%d", &a, &b);
			printf("%d\n", f[a]);
		}
	}
}
namespace test {
	int f[N][N];
	int a[N];
	inline void solve() {
		int inv = qpow(1ll * m * m % mod, mod - 2, mod);
		for (int k = 0; k <= m; ++ k) {
			memset(f, 0, sizeof(f));
			f[0][k] = 1;
			printf("%d: ", k);
			for (int t = 0; t < 10; ++ t) {
				for (int i = 0; i <= m; ++ i) {
					int v1 = 1ll * i * (1ll * (n - 2) * m % mod + i) % mod * inv % mod, v2 = 1ll * (m - i) * (m - i) % mod * inv % mod;
					int v = ((1 - v1 - v2) % mod + mod) % mod;
					if (i && i < m) f[t + 1][i - 1] = (f[t + 1][i - 1] + 1ll * f[t][i] * v1) % mod;
					if (i < m) f[t + 1][i + 1] = (f[t + 1][i + 1] + 1ll * f[t][i] * v2) % mod;
					f[t + 1][i] = (f[t + 1][i] + 1ll * f[t][i] * v % mod) % mod;
				}
				if (t) printf("%10lld/%lld ", 1ll * f[t][m] * qpow(1ll * m * m % mod, t, mod) % mod, qpow(1ll * m * m % mod, t, mod));
			}
			puts("");
		}
		for (; t --; ) {
			for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
		}
	}
}
int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &t);
	if (n == 1) {
		for (; t --; ) puts("0");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if (sub3::check()) {
		sub3::solve();
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for (; t --; ) puts("0");
//	test::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
