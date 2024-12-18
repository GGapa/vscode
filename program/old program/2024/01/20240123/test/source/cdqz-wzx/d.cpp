#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int P = 998244353;
int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2) res = 1ll * res * a % P;
		a = 1ll * a * a % P;
		b /= 2;
	}
	return res;
}
int inv(int x) {
	return power(x, P - 2);
}
signed main() {
	freopen("d.in", "r", stdin), freopen("d.out", "w", stdout);
	int n, m, k, p, t;
	cin >> n >> m >> k >> p >> t;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
	}
	vector<array<int, 3>> edges(m);
	for (auto &it : edges) {
		cin >> it[0] >> it[1] >> it[2];
		it[0]--;
		it[1]--;
	}
	vector<int> vp;
	for (int S = 0; S < (1 << (n + m)); S++) {
		if (__builtin_popcount(S) == p) {
			vp.push_back(S);
		}
	}
	int ans = 0;
	for (int S = 0; S < (1 << n); S++) {
		int bad = 0;
		for (auto it : edges) {
			int u = it[0], v = it[1];
			if ((S >> u & 1) && (S >> v & 1)) {
				bad = 1;
				break;
			}
		}
		if (bad) continue;
		int sum = 0, num = 0;
		for (int i = 0; i < n; i++) {
			if (S >> i & 1) {
				(sum += a[i]) %= P;
				num++;
			}
		}
		for (auto it : edges) {
			int u = it[0], v = it[1], w = it[2];
			if (!(S >> u & 1) && !(S >> v & 1)) {
				(sum += w) %= P;
				num++;
			}
		}
		for (int T : vp) {
			int val = sum;
			for (int j = 0; j < num; j++) {
				if (T >> j & 1) {
					(val += t) %= P;
				}
			}
			(ans += power(val, k)) %= P;
		}
	}
	cout << 1ll * ans * inv(vp.size()) % P << "\n";
	return 0;
}