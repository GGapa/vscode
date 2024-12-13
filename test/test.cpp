#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
const int N=1010,M=2010;
int n,m,lim;
vector<int> anc[N];
ll dis[N][N],f[N][N][13];
int h[N],e[M],w[M],ne[M],idx;
inline void dfs(int u,int p,ll d)
{
	dis[p][u]=d;
	if(u!=p) anc[u].push_back(p);
	for(int i=h[u];~i;i=ne[i]) dfs(e[i],p,d+w[i]);
}
inline void add(int a,int b,int c)
{
	e[idx]=b;w[idx]=c;ne[idx]=h[a];h[a]=idx++;
}
inline void dp(int u)
{
	anc[u].push_back(0);
	for(int i=0;i<=lim;i++) for(auto v:anc[u]) f[u][v][i]=0;
	for(int i=h[u];~i;i=ne[i]) dp(e[i]);
	for(auto v:anc[u])
		for(int j=0;j<=lim;j++)
		{
			ll mx=0;
			for(int i=h[u];~i;i=ne[i]) 
			{
				ll cur=min(f[e[i]][v][j]+dis[v][u],j>0?f[e[i]][u][j-1]:inf);
				f[u][v][j]+=w[i]+cur;mx=max(mx,cur-f[e[i]][v][j]);	
			}
			f[u][v][j]-=mx;
		}
}
int main()
{
	memset(h,-1,sizeof h);
	// memset(f,0x3f,sizeof f);
	memset(dis,0x3f,sizeof dis);
	scanf("%d%d",&n,&m);
	for(int i=2;i<=n;i++)
	{
		int p,x;
		scanf("%d%d",&p,&x);
		add(p,i,x);
	}
	for(int i=1;i<=n;i++) dfs(i,i,0);
	lim=min(m,__lg(n)+1);dp(1);
	for(int i=1;i<=m;i++) printf("%lld\n",f[1][0][min(i,lim)]);
	return 0;
}