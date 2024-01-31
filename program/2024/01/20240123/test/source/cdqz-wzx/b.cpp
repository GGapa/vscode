#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
constexpr int N = 805, Q = 105, P = 1e9 + 7;
int n1, n2, q, f1[N], f2[N];
vector<int> t1[N], t2[N];
int zl[N];
namespace bb {
int f[N][N];
set<int> sb;
void add(int x) {
	sb.insert(x);
}
void del(int x) {
	sb.erase(x);
}
void calc() {
	memset(f, 0, sizeof f);
	f[0][0] = 1;
	for (int i = 1; i <= n1; i++) {
		for (int x : sb) {
			for (int j = x; j <= n2; j++) {
				(f[i][j] += f[i - 1][j - x]) %= P;
			}
		}
	}
}
}
int ans;
void dfs(int u, int v) {
	int len = 1;
	while (t2[v].size() == 1) v = t2[v][0], len++;
	ans = 1ll * ans * bb::f[zl[u]][len] % P;
	if (t1[u].size() != t2[v].size()) {
		ans = 0;
		return;
	}
	for (int i = 0; i < t1[u].size(); i++) {
		dfs(t1[u][i], t2[v][i]);
	}
}
void solve() {
	ans = 1;
	dfs(1, 1);
	cout << ans << "\n";
}
int main() {
	freopen("b.in", "r", stdin), freopen("b.out", "w", stdout);
	cin >> n1 >> n2;
	for (int i = 1; i <= n1; i++) {
		zl[i] = 1;
	}
	for (int i = 2; i <= n1; i++) {
		cin >> f1[i];
		t1[f1[i]].push_back(i);
	}
	for (int i = 2; i <= n2; i++) {
		cin >> f2[i];
		t2[f2[i]].push_back(i);
	}
	for (int i = 2; i <= n1; i++) {
		if (t1[f1[i]].size() == 1) {
			int f = f1[i];
			t1[f] = t1[i];
			for (int j : t1[i]) {
				f1[j] = f;
			}
			zl[f]++;
			f1[i] = 0;
		}
	}
	bb::f[0][0] = 1;
	cin >> q;
	while (q--) {
		int o, x;
		cin >> o >> x;
		if (o == 1) {
			bb::add(x);
		} else {
			bb::del(x);
		}
		bb::calc();
		solve();
	}
	return 0;
}