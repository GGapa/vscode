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
	for (int i = 1; i <= 5000; ++ i)
		if (1ll * x * i % mod <= 10000) {
			printf("%d/%d ", 1ll * x * i % mod, i);
			return;
		}
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
			printf("%d: ", i); print(vfi[i]); print(vfip1[i]); print(vfc[i]); puts("");
		}
		f[m - 1] = vfc[m - 1]; for (int i = m - 2; i; -- i) f[i] = (1ll * vfip1[i] * f[i + 1] % mod + vfc[i]) % mod;
		for (int i = 0; i <= m; ++ i) printf("%d: ", i), print(f[i]), puts("");
//		for (int i = 0; i <= m; ++ i) printf("%d ", f[i]); puts("");
		for (int a, b; t --; ) {
			scanf("%d%d", &a, &b);
			printf("%d\n", f[a]);
		}
	}
}
namespace test {
	int f[M];
	int vfi[M], vfip1[M], vfc[M];
	int a[N];
	inline void solve() {
		int inv = qpow(1ll * m * m % mod, mod - 2, mod);
		for (int i = 0; i < m; ++ i) {
			int v1 = 1ll * i * (1ll * (n - 2) * m % mod + i) % mod * inv % mod, v2 = 1ll * (m - i) * (m - i) % mod * inv % mod;
			if (i) vfi[i] = (mod - 1ll * v1 * vfip1[i - 1] % mod + v1 + v2) % mod; else vfi[i] = 1;
			vfip1[i] = 1ll * v2 * qpow(vfi[i], mod - 2, mod) % mod;
			vfc[i] = (1ll * v1 * vfc[i - 1] % mod + 1) % mod * qpow(vfi[i], mod - 2, mod) % mod;
			printf("%d: ", i); print(vfi[i]); print(vfip1[i]); print(vfc[i]); puts("");
		}
		f[m - 1] = vfc[m - 1]; for (int i = m - 2; ~i; -- i) f[i] = (1ll * vfip1[i] * f[i + 1] % mod + vfc[i]) % mod;
		for (int i = 0; i <= m; ++ i) printf("%d: ", i), print(f[i]), puts("");
		print(825297686); puts("");
		print(559099197); puts("");
		for (; t --; ) {
			for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
			for (int i = 1; i <= n; ++ i) {
				printf("%d: ", a[i]); print(f[a[i]]); puts("");
			}
		}
	}
}
int main() {
//	freopen("c.in", "r", stdin);
//	freopen("c.out", "w", stdout);
//	printf("%lf\n", 6176564.0 / 48067.0);
//	printf("%d\n", (7 * 13 + 2 * 6176564) / 48067);
//	printf("%d\n", (48067 * 257 - 13 * 7) / 2); // 13 * 7 + 48067 * 128
	scanf("%d%d%d", &n, &m, &t);
	if (n == 1) {
		puts("0");
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
	test::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
