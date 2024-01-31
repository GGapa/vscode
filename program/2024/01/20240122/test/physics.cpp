#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
const int mod = 998244353;

string s;
int n, type[N], fu[N], zh[N], unk[N];
int fz[N], ff[N];
ll ans = 0; 
vector<int> un;
void work() {
	memset(fu, 0, sizeof(fu));
	memset(zh, 0, sizeof(zh));
	rep(i, 1, n) {
		fu[i] = fu[i-1] + (s[i] == '-');
		zh[n - i + 1] = zh[n - i + 2] + (s[n - i + 1] == '+');
		unk[i] = unk[i-1] + (s[i] == '?');
	}
}

void dfs(int x) {
//	cout << x << endl;
//	cout << s << endl; 
	if(x >= un.size()) {
		if(x == un.size()) {
//			work();
			rep(i, 1, n) {
				ff[i] += ff[i-1];
				fz[n - i + 1] += fz[n - i + 2]; 
				fu[i] += ff[i];
				zh[n - i + 1] += fz[n - i + 1];
			}
			rep(i, 1, n) {
				fz[i] = ff[i] = 0;
				if(s[i] == '-' && zh[i+1] - fu[i-1] > 0) ans++;
			}
//			memset(ff, 0, sizeof(ff));
//			memset(fz, 0, sizeof(fz));
			ans %= mod;
		}
		return ;
	}
	fz[un[x]] = 1;
	s[un[x]] = '+';
	dfs(x + 1);
	fz[un[x]] = -1;
	ff[un[x]] = 1;
	s[un[x]] = '-';
	dfs(x + 1);
	ff[un[x]] = -1;
}

namespace A2 {
	int main() {
		rep(i, 1, n) if(s[i] == '-' && zh[i+1] - fu[i-1] > 0) ans++;
		cout << ans << '\n';
		return 0; 
	}
}

ll qpow(ll x, ll y) {
	ll sum = 1;
	while(y) {
		if(y & 1) sum = sum * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return sum;
}

namespace A3 {
	ll inv[N], mul[N]/*, cc[5005][5005]*/;
	ll C(ll x, ll y) {
		if(x == 0 || x == y) return 1;
		return mul[y] * inv[y - x] % mod * inv[x] % mod;
	}
	void init() {
		mul[0] = 1;
		rep(i, 1, n) {
			mul[i] = mul[i - 1] * i % mod;
			inv[i] = qpow(mul[i], mod -  2);
		}
//		cc[1][1] = 1;
//		rep(i, 0, n) cc[0][i] = cc[i][0] = 1;
//		rep(i, 2, 5e3) {
//			rep(j, 1, i) {
//				cc[i][j] = (cc[i-1][j] + cc[i-1][j-1]) % mod;
//			}
//		}		

	}
	
	int main() {
		ans = 0;
		init();
		rep(i, 1, n) {
			if(s[i] == '-' || s[i] == '?') {
				
				rep(x1, max(0, fu[i-1] - zh[i]), unk[n] - unk[i]) {
					int tt1 = 0, tt2 =  0;
					rep(x2, 0, min(unk[i - 1], zh[i] + x1 - fu[i - 1] - 1)) {
						ans = (ans + C(x2, unk[i - 1]) * C(x1, unk[n] - unk[i]) % mod) % mod;
//						tt1 = (tt1 + cc[unk[i - 1]][x2]) % mod; tt2 += (cc[unk[n] - unk[i]][x1]) % mod;
//						ans = (ans + (cc[unk[i - 1]][x2] * cc[unk[n] - unk[i]][x1]) % mod) % mod;
					}
//					ans = (ans + (tt1 * tt2) % mod) % mod;
				}
			}	
		}
		cout << ans % mod<< '\n';
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("physics.in", "r", stdin);
	freopen("physics.out", "w", stdout);
	cin >> s;
	n = s.length();
	s.insert(0, " ");
	rep(i, 1, n) if(s[i] == '?') un.push_back(i);
	work();
//	A3::main();
	if(unk[n] == 0) {
		A2::main();
		return 0;
	}
	if(n <= 2e6) {
		A3::main();
		return 0;
	} 
//	dfs(0);
	cout << ans << '\n';
	return 0;
}
