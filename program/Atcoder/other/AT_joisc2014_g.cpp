#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

template <typename T>
constexpr void chkmin(T &x, const T &y) {x = min(x, y); }

constexpr int INF = 1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, t; cin >> n >> t;
    vector<VI> F(n + 2, VI(n + 2, INF));
	F[0][0] = 0;
	for(int i = 1, u, v, d, e; i <= n; i++) {
		cin >> u >> v >> d >> e;
		rep(j, 1, n) if(F[i - 1][j] < INF) F[i - 1][j] += 2 * j * t;
		rep(j, 0, n) chkmin(F[i][j], F[i - 1][j] + u + v);
		rep(j, 1, n) chkmin(F[i][j], F[i - 1][j] + d + e);
		rep(j, 1, n) chkmin(F[i][j], F[i - 1][j - 1] + d + v);
		rep(j, 0, n - 1) chkmin(F[i][j], F[i - 1][j + 1] + u + e);
		rep(j, 1, n) chkmin(F[i][j], F[i][j - 1] + d + v);
		per(j, n - 1, 0) chkmin(F[i][j], F[i][j + 1] + u + e);
	}
    cout << F[n][0] + t * (n + 1) << '\n';
    return 0;
}
