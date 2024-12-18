#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, mod = 998244353;
int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
char s[N];
int a[N];
int n;
int pos[N], tot, suf[N], suft[N], pre[N], pret[N];
int fac[N], ifac[N];
int qpow(int a, int k) {
	int res = 1;
	while(k) {
		if(k & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		k >>= 1; 
	}
	return res;
}
int pw2[N];
int C(int n, int m) { return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
int C1[N], C2[N];
int main() {
//	freopen("physics.in", "r", stdin);
//	freopen("physics.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	fac[0] = pw2[0] = 1;
	for(int i = 1; i <= n; i++)
		pw2[i] = 2ll * pw2[i - 1] % mod;
	for(int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[n] = qpow(fac[n], mod - 2);
	for(int i = n - 1; ~i; i--)
		ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
	int cnt = 0, tot = 0;
	for(int i = 1; i <= n; i++)
		cnt += s[i] == '+',
		tot += s[i] == '?';
	for(int i = tot; ~i; i--)
		C1[i] = add(C1[i + 1], C(tot, i));
	for(int i = tot - 1; ~i; i--)
		C2[i] = add(C2[i + 1], C(tot - 1, i));
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(s[i] == '+') continue;
		if(s[i] == '?') {
			if(i <= cnt) ans = add(ans, pw2[tot - 1]);
			else if(i > cnt + tot - 1);
			else ans = add(ans, C2[i - cnt]);
		}
		if(s[i] == '-') {
			if(i <= cnt) ans = add(ans, pw2[tot]);
			else if(i > cnt + tot);
			else ans = add(ans, C1[i - cnt]);
		}
//		cout << ans << endl;
	}
	printf("%d\n", ans);
	return 0;
}
