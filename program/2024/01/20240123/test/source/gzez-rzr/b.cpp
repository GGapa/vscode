#include <bits/stdc++.h>
using namespace std;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(!isdigit(ch)) { if(ch == '-') f = -1; ch = getchar(); }
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}
const int N = 1.6e3 + 10, mod = 1e9 + 7;
int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
vector<int> e[N];
int f[810][810], dep[N];
int n1, n2, rt1, rt2;
void dfs1(int u, int fa) {
    dep[u] = dep[fa] + 1;
    for(auto v : e[u])
	    dfs1(v, u);
}
struct edge {
    int to, nxt;
} E[N];
int head[N], du[N], ecnt;
void addedge(int u, int v) {
//	cout << "Edge:"<<u << " " << v<< endl;
    E[++ecnt] = {v, head[u]};
    head[u] = ecnt;
    du[u]++;
}
void imp(int u, int fa) {
    if(e[u].size() == 1 && u != rt1 && u != rt2) {
	    imp(e[u][0], fa);
	    return;
	}
    if(fa) addedge(fa, u);
    for(auto v : e[u])
	    imp(v, u);
}
set<int> s;
int F(int x, int y) {
	if(!x) return !y;
	if(~f[x][y]) return f[x][y];
	f[x][y] = 0;
	for(auto i : s)
		if(y - i >= 0) f[x][y] = add(F(x - 1, y - i), f[x][y]);
	return f[x][y];
}
int dfs2(int u1, int u2) {
    if(du[u1] != du[u2]) return 0;
    int res = 1;
    for(int i = head[u1], j = head[u2]; i && j; i = E[i].nxt, j = E[j].nxt) {
	    int v1 = E[i].to, v2 = E[j].to;
	    int x = dfs2(v1, v2);
	    if(!x) return 0;
	    res = 1ll * res * x % mod * F(dep[v1] - dep[u1], dep[v2] - dep[u2]) % mod;
	    if(!res) return 0;
	}
    return res;
}
int main() {
//	if(system("fc b.out ex_b3.ans")); return 0;
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
    n1 = read(), n2 = read();
    for(int i = 2, fa; i <= n1; i++) {
	    fa = read();
	    e[fa].push_back(i);
	}
    rt1 = n1 + n2 + 1, rt2 = n1 + n2 + 2;
    for(int i = n1 + 2, fa; i <= n1 + n2; i++) {
	    fa = read() + n1;
	    e[fa].push_back(i);
	}
    e[rt1].push_back(1);
    e[rt2].push_back(n1 + 1);
    dfs1(rt1, 0); dfs1(rt2, 0);
    imp(rt1, 0), imp(rt2, 0);
    int q = read();
    f[0][0] = 1;
    int lim = max(n1, n2);
    while(q--) {
	    int op = read(), x = read();
	    if(op == 1) s.insert(x);
	    else s.erase(x);
	    memset(f, -1, sizeof(f));
	    f[0][0] = 1;
//	    for(int i = 1; i <= lim; i++)
//	    	for(auto x : s)
//	    		for(int j = x; j <= lim; j++)
//	    			f[i][j] = add(f[i - 1][j - x], f[i][j]);
//	    if(op == 1) {
//			for(int j = x; j <= lim; j++)
//		    	for(int i = 1; i <= lim; i++)
//				    f[i][j] = add(f[i][j], f[i - 1][j - x]);
//		}
//	    else {
//		    	for(int i = 1; i <= lim; i++)
//			for(int j = lim; j >= x; j--)
//				    f[i][j] = add(f[i][j], mod - f[i - 1][j - x]);
//		}
	    printf("%d\n", dfs2(rt1, rt2));
	}
    return 0;
}
