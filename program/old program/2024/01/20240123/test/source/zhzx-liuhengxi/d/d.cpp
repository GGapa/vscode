// created:  Jan/23/2024 12:37:42
#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=905,MOD=998244353;
void reduce(int &x){(x>=MOD)&&(x-=MOD);}
int qpow(long long a,int b)
{
	long long c=1;
	for(;b;b>>=1,(a*=a)%=MOD)if(b&1)(c*=a)%=MOD;
	return (int)c;
}
struct result
{
	int a0,a1;
	friend result operator+(const result &u,const result &v)
	{
		result w={u.a0+v.a0,u.a1+v.a1};
		reduce(w.a0);reduce(w.a1);
		return w;
	}
	friend result operator*(const result &u,const result &v)
	{
		return {(int)(((long long)u.a0*v.a0)%MOD),(int)(((long long)u.a0*v.a1+(long long)u.a1*v.a0)%MOD)};
	}
	friend result operator*(const result &u,int v)
	{
		return {u.a0,(int)((u.a1+(long long)u.a0*v)%MOD)};
	}
}f[N][2];
int n,m,k,p,t,a[N];
vector<pair<int,int>> adj[N];
void dfs(int u,int fa)
{
	f[u][0]={1,0};
	f[u][1]={1,a[u]};
	for(pair<int,int> vw:adj[u])
	{
		int v=vw.first,w=vw.second;if(v==fa)continue;
		dfs(v,u);
		f[u][0]=f[u][0]*f[v][0]*w+f[u][0]*f[v][1];
		f[u][1]=f[u][1]*f[v][0];
	}
}
int main()
{
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
#endif
	read(n,m,k,p,t);
	t=(int)((long long)p*t*qpow(n+m,MOD-2)%MOD);
	F(i,0,n)reduce(read(a[i])+=t);
	F(i,0,m)
	{
		int u,v,w;read(u,v,w);--u,--v;reduce(w+=t);
		adj[u].emplace_back(v,w);
		adj[v].emplace_back(u,w);
	}
	dfs(0,0);
	result ans=f[0][0]+f[0][1];
	printf("%d\n",ans.a1);
	return 0;
}
