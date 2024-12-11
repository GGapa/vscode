#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s;
	using VI = vector<int>;
	vector<VI> F(n + 1, VI(k + 1)), G(n + 1, VI(n + 1));
	 
	rep(i, 0, n - 1) for(int len = 1, j; len + i <= n; len++) {
		j = i + len - 1;
		auto t = s.substr(i, len); if(t == "") continue;
		G[i][j]	= stoi(t);
	}
	rep(i, 0, n - 1) F[i][0] = G[0][i];
	rep(c, 1, k) rep(i, 0, n - 1) rep(j, c - 1, i - 1) {
		auto &f = F[i][c];
		f = max(f, F[j][c - 1] + G[j + 1][i]);
	}
	cout << F[n - 1][k] << '\n';
    return 0;
}
/*
6 2
340670

*/
