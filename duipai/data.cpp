#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());

signed main() {
	freopen("test.in", "w", stdout);
	int n = 1000;
	cout << n << '\n';
	vector<int> fa(n + 1);
	for(int i = 1; i <= n; i++) cout << uniform_int_distribution<>(-1000000000, 1000000000)(rnd) << " \n"[i == n];
	for(int i = 2; i <= n; i++) fa[i] = uniform_int_distribution<>(1, i - 1)(rnd);
	for(int i = 2; i <= n; i++) cout << fa[i] << " " << i << '\n';
}
