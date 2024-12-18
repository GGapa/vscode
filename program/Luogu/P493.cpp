#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000  + 5;
const int mod = 998244353;
#define int long long
#define _foru(i, a, b) for(int i = (a); i <= (b); i++)
#define _ford(i, a, b) for(int i = (a); i >= (b); i--)

int a[maxn], f[maxn][100000 / 2];
int n;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0) ;
	cout.tie(0) ;
	//freopen("AKIOI.in", "r", stdin);
	//freopen("AKIOI.out", "w", stdout);
	int ans = 0;
	cin >> n;
	_foru(i, 1, n) cin >> a[i], f[i][0] = 1;
	for(int i = 1; i <= n; i++) {
		ans++;
		for(int j = (i - 1); j >= (1); j--) {
			int p = a[i] - a[j] + 20000;
			f[i][p] = (f[i][p] + f[j][p] + 1) % mod;
			ans = (ans + f[j][p] + 1) % mod;
		}
	}
	cout << ans % mod << "\n";
	return 0;
}