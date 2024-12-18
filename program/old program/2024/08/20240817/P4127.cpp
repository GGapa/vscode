#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int mod;
LL F[20][165][165]; 
int A[20];

LL dfs(LL len, LL sum, LL x, bool pos) {
    auto &f = F[len][sum][x];
	if(sum + 9 * len < mod) return 0;
	if(!len) return sum == mod && x == 0;
	if(F[len][sum][x] != -1 && !pos)
		return F[len][sum][x];
	int m = pos ? A[len]: 9;
	LL ans = 0;
	for (int i = 0; i <= m && i + sum <= mod; i++)
		ans += dfs(len - 1, sum + i, (10ll * x + i) % mod, i == A[len] && pos);
	if(!pos) F[len][sum][x]= ans;
	return ans;
} 

LL solve(LL n) {
	memset(A, 0, sizeof(A));
	LL x = n;
	LL len = 0;
	for (; x; x /= 10) A[++len] = x % 10;
	LL ans = 0;
	for (mod = 1; mod <= len * 9; mod ++) {
		memset(F, -1, sizeof(F));
		ans += dfs(len, 0, 0, 1);
	}
	return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL l, r; cin >> l >> r;
    cout << solve(r) - solve(l - 1) << '\n';
    return 0;
}