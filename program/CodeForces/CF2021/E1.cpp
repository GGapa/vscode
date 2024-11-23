#include<bitsdc++.h>
using namespace std;
#define ll long long
const int N=410;
bool mark[N];
ll f[N<<1][N<<1];
struct Edge{int u,v,w;}E[N];
int T,n,m,p,id,sz[N<<1],ls[N<<1],rs[N<<1],val[N<<1],fa[N<<1];
inline void chkmin(ll &x,ll y){x=min(x,y);}
inline void dp(int u)
{
	for(int i=-n;i<=n;i++) f[u][N+i]=1e15; 
	if(u<=n) sz[u]=1,f[u][N+1]=f[u][N-mark[u]]=0;
	else
	{
		dp(ls[u]);dp(rs[u]);
		sz[u]=sz[ls[u]]+sz[rs[u]];
		for(int i=-sz[ls[u]];i<=sz[ls[u]];i++)
			for(int j=-sz[rs[u]];j<=sz[rs[u]];j++)
			{
				if((i<=0&&j<=0)||(i>0&&j>0)) chkmin(f[u][N+i+j],f[ls[u]][N+i]+f[rs[u]][N+j]);
				else 
				{
					int x,y;
					if(i>0) x=i,y=-j;else x=j,y=-i;
					chkmin(f[u][N+x],f[ls[u]][N+i]+f[rs[u]][N+j]+1ll*val[u]*y);
				}
			}
	}
}


#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

struct Edge {
    int u, v, w;
};

const int N = 800;
vector<Edge> G[N], E; // 原本的图
vector<int> T[N * 2];    // 最大生成树重构树
int A[N * 2];            // 重构树节点的权重
int n, m;

namespace KruTree {
    int fa[M];
    int tot = 0;
    void init() {
        tot = 0;
        iota(fa, fa + 10 + n + m, 0);
    }
    int find(int x) {
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    int work()  {
        init();
        sort(E.begin(), E.end(), [&](const Edge &x, const Edge&y) {
            return x.a > y.a;
        });
        for(auto e : E) {
            int x = find(e.u), y = find(e.v);
            if(x == y) continue;
            int id = n + ++tot;
            T[id].emplace_back(x), T[id].emplace_back(y);
            A[id] = e.a;
            fa[x] = id, fa[y] = id;
            if(tot == n - 1) break;
        }
        rep(i, 0, n) A[i] = 1e9;
        return find(1); 
    };
};

int use[N];

void init() {
    const int INF = 1e9;
    vector<Edge>(0).swap(E);
    rep(i, 0, n) vector<Edge>(0).swap(G[i]);
    rep(i, 0, n + m + 10) vector<int>(0).swap(T[i]);
}

void solve() {
    int p; cin >> n >> m >> p;
	fill(use, use + 1 + n, 0);
    for(int i = 1, x; i <= q; i++)
        cin >> x, use[x] = 1;
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, E.push_back({u, v, w});
    int rt = KruTree::work();
	dp(id);
	for(int i=1;i<=n;i++) printf("%lld ",f[id][N+i]);puts("");
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    return 0;
}