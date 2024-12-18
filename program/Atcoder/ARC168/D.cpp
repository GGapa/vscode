#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int N = 500 + 5;

int F[N][N], G[N][N][N]; 

/*
F[l][r] 代表 l 和 r 内全部被吃了的方案数量
G[l][r][i] 代表 l 和 r 内，i 是空闲的最大 w 
*/

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> w(m + 1), L(m + 1), R(m + 1);
	for(int i = 1; i <= m; i++) {
		cin >> L[i] >> R[i];
		rep(k, L[i], R[i]) G[L[i]][R[i]][k] = max(G[L[i]][R[i]][k], 1) ; 
	}
	per(i, n, 1) rep(j, i, n) rep(k, 1, n) 
		G[i][j][k] = max({G[i][j][k], G[i + 1][j][k], G[i][j - 1][k], G[i + 1][j - 1][k]});
	per(i, n, 1) rep(j, i, n)  rep(k, i, j) 
		F[i][j] = max({F[i][j], F[i][k - 1] + G[i][j][k] + F[k + 1][j]});
	cout << F[1][n] << '\n';
    return 0;  
 }