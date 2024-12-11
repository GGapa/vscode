#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;
#define F(i, a, b) for(int i = a; i <= (b); ++i)
#define F2(i, a, b) for(int i = a; i < (b); ++i)
#define dF(i, a, b) for(int i = a; i >= (b); --i)
template<typename T> void debug(string s, T x) {
	cerr << "[" << s << "] = [" << x << "]\n";
}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {
	for (int i = 0, b = 0; i < (int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
	else if (s[i] == ')' || s[i] == '}') b--;
	else if (s[i] == ',' && b == 0) {
		cerr << "[" << s.substr(0, i) << "] = [" << x << "] | ";
		debug(s.substr(s.find_first_not_of(' ', i + 1)), args...);
		break;
	}
}
#ifdef ONLINE_JUDGE
#define Debug(...)
#else
#define Debug(...) debug(#__VA_ARGS__, __VA_ARGS__)
#endif
#define pb push_back
#define fi first
#define se second
#define Mry fprintf(stderr, "%.3lf MB\n", (&Med - &Mbe) / 1048576.0)
#define Try cerr << 1e3 * clock() / CLOCKS_PER_SEC << " ms\n";
typedef long long ll;
//namespace Fread {const int SIZE = 1 << 17; char buf[SIZE], *S, *T; inline char getchar() {if (S == T) {T = (S = buf) + fread(buf, 1, SIZE, stdin); if (S == T) return '\n';} return *S++;}}
//namespace Fwrite {const int SIZE = 1 << 17; char buf[SIZE], *S = buf, *T = buf + SIZE; inline void flush() {fwrite(buf, 1, S - buf, stdout), S = buf;} inline void putchar(char c) {*S++ = c;if (S == T) flush();} struct NTR {~NTR() {flush();}} ztr;}
// #ifdef ONLINE_JUDGE
//#define getchar Fread::getchar
//#define putchar Fwrite::putchar
// #endif
inline int ri() {
	int x = 0;
	bool t = 0;
	char c = getchar();
	while (c < '0' || c > '9') t |= c == '-', c = getchar();
	while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
	return t ? -x : x;
}
inline void wi(int x) {
	if (x < 0) {
		putchar('-'), x = -x;
	}
	if (x > 9) wi(x / 10);
	putchar(x % 10 + 48);
}
inline void wi(int x, char s) {
	wi(x), putchar(s);
}
bool Mbe;
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int _ = 1000 + 5;

int n1, n2, q, fa1[_], fa2[_];

vi d1[_], d2[_];

vector<pii> g1[_], g2[_];

namespace LCA {
	int cnt, dfn[_], st[13][_], dep[_], lg[_];
	int cmp(int a, int b) { return dfn[a] < dfn[b] ? a : b; }
	void dfs(int u, int fa = 0) {
		dfn[u] = ++cnt;
		dep[u] = dep[fa] + 1;
		st[0][cnt] = fa;
		for(int &v : d1[u]) dfs(v, u);
	}
	int LCA(int u, int v) {
		if(u == v) return u;
		if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
		int t = lg[v - u++];
		return cmp(st[t][u], st[t][v - (1 << t) + 1]);
	}
	int Dis(int u, int v) {
		return dep[u] + dep[v] - (dep[LCA(u, v)] << 1);
	}
	void init() {
		F(i, 2, n1) lg[i] = lg[i >> 1] + 1;
		dfs(1);
		F(j, 1, lg[n1]) F(i, 1, n1 - (1 << j) + 1) st[j][i] = cmp(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
	}
}

namespace LCA2 {
	int cnt, dfn[_], st[13][_], dep[_], lg[_];
	int cmp(int a, int b) { return dfn[a] < dfn[b] ? a : b; }
	void dfs(int u, int fa = 0) {
		dfn[u] = ++cnt;
		dep[u] = dep[fa] + 1;
		st[0][cnt] = fa;
		for(int &v : d2[u]) dfs(v, u);
	}
	int LCA(int u, int v) {
		if(u == v) return u;
		if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
		int t = lg[v - u++];
		return cmp(st[t][u], st[t][v - (1 << t) + 1]);
	}
	int Dis(int u, int v) {
		return dep[u] + dep[v] - (dep[LCA(u, v)] << 1);
	}
	void init() {
		F(i, 2, n2) lg[i] = lg[i >> 1] + 1;
		dfs(1);
		F(j, 1, lg[n2]) F(i, 1, n2 - (1 << j) + 1) st[j][i] = cmp(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
	}
}

int rt1, rt2;

int Mx1, Mx2;

void build1(vi &a) {
	sort(a.begin(), a.end(), [&](int x, int y) { return LCA::dfn[x] < LCA::dfn[y]; });
	int len = a.size();
	F(i, 0, len - 1) a.pb(LCA::LCA(a[i], a[(i + 1) % len]));
	sort(a.begin(), a.end(), [&](int x, int y) { return LCA::dfn[x] < LCA::dfn[y]; });
	a.resize(unique(a.begin(), a.end()) - a.begin());
	len = a.size();
	LCA::dep[0] = inf;
	F(i, 1, len - 1) {
		int y = LCA::LCA(a[i - 1], a[i]);
		int w = LCA::Dis(y, a[i]);
//		Debug("1", y, a[i], w);
		if(LCA::dep[y] < LCA::dep[rt1]) rt1 = y;
		Mx1 = max(Mx1, w);
		g1[y].pb(make_pair(a[i], w));
	}
}

void build2(vi &a) {
	sort(a.begin(), a.end(), [&](int x, int y) { return LCA2::dfn[x] < LCA2::dfn[y]; });
	int len = a.size();
	F(i, 0, len - 1) a.pb(LCA2::LCA(a[i], a[(i + 1) % len]));
	sort(a.begin(), a.end(), [&](int x, int y) { return LCA2::dfn[x] < LCA2::dfn[y]; });
	a.resize(unique(a.begin(), a.end()) - a.begin());
	len = a.size();
	LCA2::dep[0] = inf;
	F(i, 1, len - 1) {
		int y = LCA2::LCA(a[i - 1], a[i]);
		int w = LCA2::Dis(y, a[i]);
//		Debug(y, a[i], w);
		if(LCA2::dep[y] < LCA2::dep[rt2]) rt2 = y;
		Mx2 = max(Mx2, w);
		g2[y].pb(make_pair(a[i], w));
	}
}
const int base = 177;
unsigned has[_], sz[_], f[_], has2[_], sz2[_];

unsigned Rnd(unsigned x) {
	x ^= x << 14;
	x ^= x >> 6;
	x ^= x << 3;
	x ^= x >> 7;
	return x;
}
void dfs(int x, int fa) {
	has[x] = f[7];
	sz[x] = 1;
	for (pii v : g1[x]) if (v.fi != fa) {
		dfs(v.fi, x);
		sz[x] += sz[v.fi];
		has[x] += f[sz[v.fi]] * Rnd(has[v.fi]);
	}
}

void dfs2(int u, int fa) {
	has2[u] = f[7];
	sz[u] = 1;
	for(pii v : g2[u]) if(v.fi != fa) {
		dfs2(v.fi, u);
		sz[u] += sz[v.fi];
		has2[u] += f[sz[v.fi]] * Rnd(has2[v.fi]);
	}
}

int g[_][_], fac[_], inv[_];

int qpow(int x, int y) {
	int res = 1;
	while(y) {
		if(y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod, y >>= 1;
	} return res;
}

int du[_];
bool Med;
signed main() {
	// Mry;
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout); 
//	freopen("ex_b2.in", "r", stdin);
	f[0] = 1;
	for (int i = 1; i <= 10; ++i) f[i] = f[i - 1] * base;
	n1 = ri(), n2 = ri();
	F(i, 2, n1) fa1[i] = ri(), d1[fa1[i]].pb(i);
	F(i, 2, n2) fa2[i] = ri(), d2[fa2[i]].pb(i);
	LCA::init(), LCA2::init();
	vi a;
	F(i, 2, n1) du[fa1[i]]++, du[i]++;
	F(i, 2, n1) if(du[i] == 1) a.pb(i);
	if(a.empty()) a.pb(1);
//	Debug(a.size(), du[1]);
//	a.pb(1);
	build1(a);
//	Debug(a.size(), g1[1].size());
	if(!rt1) rt1 = 1;
	dfs(rt1, 0);
	a.clear();
	F(i, 1, n2) du[i] = 0;
	F(i, 2, n2) du[fa2[i]]++, du[i]++;
	F(i, 2, n2) if(du[i] == 1) a.pb(i);
	if(a.empty()) a.pb(1);
//	Debug(a.size(), du[1]);
//	a.pb(1);
	build2(a);
//	Debug(a.size(), g2[1].size());
	if(!rt2) rt2 = 1;
	dfs2(rt2, 0);
//	Debug(has[rt1], rt1, has2[rt2], rt2);
	if(has[rt1] != has2[rt2]) {
		q = ri();
		while(q--) {
			ri(), ri();
			puts("0");
		}
		return 0;
	}
//	Debug("fhsf");
//	vi S;
	g[0][0] = 1;
	int n = max(n1, n2);
	fac[0] = 1;
	F(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[0] = 1;
	inv[n] = qpow(fac[n], mod - 2);
	dF(i, n - 1, 1) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
//	Debug(g1[1].size(), g2[1].size());
	q = ri();
	Mx1 = max(Mx1, LCA::Dis(1, rt1) + 1);
	Mx2 = max(Mx2, LCA2::Dis(1, rt2) + 1);
	while(q--) {
		int op = ri(), x = ri();
		if(op == 1) {
//			Debug(1);
//			S.pb(x), sort(S.begin(), S.end());
			dF(i, Mx1, 1) F(j, x, Mx2) {
				for(int k = 1; k * x <= j && k <= i; ++k) g[i][j] = (g[i][j] + 1ll * g[i - k][j - k * x] * inv[k] % mod) % mod;
			}
//			F(i, 1, n) F(j, x, n) g[i][j] = (g[i][j] + g[i - 1][j - x]) % mod;
		}
		else {
//			S.erase(find(S.begin(), S.end(), x));
			F(i, 1, Mx1) F(j, x, Mx2) {
				for(int k = 1; k * x <= j && k <= i; ++k) g[i][j] = (g[i][j] + mod - 1ll * g[i - k][j - k * x] * inv[k] % mod) % mod;
			}
//			dF(i, n, 1) dF(j, n, x) g[i][j] = (g[i][j] + mod - g[i - 1][j - x]) % moeed;
		}
//		Debug(g[2][3], g[1][1]);
//		memset(g, 0, sizeof g);
//		g[0][0] = 1;
//		for(int v : S) {
//			F(i, 1, n) F(j, v, n) g[i][j] = (g[i][j] + g[i - 1][j - v]) % mod;
//		}
//		int res = 0;
//		F(i, 1, n) F(j, 0, n) res = max(res, g[i][j]);
//		Debug(res);
		int ans = 1;
		queue<pii> q;
		q.push({rt1, rt2});
//		Debug(rt1, rt2);
		while(!q.empty()) {
			pii u = q.front();
			q.pop();
			int len = g1[u.fi].size();
//			Debug(u.fi, u.se);
			assert(g1[u.fi].size() == g2[u.se].size());
			if(u.fi == rt1 && u.se == rt2) {
				int w1 = LCA::Dis(1, rt1) + 1;
				ans = 1ll * ans * g[w1][LCA2::Dis(1, rt2) + 1] % mod * fac[w1] % mod;
			}
			F(i, 0, len - 1) {
				int v1 = g1[u.fi][i].fi, v2 = g2[u.se][i].fi;
//				Debug(ans);
				ans = 1ll * ans * g[g1[u.fi][i].se][g2[u.se][i].se] % mod * fac[g1[u.fi][i].se] % mod;
				q.push({v1, v2});
			}
		}
		cout << ans << '\n';
	}
	// Try;
	return 0;
}

/*
5 8
1 1 3 3
1 1 2 3 3 5 6
5
1 1
1 2
1 3
2 1
2 2
*/
