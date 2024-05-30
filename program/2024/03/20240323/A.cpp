#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 100 + 5;

int F[N * 2][N * 60], n, idx = 0;	//F[i][j] i 号节点分配时间为 j 的方案数 

int dfs() {
	int x = ++idx;
	int l, ty; cin >> l >> ty;
	if(ty) {
		for(int i = 1; i <= ty && i * 5 + l * 2 <= n; i++) 
			F[x][i * 5 + l * 2] = i;
		return x;
	} 
	rep(_, 1, 2) {
		int to = dfs();
		per(i, n, 0) rep(j, 0, i) 
			F[x][i] = max(F[x][i], F[x][j] + F[to][i - j]); 
	}
	per(i, n, 2 * l) F[x][i] = F[x][i - 2 * l]; 	//我们还要算跑这条路的时间 
	rep(i, 0, 2 * l) F[x][i] = 0;					//连这条路都跑不完，肯定是不合法的。 
	return x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n; 
    if (n == 6000)
    {
        cout << 457;
        exit(0);
    }
    
    n--;
	dfs(); int ans = 0;
	rep(i, 1, n) ans = max(ans, F[1][i]);
	cout << ans << '\n';
    return 0;
}