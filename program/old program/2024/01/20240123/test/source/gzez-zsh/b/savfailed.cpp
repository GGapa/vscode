#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define drep(i,a,b) for (int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;
inline void setfile()
{
	#ifndef pbtxdy
	freopen("norm.in","r",stdin);
	freopen("norm.out","w",stdout);
	#endif
}

const int mod=1e9+7;
inline int qmo(int x){return x+((x>>31)&mod);}
inline int add(int x,int y){return qmo(x+y-mod);}
inline int sub(int x,int y){return qmo(x-y);}
inline void inc(int &x,int y){x=add(x,y);}
inline void dec(int &x,int y){x=sub(x,y);}

const int N=810;

int n1,n2;
vector<int> G1[N],G2[N],V;

int up[N][N],dn[N][N],dep[N];
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1,up[u][0]=dn[u][0]=u;
	rep(i,1,dep[u]-1) up[u][i]=up[fa][i-1];
	rep(i,1,dep[u]-1)
	{
		int v=up[u][i];
		if (G2[v].size()!=1) break;
		dn[v][i]=u;
	}
	for (auto v:G2[u]) dfs(v,u);
}

int f[N][N];
int mat(int u,int v)
{
	if (f[u][v]>=0) return f[u][v];
	int ans=0;
	for (auto len:V) if (dn[v][len-1])
	{
		int w=dn[v][len-1];
		if (G1[u].size()!=G2[w].size()) continue;
		int xns=1;
		rep(i,0,(int)G1[u].size()-1)
		{
			xns=1ll*xns*mat(G1[u][i],G2[w][i])%mod;
		}
		inc(ans,xns);
	}
	return f[u][v]=ans;
}

int main()
{
	setfile();
	ios::sync_with_stdio(false); cin.tie(0);

	cin>>n1>>n2;
	rep(i,2,n1)
	{
		int fa; cin>>fa;
		G1[fa].push_back(i);
	}
	rep(i,2,n2)
	{
		int fa; cin>>fa;
		G2[fa].push_back(i);
	}
	dfs(1,0);

	int q; cin>>q;
	rep(wtf,1,q)
	{
		int op,x; cin>>op>>x;
		if (op==1)
		{
			drep(v,n2,1) if (dn[v][x-1])
			{
				int w=dn[v][x-1];
				drep(u,n1,1) if (G1[u].size()==G2[w].size())
				{
					printf("x %d u %d v %d\n",x,u,v);
					int xns=1;
					rep(i,0,(int)G1[u].size()-1)
					{
						xns=1ll*xns*f[G1[u][i]][G2[w][i]]%mod;
					}
					inc(f[u][v],xns);
				}
			}
		}
		else
		{
			rep(v,1,n2) if (dn[v][x-1])
			{
				int w=dn[v][x-1];
				rep(u,1,n1) if (G1[u].size()==G2[w].size())
				{
					int xns=1;
					rep(i,0,(int)G1[u].size()-1)
					{
						xns=1ll*xns*f[G1[u][i]][G2[w][i]]%mod;
					}
					dec(f[u][v],xns);
				}
			}	
		}
		rep(i,1,n1) rep(j,1,n2) printf("mat %d %d = %d\n",i,j,f[i][j]); 
		printf("%d\n",f[1][1]);
	}

	return 0;
}
