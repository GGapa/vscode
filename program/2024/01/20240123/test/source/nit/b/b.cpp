#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int N=805;
int dfn[N];
inline bool cmp(int x,int y){return dfn[x]<dfn[y];}
struct Tree{
	int n;
	vector<int>G[N],g[N];
	int dfc,f[N],d[N];
	int b[N<<1],tot,a[N<<1],D;
	inline void add(int u,int v){G[u].push_back(v);}
	void dfs1(int x,int fa){
		d[x]=d[f[x]=fa]+1,dfn[x]=++dfc;
		if(G[x].size()!=1) b[++tot]=x;
		for(auto v:G[x]) dfs1(v,x);
	}
	inline int lca(int u,int v){
		if(d[u]<d[v]) swap(u,v);
		while(d[u]!=d[v]) u=f[u];
		while(u!=v) u=f[u],v=f[v];
		return u;
	}
	inline int init(){
		dfs1(1,0),a[++D]=b[tot];
		for(int i=1;i<tot;++i)
			a[++D]=b[i],a[++D]=lca(b[i],b[i+1]);
		sort(a+1,a+D+1,cmp);
		D=unique(a+1,a+D+1)-a-1;
		for(int i=1;i<D;++i)
			g[lca(a[i],a[i+1])].push_back(a[i+1]);
		for(int i=1;i<=n;++i)
			if(g[i].size()) sort(g[i].begin(),g[i].end(),cmp);
		return a[1];
	}
}T1,T2;
int fl=1;
int cnt[N],sum[N],tot,Mx,Mx2;
void dfs(int x1,int x2){
	if(T1.g[x1].size()!=T2.g[x2].size()) return fl=0,void();
	int sz=T1.g[x1].size();
	for(int i=0;i<sz;++i)
		cnt[++tot]=T1.d[T1.g[x1][i]]-T1.d[x1],
		sum[tot]=T2.d[T2.g[x2][i]]-T2.d[x2],
		dfs(T1.g[x1][i],T2.g[x2][i]);
}
int n1,n2,q,vis[N];
const int mod=1e9+7;
vector<int>S;
#define ll long long
ll f[N][N];
inline int ask(){
	if(!fl) return 0;
	ll ans=1;
	S.clear();
	for(int i=1;i<=800;++i)
		if(vis[i]) S.emplace_back(i);
	memset(f,0,sizeof f);
	f[0][0]=1;
	for(int i=0;i<=Mx2;++i)
		for(int j=0;j<=Mx;++j){
			f[i][j]%=mod;
			if(!f[i][j]||i==Mx2||j==Mx) continue;
			for(auto v:S)
				if(j+v<=Mx) f[i+1][j+v]+=f[i][j];
				else break;
		}
	for(int i=1;i<=tot;++i)
		ans=ans*f[cnt[i]][sum[i]]%mod;
	return ans;
}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n1>>n2,T1.n=n1,T2.n=n2;
	for(int i=2,u;i<=n1;++i)
		cin>>u,T1.add(u,i);
	for(int i=2,u;i<=n2;++i)
		cin>>u,T2.add(u,i);
	int rt1=T1.init(),rt2=T2.init();
	cnt[++tot]=T1.d[rt1],sum[tot]=T2.d[rt2];
	dfs(rt1,rt2);
	for(int i=1;i<=tot;++i) Mx=max(Mx,sum[i]),Mx2=max(Mx2,cnt[i]);
	cin>>q;
	int opt,x;
	while(q--)
		cin>>opt>>x,vis[x]^=1,
		cout<<ask()<<"\n";
}