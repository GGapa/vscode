#include <bits/stdc++.h>
using namespace std;
#define _rep(i_,a_,b_) for(int i_ = (a_); i_ <= (b_); ++i_)
#define mid ((L+R) >> 1)
#define multiCase() int testCnt = in(); _rep(curCase,1,testCnt)
#ifdef ONLINE_JUDGE
#define debug(...) 0
#else
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#endif
using ll = long long;
using pii = pair<int,int>;

int in(void) { int x; scanf("%d", &x); return x; } ll inl(void) { ll x; scanf("%lld", &x); return x; }
void out(int x) { printf("%d ", x); } void outln(int x) { printf("%d\n", x); }
void out(ll x) { printf("%lld ", x); } void outln(ll x) { printf("%lld\n", x); }
template<typename T> void chkmax(T &a, const T &b) { a = max(a, b); } 
template<typename T> void chkmin(T &a, const T &b) { a = min(a, b); } 
const int kN = 805, p = 1000000007;
int n1, n2;
vector<int> g1[kN], g2[kN];
int siz1[kN], siz2[kN], C[kN][kN];
vector<int> g3[kN], g4[kN];
void dfs1(int u, int o) {
	++siz1[o];
	for(auto &v : g1[u]) {
		if(g1[u].size() == 1) dfs1(v, o);
		else g3[o].emplace_back(v), dfs1(v, v);
	}
}
void dfs2(int u, int o) {
	++siz2[o];
	for(auto &v : g2[u]) {
		if(g2[u].size() == 1) dfs2(v, o);
		else g4[o].emplace_back(v), dfs2(v, v);
	}
}
vector<pii> cmp;
bool error;
void dfs3(int u, int v) {
	cmp.emplace_back(siz1[u], siz2[v]);
	if(g3[u].size() != g4[v].size()) { error = true; return; }
	for(int i = 0; i < g3[u].size(); ++i) dfs3(g3[u][i], g4[v][i]);
}
int f[kN][kN];
int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	n1 = in(), n2 = in();
	C[0][0] = 1;
	_rep(i,1,800) {
		C[i][0] = C[i][i] = 1;
		_rep(j,1,i - 1) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % p;
	}
	_rep(i,2,n1) g1[in()].emplace_back(i);
	_rep(i,2,n2) g2[in()].emplace_back(i);
	_rep(i,1,n1) sort(g1[i].begin(), g1[i].end());
	_rep(i,1,n2) sort(g2[i].begin(), g2[i].end());
	dfs1(1, 1), dfs2(1, 1);
	dfs3(1, 1);
	if(error) {
		multiCase() puts("0");
		return 0;
	}
	// for(auto &p : cmp) debug("(%d, %d)\n", p.first, p.second);
	f[0][0] = 1;
	set<int> s;
	multiCase() {
		int op = in(), v = in();
		if(op == 1) {
			// s.insert(x);
			for(int i = n1; i; --i)
				for(int j = n2; j; --j)
					_rep(k,1,min(i, j / v))
						f[i][j] = (f[i][j] + 1ll * C[i][k] * f[i - k][j - k * v] % p) % p;
			// for(int i = n1; i; --i)
			// 	for(int j = n2; j; --j)
			// 		_rep(k,1,i)
			// 			if(j >= k * v)
			// 				f[i][j] = (f[i][j] + 1ll * C[i][k] * f[i - k][j - k * v] % p) % p;
			// int w = n1, v = x;
			// for(int i = 9; ~i; --i) if(w & (1 << i)) {
			// 	int w_ = 1 << i, v_ = x * w_;
			// 	_rep(i,w_,n1) _rep(j,v_,n2) f[i][j] = (f[i][j] + f[i - w_][j - v_]) % p;
			// 	w -= w_;
			// }
			// if(w) {
			// 	v = w * x;
			// 	_rep(i,w,n1) _rep(j,v,n2) f[i][j] = (f[i][j] + f[i - w][j - v]) % p;
			// }
		} else {
			_rep(i,1,n1)
				_rep(j,1,n2)
				// for(int j = n2; j; --j)
					_rep(k,1,min(i, j / v))
						f[i][j] = (f[i][j] - 1ll * C[i][k] * f[i - k][j - k * v] % p + p) % p;
			// s.erase(x);
			// for(int i = n1; i; --i) _rep(j,x,n2) f[i][j] = (f[i][j] - f[i - 1][j - x] + p) % p;
			// throw runtime_error("todo");
		}
		// memset(f, 0, sizeof(f));
		// f[0][0] = 1;
		// for(auto &v : s) {
			// for(int i = n1; i; --i)
			// 	for(int j = n2; j; --j)
			// 		_rep(k,1,min(i, j / v))
			// 			f[i][j] = (f[i][j] + 1ll * C[i][k] * f[i - k][j - k * v] % p) % p;
		// }
		int tot = 1;
		for(auto z : cmp) {
			tot = 1ll * tot * f[z.first][z.second] % p; 
			// if(f[z.first][z.second]) debug("f[%d][%d] = %d\n", z.first, z.second, f[z.first][z.second]);
		}
		outln(tot);
		// if(tot == 180) {
			// _rep(i,1,3) _rep(j,1,50) debug("f[%d][%d] = %d\n", i, j, f[i][j]);
			// for(auto v : s) debug("%d ", v);
			// debug("\n");
		// }
	}
    return 0;
}