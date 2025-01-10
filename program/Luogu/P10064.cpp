#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int N = 3e3 + 5, mod = 998244353;

namespace pre {
    constexpr LL qpow(LL x, LL y){
        LL ret = 1;
        for(; y; y >>= 1) {
            if(y & 1) (ret = ret * x % mod);
            (x = x * x % mod) ;
        }
        return ret;
    }

    constexpr LL inv(LL x) {return qpow(x, mod - 2); }
}   
using namespace pre;


int n, m, rt, lef[N], siz[N];
LL pw2[N * N], pw[N][N], f[2][N], sum, C[N][N];
vector<int> G[N];

void dfs(int u,int ft){
	if(G[u].size() == 1) return siz[u] = lef[u] = 1,void();
	for(int v : G[u]) if(v != ft) dfs(v,u);
	memset(f,0,sizeof f);
	int t = 0,in = 0; siz[u] = f[0][0] = 1;
	for(int v : G[u]) if(v != ft){
		t ^= 1,memset(f[t],0,sizeof f[t]);
		for(int i = 0;i <= lef[u];++i)	
			for(int j = 0,x = 1;j <= lef[v];++j,x = mod - x)
				(f[t][i + j] += f[t ^ 1][i] * x % mod * C[lef[v]][j] % mod * pw2[(siz[u] - i) * (siz[v] - j)] % mod) %= mod;
		siz[u] += siz[v],lef[u] += lef[v],in += siz[v] * (siz[v] - 1) / 2;
	}
	int os = n - siz[u],ol = m - lef[u];
	in += os * (os - 1) / 2;
	for(int i = 0;i <= lef[u];++i)
		(sum += f[t][i] * pw2[in] % mod * pw2[(os - ol) * (siz[u] - i)] % mod * pw[siz[u] - i][ol] % mod) %= mod;
	if(ft){
		in = siz[u] * (siz[u] - 1) / 2 + os * (os - 1) / 2;
		for(int i = 0,x = mod - 1;i <= lef[u];++i,x = mod - x)
			(sum += C[lef[u]][i] * x % mod * pw2[in] % mod * pw2[(os - ol) * (siz[u] - i)] % mod * pw[siz[u] - i][ol] % mod) %= mod;
	}
}


signed main() {
    // binom::init();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
	pw2[0] = C[0][0] = 1;
	rep(i, 1, n * n) pw2[i] = pw2[i - 1] * 2 % mod;
	rep(i, 1, n) {
		pw[i][0] = C[i][0] = 1;
		rep(j, 1, n) C[i][j] = j ? (C[i - 1][j] + C[i - 1][j - 1]) % mod : 1,
			pw[i][j] = pw[i][j - 1] * (pw2[i] - 1) % mod;
	}
	rep(i, 1, n) G[i].size() == 1 ? ++m : (rt = i);
	dfs(rt, 0);
	cout << sum << '\n';
    return 0;
}
