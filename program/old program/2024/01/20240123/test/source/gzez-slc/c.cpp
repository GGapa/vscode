#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxm = 1e5 + 5;

int add(int x, int y)
{
	return (x + y) % mod;
}

int mul(int x, int y)
{
	return (1ll * x * y) % mod;
}

int fast_power(int x, int y)
{
	if (y == 0)
		return 1;

	int h = fast_power(x, y / 2);
	h = mul(h, h);
	if (y % 2 == 0)
		return h;
	return mul(h, x);
}

int inv(int x)
{
	return fast_power(x, mod - 2);
}

int f[maxm];

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);

	int n, m, T;
	scanf("%d %d %d", &n, &m, &T);
	f[0] = f[1] = 0;
	const int im = mul(m, n - 1);
	for (int x = 1; x < m; ++x) {
		const int Lx = mul(x, add(mul(n, m), add(mod - 2 * m, x)));
		const int Rx = mul(m - x, m - x);
		const int RxFx1 = add(mul(add(Lx, Rx), f[x])
				, mod - add(mul(x, im), mul(Lx, f[x - 1])));
		f[x + 1] = mul(inv(Rx), RxFx1);
	}

	for (int _ = 0; _ < T; ++_) {
		int ans = mod - add(mul(f[0], n - 1), f[m]);
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			ans = add(ans, f[x]);
		}
		printf("%d\n", ans);
	}

	return 0;
}
