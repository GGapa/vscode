#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define drep(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
inline void setfile()
{
	#ifndef pbtxdy
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	#endif
}

const int mod=998244353;
inline int qmo(int x){return x+((x>>31)&mod);}
inline int add(int x,int y){return qmo(x+y-mod);}
inline int sub(int x,int y){return qmo(x-y);}
inline void inc(int &x,int y){x=add(x,y);}
inline void dec(int &x,int y){x=sub(x,y);}
inline int quick_pow(int x,int k){int res=1; for (;k;k>>=1,x=1ll*x*x%mod) if (k&1) res=1ll*res*x%mod; return res;}

const int N=1810,M=33;

int n,m,K,P,V,mp[N][N],a[N];
vector<int> G[N];

int idx,low[N],dfn[N],pcnt;
vector<int> stk,E[N];
void tarjan(int u)
{
	low[u]=dfn[u]=++idx; stk.push_back(u);
	for (auto v:G[u])
	{
		if (!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
			if (low[v]>=dfn[u])
			{
				int x=-1;
				pcnt++;
				E[u].push_back(pcnt);
				while (x!=v)
				{
					x=stk.back();
					stk.pop_back();
					E[pcnt].push_back(x);
				}
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
}

int C[M][M];
void init()
{
	C[0][0]=1;
	rep(i,1,K) 
	{
		C[i][0]=1;
		rep(j,1,i) C[i][j]=add(C[i-1][j],C[i-1][j-1]);
	}
}

struct info
{
	int s,a[M][M];
	info () {memset(a,0,sizeof(a));}
};
inline info operator + (info x,const info &y)
{
	x.s=max(x.s,y.s);
	rep(i,0,x.s) rep(j,0,K) inc(x.a[i][j],y.a[i][j]);
	return x;
}
inline info operator * (const info &x,const info &y)
{
	info z;
	z.s=min(x.s+y.s,P);
	rep(i,0,x.s) rep(s,0,K) if (x.a[i][s])
	{
		const int &v=x.a[i][s];
		rep(j,0,min(P-i,y.s)) rep(t,0,K-s) if (y.a[j][t])
		{
			inc(z.a[i+j][s+t],1ll*v*y.a[j][t]%mod*C[s+t][t]%mod);
		}
	}
	return z;
}
inline info up(const info &x,int c)
{
	info y;
	y.s=min(P,x.s+c);
	rep(i,0,P-c) rep(j,0,K) y.a[i+c][j]=x.a[i][j];
	return y;
}
inline info gen(int w)
{
	info x;
	x.s=0;
	x.a[0][0]=1;
	rep(i,1,K) x.a[0][i]=1ll*x.a[0][i-1]*w%mod;
	return x;
}

info f[N][2],g[N][2][2];
void dfs(int u)
{
	for (auto x:E[u]) dfs(x);
	if (u<=n)
	{
		f[u][0].s=f[u][1].s=1;
		f[u][0].a[0][0]=f[u][0].a[1][0]=1;
		rep(c,0,1)
		{
			int nw=add(a[u],c*V);
			f[u][1].a[c][0]=1;
			rep(i,1,K) f[u][1].a[c][i]=1ll*f[u][1].a[c][i-1]*nw%mod;
		}

		for (auto v:E[u])
		{
			info nf0,nf1;
			if (E[v].size()==1)
			{
				int W=mp[u][E[v][0]];
				rep(c,0,1)
				{
					static info ng[2];
					rep(i,0,1) ng[i]=up(g[v][i][i],c);
					nf0=nf0+ng[0]*gen(add(W,c*V));
					nf0=nf0+ng[1];
					nf1=nf1+ng[0];
				}
			}
			else
			{
				rep(cl,0,1) rep(cr,0,1)
				{
					static info ng[2][2];
					rep(i,0,1) rep(j,0,1) ng[i][j]=up(g[v][i][j],cl+cr);
					int wl=add(mp[u][E[v][0]],cl*V);
					int wr=add(mp[u][E[v].back()],cr*V);
					nf0=nf0+(ng[0][0]*gen(wl)*gen(wr));
					nf0=nf0+(ng[0][1]*gen(wl));
					nf0=nf0+(ng[1][0]*gen(wr));
					nf0=nf0+ng[1][1];
					nf1=nf1+ng[0][0];
				}
			}
			f[u][0]=f[u][0]*nf0;
			f[u][1]=f[u][1]*nf1;
		}
	}
	else
	{
		info h[2][2];
		h[0][0]=f[E[u][0]][0];
		h[1][1]=f[E[u][0]][1];
		rep(i,1,(int)E[u].size()-1)
		{
			int v=E[u][i];
			rep(fi,0,1)
			{
				info nh0,nh1;
				rep(c,0,1)
				{
					static info nf[2];
					rep(j,0,1) nf[j]=up(f[v][j],c);
					int nw=add(mp[E[u][i]][E[u][i-1]],c*V);
					nh0=nh0+(h[fi][0]*nf[0]*gen(nw));
					nh0=nh0+(h[fi][1]*nf[0]);
					nh1=nh1+(h[fi][0]*nf[1]);
				}
				h[fi][0]=nh0;
				h[fi][1]=nh1;
			}
		}
		rep(i,0,1) rep(j,0,1) g[u][i][j]=h[i][j];
	}
}

int main()
{
	setfile();
	ios::sync_with_stdio(false); cin.tie(0);

	cin>>n>>m>>K>>P>>V;
	rep(i,1,n) cin>>a[i];
	rep(i,1,m)
	{
		int u,v,w; cin>>u>>v>>w;
		G[u].push_back(v);
		G[v].push_back(u);
		mp[u][v]=mp[v][u]=w;
	}
	pcnt=n;
	tarjan(1);

	init();
	dfs(1);

	int ans=0;
	rep(i,0,1)  inc(ans,f[1][i].a[P][K]);

	int c=1;
	rep(i,1,P) c=1ll*c*(n+m-i+1)%mod*quick_pow(i,mod-2)%mod;
	ans=1ll*ans*quick_pow(c,mod-2)%mod;
	printf("%d\n",ans);

	return 0;
}