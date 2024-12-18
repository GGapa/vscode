#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 5, P = 998244353;
int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2) res = 1ll * res * a % P;
		a = 1ll * a * a % P;
		b /= 2;
	}
	return res;
}
int n, m, t, f[N];
int k[N], b[N];
int im;
void dp() {
	k[1] = 1;
	im = 1ll * power(m, P - 2) * power(m, P - 2) % P;
	for (int i = 1; i < m; i++) {
		int l = 1ll * i * i % P * im % P, r = 1ll * (m - i) * (m - i) % P * im % P, ir = power(r, P - 2);
		k[i + 1] = 1ll * (1ll * k[i] * (l + r) % P - 1ll * k[i - 1] * l % P + P) * ir % P;
		b[i + 1] = 1ll * (1ll * b[i] * (l + r) % P - 1ll * b[i - 1] * l % P - 1 + P) * ir % P;
	}
	f[1] = 1ll * (P - b[m]) * power(k[m], P - 2) % P;
	for (int i = 1; i < m; i++) {
		int l = 1ll * i * i % P * im % P, r = 1ll * (m - i) * (m - i) % P * im % P, ir = power(r, P - 2);
		f[i + 1] = 1ll * (1ll * f[i] * (l + r) % P - 1ll * f[i - 1] * l % P - 1 + P) * ir % P;
	}
}
int main() {
	freopen("c.in", "r", stdin), freopen("c.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> t;
	dp();
	while (t--) {
		int p, q;
		cin >> p >> q;
		cout << f[p] << "\n";
	}
	return 0;
}