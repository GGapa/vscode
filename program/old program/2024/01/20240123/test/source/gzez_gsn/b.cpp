#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define per(i, a, b) for(int i = a; i >= b; --i)
#define mkp make_pair
#define pii pair<int, int>
#define fr first
#define se second 
const int maxn = 805;
const ll mod = 1e9 + 7;
int n1, n2, fa[2][maxn];
vector<int> e[2][maxn], T[2][maxn]; int dis[2][maxn];
int vis[2][maxn], dep[2][maxn];
ll f[maxn][maxn], g[maxn][maxn];
vector<pii> getA;
set<int> S;

inline void dfs(int x, int lst, int k){
	dep[k][x] = dep[k][fa[k][x]] + 1;
	if(!vis[k][x]){
		for(int v : e[k][x]) dfs(v, lst, k);
	} else{
		T[k][lst].push_back(x), dis[k][x] = dep[k][x] - dep[k][lst];
		for(int v : e[k][x]) dfs(v, x, k); 
	}
}

int Flg = 0; int mxx = 0, mxy = 0;
inline void jdg(int x, int y){
	if(Flg) return;
//	if((!x and y) or (!y and x)) return Flg = 1, void();
	if(T[0][x].size() != T[1][y].size()) return Flg = 1, void();
	if(!T[0][x].size()) return;
	for(int j = 0; j < T[0][x].size(); ++j){
		int xx = T[0][x][j], yy = T[1][y][j];
		getA.push_back(mkp(dis[0][xx], dis[1][yy]));
		mxx = max(mxx, dis[0][xx]), mxy = max(mxy, dis[1][yy]);
		jdg(xx, yy);
	}
}

int main(){
	freopen("b.in", "r", stdin); freopen("b.out", "w", stdout);
//	return system("fc 2.txt 3.txt"), 0;
//	return system("fc 2.txt ex_b2.ans"), 0;
//	freopen("1.txt", "r", stdin); freopen("2.txt", "w", stdout);
//	freopen("ex_b2.in", "r", stdin); freopen("2.txt", "w", stdout);
	scanf("%d%d", &n1, &n2);
	rep(i, 2, n1) scanf("%d", &fa[0][i]),
		e[0][fa[0][i]].push_back(i);
	rep(i, 2, n2) scanf("%d", &fa[1][i]),
		e[1][fa[1][i]].push_back(i);
	rep(i, 1, n1) 
		sort(e[0][i].begin(), e[0][i].end()),
		(e[0][i].size() != 1) and (vis[0][i] = 1);
	rep(i, 1, n2)
		sort(e[1][i].begin(), e[1][i].end()),
		(e[1][i].size() != 1) and (vis[1][i] = 1);
	dfs(1, 0, 0), dfs(1, 0, 1);
	jdg(0, 0);
	
//	rep(i, 1, n2) if(vis[1][i]){
//		printf("i=%d numson=%d dis=%d\n", i, T[1][i].size(), dis[1][i]);
//	}
	
	int q; scanf("%d", &q);
	f[0][0] = 1ll; int n = max(n1, n2); g[0][0] = 1ll;
	while(q--){
		int opt, x; scanf("%d%d", &opt, &x);
		if(opt == 1){
			S.insert(x); 
			rep(i, 1, mxx) rep(j, x, mxy) 
				g[i][j] += g[i - 1][j - x],
				(g[i][j] >= mod) and (g[i][j] -= mod);
		} else{
			S.erase(x); 
			per(i, mxx, 1) per(j, mxy, x)
				g[i][j] += mod - g[i - 1][j - x],
				(g[i][j] >= mod) and (g[i][j] -= mod);
		}
		int flgg = 0;
		for(pii nw : getA){
			if(nw.fr > nw.se) flgg = 1;
			if(g[nw.fr][nw.se] == 0) flgg = 1;
			if(flgg) break;
		}
		if(flgg or Flg){ printf("0\n"); continue;}
		
//		if(opt == 1) S.insert(x); else S.erase(x);
//		if(opt == 1){
//			per(i, n, 1) rep(j, x, n) rep(k, 1, j / x)
//				(f[i][j] += f[i - k][j - k * x] * C(i - k) % mod) %= mod;
//			memset(f, 0ll, sizeof f), f[0][0] = 1ll;
//			rep(i, 1, n) for(int a : S) rep(j, x, n) 
//				(f[i][j] += f[i - 1][j - x]) %= mod;
//		} else{
		rep(i, 1, mxx) rep(j, 1, mxy) f[i][j] = 0ll; f[0][0] = 1ll;
		rep(i, 1, mxx) for(int a : S) rep(j, a, mxy) 
			f[i][j] += f[i - 1][j - a],
			(f[i][j] >= mod) and (f[i][j] -= mod);
//		}
		
		ll ans = 1ll;
		for(pii nw : getA){
			if(nw.fr > nw.se) ans = 0ll;
			else (ans *= f[nw.fr][nw.se]) %= mod;
			if(!ans) break;
		}
		if(!Flg) printf("%lld\n", ans);
		else printf("0\n");
	} 
	return 0;
}
