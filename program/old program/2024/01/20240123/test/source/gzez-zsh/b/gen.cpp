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

int up[N][N],dn[N][N],dep[N],s1[N],s2[N];
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
	if (s1[u]<s2[v]) return 0;
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

	int n1=300,n2=800,q=100;
	printf("%d %d\n",n1,n2);
	rep(i,2,n1) printf("%d ",i-1); printf("\n");
	rep(i,2,n2) printf("%d ",i-1); printf("\n");

	printf("%d\n",q);
	rep(i,1,q) printf("%d %d\n",1,i);

	return 0;
}
