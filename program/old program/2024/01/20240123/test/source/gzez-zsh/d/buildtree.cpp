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

void print(int x)
{
	for (auto it:E[x]) printf("%d -> %d\n",x,it);
	for (auto it:E[x]) print(it);
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
	print(1);

	

	return 0;
}
