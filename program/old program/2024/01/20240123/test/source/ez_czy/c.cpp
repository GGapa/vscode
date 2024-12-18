#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline int Mod(int x) { return x + ((x >> 31) & mod); }
inline int add(int x, int y) { return Mod(x + y - mod); }
inline int sub(int x, int y) { return Mod(x - y); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline int sqr(int x) { return 1ll * x * x % mod; }
int qpow(int a, int b) {
	if (!b) return 1;
	int t = qpow(a, b >> 1);
	t = mul(t, t);
	if (b & 1) return mul(t, a);
	return t;
}
const int maxm = 100000;
int f[maxm + 5];
int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < m; i++) {
        int p = qpow(sqr(m - i), mod - 2), q = mul(mul(add(mul(n - 2, m), i), i), p);
        f[i + 1] = sub(mul(q + 1, f[i]), mul(mul(n - 1, mul(m, i)), p));
        if (i) f[i + 1] = sub(f[i + 1], mul(q, f[i - 1]));
    }
    for (int i = 1; i <= t; i++) {
        int sum = Mod(-f[m]);
        for (int j = 1, a; j <= n; j++) {
            scanf("%d", &a);
            sum = add(sum, f[a]);
        }
        printf("%d\n", sum);
    }
}